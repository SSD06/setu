#include "xunh.h"
#include<QLineEdit>
#include <QWidget>
#include <QFile>
#include <QMessageBox>
xunh::xunh(huoqu *t,MainWindow *k)
{
    this->t1 = t;
    this->k1 = k;
}
void xunh::run()
{
    while (true)
    {
        tag="&tag="+k1->ui->lineEdit->text();
        if (t1->isFinished()==true&&isz==0)
        {
            t1->start();
        }
    }
}
