#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_setuapi.h"
#include"huoqu.h"
#include<QLineEdit>
#include <QtWidgets>
#include <QCompleter>
#include <QStringList>
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
#include<qvector.h>
class setuapi : public QMainWindow
{
    Q_OBJECT

public:
    setuapi(QWidget *parent = Q_NULLPTR);
	
private:
	Ui::setuapiClass ui;
	QVector<QSharedPointer<huoqu>> Threads;
	void LoadImage();
	QQueue<QString> Filenames;
	bool checkPermission();
	void Dirmik();
	QTimer *timer;
	QMutex Mutex_filename;


signals:

};
