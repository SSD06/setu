#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include<QDir>
#include<QJsonDocument>
#include<QJsonArray>
#include<QJsonObject>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setScaledContents(true);
    Mkdir();
    connect(&GetUrlThread::GlobalInstance(),&GetUrlThread::Enqueue,[](){
        DownloadThreadPool::GlobalInstance().waitcondition.wakeOne();
    });

    connect(&GetUrlThread::GlobalInstance(),&GetUrlThread::Queuenum,[&](const uint &num){
        ui->label_3->setText(QString("下载队列数量：%1").arg(num));
    });
    timer.reset(new QTimer(this));
    connect(timer.get(),&QTimer::timeout,[&](){
        if(!DownloadThreadPool::GlobalInstance().getQueue_filename().isEmpty())
        {
           auto filename=DownloadThreadPool::GlobalInstance().getQueue_filename().dequeue();
           //qDebug()<<"mmmmmmmm"<<filename;
           QPixmap pixmap(filename);
           pixmap = pixmap.scaled(ui->label->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
           ui->label->setPixmap(pixmap);
        }
        //qDebug()<<DownloadThreadPool::GlobalInstance().getQueue_filename();
    });
    if(QFile::exists("./待下载清单.txt")&&GetUrlThread::GlobalInstance().getUrlfileinfoqueue().isEmpty())
    {
        QFile file("./待下载清单.txt");
        if(file.open(QIODevice::ReadOnly|QIODevice::Text))
        {
            auto array=QJsonDocument::fromJson(file.readAll()).array();
            for(auto a:array)
            {
                auto fileinfo=GetUrlThread::UrlFileInfo(a.toObject().value("fileurl").toString(),a.toObject().value("filename").toString());
                GetUrlThread::GlobalInstance().EnqueueUrlfileinfo(fileinfo);
            }
        }
    }
    //    GetUrlThread::GlobalInstance().setNum(20);
    //    GetUrlThread::GlobalInstance().setR18(GetUrlThread::R18_ON);
    //    GetUrlThread::GlobalInstance().start();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    Mkdir();
    if(ui->pushButton->text()=="随机色图")
    {
        if(QFile::exists("./待下载清单.txt")&&GetUrlThread::GlobalInstance().getUrlfileinfoqueue().isEmpty())
        {
            QFile file("./待下载清单.txt");
            if(file.open(QIODevice::ReadOnly|QIODevice::Text))
            {
                auto array=QJsonDocument::fromJson(file.readAll()).array();
                for(auto a:array)
                {
                    auto fileinfo=GetUrlThread::UrlFileInfo(a.toObject().value("fileurl").toString(),a.toObject().value("filename").toString());
                    GetUrlThread::GlobalInstance().EnqueueUrlfileinfo(fileinfo);
                }
            }
        }
        ui->pushButton->setText("停止获取");
        GetUrlThread::GlobalInstance().setNum(20);
        if (ui->radioButton->isChecked())
        {
            GetUrlThread::GlobalInstance().setR18(GetUrlThread::R18_OFF);
        }
        else if (ui->radioButton_2->isChecked())
        {
            GetUrlThread::GlobalInstance().setR18(GetUrlThread::R18_ON);
        }
        else if (ui->radioButton_3->isChecked())
        {
            GetUrlThread::GlobalInstance().setR18(GetUrlThread::R18_ALL);
        }

        GetUrlThread::GlobalInstance().setTag(ui->lineEdit->text());
        GetUrlThread::GlobalInstance().setStop(false);
        GetUrlThread::GlobalInstance().start();
        //DownloadThreadPool::GlobalInstance().setThreadNum(QThread::idealThreadCount());
        DownloadThreadPool::GlobalInstance().setThreadNum(ui->spinBox->value());
        DownloadThreadPool::GlobalInstance().start();
        timer->start(1000);
    }
    else
    {
        ui->pushButton->setText("随机色图");
        GetUrlThread::GlobalInstance().setStop(true);
        GetUrlThread::GlobalInstance().quit();
        DownloadThreadPool::GlobalInstance().stop();
        QFile file("./待下载清单.txt");
        if(file.open(QIODevice::WriteOnly|QIODevice::Text))
        {
            QJsonArray array;

            for(auto &a:GetUrlThread::GlobalInstance().getUrlfileinfoqueue())
            {
                QJsonObject object;
                object.insert("fileurl",a.Url);
                object.insert("filename",a.Filename);
                array.append(object);
            }
            GetUrlThread::GlobalInstance().getUrlfileinfoqueue().clear();
            file.write(QJsonDocument(array).toJson());
            file.close();
        }
        timer->stop();
        DownloadThreadPool::GlobalInstance().getQueue_filename().clear();
    }
}

void MainWindow::Mkdir()
{
    QDir dir("./");
    if(!dir.exists("色图"))
    {
        dir.mkdir("色图");
    }
}
