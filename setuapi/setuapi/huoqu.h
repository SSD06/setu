#pragma once
#include <qthread.h>
#include <QtWidgets/QApplication>
#include <QtNetwork/QtNetwork>
#include <QPainter>
#include <QRect>
#include <QBrush>
#include <QFont>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include<QJsonArray>
#include<QJsonDocument>
#include<QJsonObject>
#include <QScriptEngine>
#include <QScriptValue>
#include <QScriptValueIterator>
#include<qmovie.h>
#include<QButtonGroup>
#include<QThread>
class huoqu :public QThread
{
	Q_OBJECT
public:
	huoqu();

	QString getTag() const;
	void setTag(const QString &value);

	int getIsR18() const;
	void setIsR18(int value);

	int getThreadnum() const;
	void setThreadnum(int value);

	bool getStop() const;
	void setStop(bool value);

protected:
	void run() Q_DECL_OVERRIDE;
private:
	QString apiurl = "https://api.lolicon.app/setu/v2/?";
	QString tag;
	int isR18;
	int threadnum;
	bool stop = false;


signals:
	void jieshu(QString filename);
};

