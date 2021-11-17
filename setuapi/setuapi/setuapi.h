#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_setuapi.h"
#include<QLineEdit>
#include <QtWidgets>
#include <QCompleter>
#include <QStringList>
class setuapi : public QMainWindow
{
    Q_OBJECT

public:
    setuapi(QWidget *parent = Q_NULLPTR);
	Ui::setuapiClass ui;
private:
	
signals:
	void wan();
	void chongx();
};
