#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets/QApplication>
#include <QtNetwork/QtNetwork>
#include<QtAndroidExtras/QtAndroid>
#include <QtAndroid>
#include<QMessageBox>
#include<QLineEdit>
#include <QWidget>
#include <QFile>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    checkPermission();
    Dirmik();
    timer=new QTimer();
    connect(timer,&QTimer::timeout,this,&MainWindow::LoadImage);



    connect(ui->pushButton, &QPushButton::clicked, [=]() {
        if(ui->pushButton->text()=="随机色图")
        {
            ui->pushButton->setText("停止获取");
            auto num=ui->spinBox->value();
            auto tag=ui->lineEdit->text();
            int isR18=0;
            if(ui->radioButton->isChecked())
            {
                isR18=0;
            }
            else if(ui->radioButton_2->isChecked())
            {
                isR18=1;
            }
            else if(ui->radioButton_3->isChecked())
            {
                isR18=2;
            }
            for (int i=0;i<num;i++)
            {
                QSharedPointer<huoqu> thread(new huoqu);
                thread->setIsR18(isR18);
                thread->setTag(tag);
                thread->setThreadnum(i+1);
                connect(thread.get(),&huoqu::jieshu,this,[=](QString filename){
                    QMutexLocker lock(&Mutex_filename);
                    Filenames.enqueue(filename);
                });
                Threads.push_back(thread);
            }
            foreach(auto &thread,Threads)
            {
                thread->start();
            }
            timer->start(1000);
        }
        else if(ui->pushButton->text()=="停止获取")
        {

            foreach(auto &thread,Threads)
            {
                thread->setStop(true);
                thread->quit();

            }
            while(true)
            {
                auto stopnum=false;
                foreach(auto &thread,Threads)
                {
                    stopnum=stopnum||thread->isRunning();
                }
                if(stopnum==false)
                {
                    break;
                }
            }
            Threads.clear();
            timer->stop();
            Filenames.clear();
            ui->pushButton->setText("随机色图");
        }
    });


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::LoadImage()
{

    QMutexLocker lock(&Mutex_filename);

    if(!Filenames.isEmpty())
    {
        QString filename;
        filename=Filenames.dequeue();

        QImage Image;
        if(Image.load(filename))
        {

            QPixmap pixmap = QPixmap::fromImage(Image);

            int with = ui->label->width();
            int height = ui->label->height();

            QPixmap fitpixmap = pixmap.scaled(with, height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

            ui->label->setPixmap(fitpixmap);

            ui->label->setScaledContents(true);
        }
    }
}

bool MainWindow::checkPermission()
{
    QtAndroid::PermissionResult r = QtAndroid::checkPermission("android.permission.WRITE_EXTERNAL_STORAGE");
    if(r == QtAndroid::PermissionResult::Denied) {
        QtAndroid::requestPermissionsSync( QStringList() << "android.permission.WRITE_EXTERNAL_STORAGE" );
        r = QtAndroid::checkPermission("android.permission.WRITE_EXTERNAL_STORAGE");
        if(r == QtAndroid::PermissionResult::Denied) {
            return false;
        }
    }
    return true;
}

void MainWindow::Dirmik()
{
    QDir *folder = new QDir;
    bool exist = folder->exists("/storage/emulated/0/色图");
    if(exist)
    {
        //QMessageBox::warning(this, tr("createDir"), tr("Dir is already existed!"));
    }
    else
    {
        //创建文件夹
        bool ok = folder->mkdir("/storage/emulated/0/色图");
        if(ok)
        {
            //QMessageBox::warning(this, tr("CreateDir"), tr("Create Dir success!"));
        }
        else
            QMessageBox::warning(this, tr("CreateDir"), tr("Create Dir fail"));
    }
}

