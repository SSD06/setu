#ifndef XUNH_H
#define XUNH_H
#include<QThread>
#include"huoqu.h"
#include"quanju.h"
#include"mainwindow.h"
#include<QLineEdit>
#include "ui_mainwindow.h"
class xunh :
    public QThread
{
    Q_OBJECT
public:
    huoqu *t1;
    MainWindow *k1;
    xunh(huoqu *t,MainWindow *k);
protected:
    void run() Q_DECL_OVERRIDE;
private:


signals:
};
#endif // XUNH_H
