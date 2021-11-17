#include "widget1.h"
#include <QtWidgets/QApplication>
#include <QtNetwork/QtNetwork>
#include <QPainter>
#include <QRect>
#include <QBrush>
#include <QFont>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QScriptEngine>
#include <QScriptValue>
#include <QScriptValueIterator>
#include<qmovie.h>
#include<QButtonGroup>
#include<QThread>
#include <qthread.h>
widget1::widget1(QWidget* parent)
	: QWidget(parent)	//构造函数初始化列表QWidget
{
	//其他组件需在setupUi函数调用后生成，否则会被UI覆盖导致无法点击
	
	ui.setupUi(this);
	
}
