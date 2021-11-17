#pragma execution_character_set("utf-8")
#include "xunh.h"
#include<qdebug.h>
#include <QWidget>
#include <QFile>
#include <QMessageBox>
#include <QtDebug>
#include <QVector>
xunh::xunh(huoqu *t, setuapi *k)
{
	this->t1 = t;
	this->k1 = k;
}
void xunh::run()
{
	while (true)
	{
		tag = "&tag=" + k1->ui.lineEdit->text();
		if (t1->isFinished()==true&&isz==0)
		{
			
			t1->start();
			qDebug() << "线程重启成功";
		}
	}
}