#pragma once
#include <qwidget.h>
#include <QtWidgets/QMainWindow>	
#include"ui_Widget1.h"
class widget1 :
	public QWidget
{
	Q_OBJECT	//必要的宏

public:
	widget1(QWidget* parent = Q_NULLPTR);	//构造器
	Ui::Widget1class ui;
private:
	//ui类名即是窗体类名，在自动生成的"ui_XXX.h"头文件中已定义
};

