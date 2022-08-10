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
#include<qmovie.h>
#include<QButtonGroup>
#include<QThread>
class huoqu :public QThread
{
	Q_OBJECT
public:
	huoqu();
	~huoqu();

	QString getTag() const;
	void setTag(const QString &value);

	int getIsR18() const;
	void setIsR18(int value);

	int getThreadnum() const;
	void setThreadnum(int value);

	bool getStop() const;
	void setStop(bool value);

	void seturl();

protected:
	void run() Q_DECL_OVERRIDE;
private:
	QString apiurl = "https://api.lolicon.app/setu/v2/?";
	QString tag;
	int isR18;
	int threadnum;
	bool stop = false;
	//QSharedPointer<QNetworkAccessManager> m_pHttpMgr;
	//QSharedPointer<QNetworkReply> reply;
	//QSharedPointer<QNetworkAccessManager> m_pHttpMgr1;
	//QSharedPointer<QNetworkReply> reply1;
	QSharedPointer<QPixmap>currentPicture;
	QString url;
	//QEventLoop eventLoop;
	//QEventLoop eventLoop1;

	//QSharedPointer<QEventLoop> eventLoop;
	//QSharedPointer<QEventLoop> eventLoop1;
	QString s1;
	QByteArray responseByte;
	//QNetworkRequest requestInfo;
	//QNetworkRequest requestInfo1;
	QString  curPath;
	QString sub = "色图";
	QString filename;

signals:
	void jieshu(QString filename);
};

