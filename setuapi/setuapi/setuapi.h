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
	~setuapi();
private:
	Ui::setuapiClass ui;
	QVector<QSharedPointer<huoqu>> Threads;
	void LoadImage();
	QQueue<QString> Filenames;
	bool checkPermission();
	void Dirmik();
	QTimer *timer;
	QMutex Mutex_filename;
	void Queuefilename(QString filename);


signals:

};
