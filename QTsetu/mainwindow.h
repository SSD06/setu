#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<GetUrlThread.h>
#include<DownloadThread.h>
#include<QQueue>
#include<QTimer>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    QSharedPointer<QTimer> timer;
    void Mkdir();
    //QQueue<QString> queue_filename;
};
#endif // MAINWINDOW_H
