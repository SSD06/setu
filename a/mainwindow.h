#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "ui_mainwindow.h"
#include "huoqu.h"
#include <QMainWindow>
#include<QLineEdit>
#include <QCompleter>
#include <QStringList>
#include <QWidget>
#include <QFile>
#include <QMessageBox>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QVector<QSharedPointer<huoqu>> Threads;
    void LoadImage();
    QQueue<QString> Filenames;
    bool checkPermission();
    void Dirmik();
    QTimer *timer;
    QMutex Mutex_filename;
};
#endif // MAINWINDOW_H
