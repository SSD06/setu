#ifndef HUOQU_H
#define HUOQU_H
#include<QThread>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets/QApplication>
#include <QtNetwork/QtNetwork>
#include<QtAndroidExtras/QtAndroid>
#include <QtAndroid>
#include<QMessageBox>
#include"quanju.h"
class huoqu : public QThread
{
    Q_OBJECT
public:
    QString url1 = "https://api.lolicon.app/setu/v2/?";
    QString key1 = "23327833606bf37cbb86f3";
    QString key2 = "08248891606b09299f3560";
    QString key = key1;
    QString url = url1+tag;
    huoqu();
protected:
    void run() Q_DECL_OVERRIDE;
private:


signals:
    void jieshu();
    void hais();
};

#endif // HUOQU_H
