#pragma execution_character_set("utf-8")
#include "huoqu.h"
#include"quanju.h"
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
#include <QJsonDocument>
#include <QJsonParseError>
#include <QScriptEngine>
#include <QScriptValue>
#include <QScriptValueIterator>
#include<qmovie.h>
#include<QButtonGroup>
#include<QThread>
#include <qthread.h>
QString huoqu::huo(QString url)
{
	return url;
}
void huoqu::run()
{
	if (isr18 == 0)
	{
		url = url1 + tag;
	}
	else
	{
		if (isr18 == 1)
		{
			url = url1 + tag + "&r18=1";
		}
		else
		{
			if (isr18 == 2)
			{
				url = url1 + tag + "&r18=2";
			}
		}
	}
	QString  curPath = QDir::currentPath();
	QDir dir(curPath);
	QString sub = "色图";
	dir.mkdir(sub);
	QNetworkAccessManager *m_pHttpMgr = new QNetworkAccessManager();
	//设置url
	qDebug() << url;
	//QString url = "https://i.pixiv.cat/img-original/img/2020/09/06/23/55/59/84206039_p0.jpg";
	QNetworkRequest requestInfo;
	requestInfo.setUrl(QUrl(url));

	//添加事件循环机制，返回后再运行后面的
	QEventLoop eventLoop;
	QNetworkReply *reply = m_pHttpMgr->get(requestInfo);
	connect(reply, SIGNAL(finished()), &eventLoop, SLOT(quit()));
	eventLoop.exec();       //block until finish
	//错误处理
	if (reply->error() == QNetworkReply::NoError)
	{
		qDebug() << "request protobufHttp NoError";
	}
	else
	{
		/*key = key2;
		url = url1 + key;*/
		qDebug() << "request protobufHttp handle errors here";
		QVariant statusCodeV = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
		//statusCodeV是HTTP服务器的相应码，reply->error()是Qt定义的错误码，可以参考QT的文档
		qDebug("request protobufHttp found error ....code: %d %d\n", statusCodeV.toInt(), (int)reply->error());
		qDebug(qPrintable(reply->errorString()));
	}
	//请求返回的结果
	QByteArray responseByte = reply->readAll();
	qDebug() << responseByte;
	QString sr = responseByte;
	qDebug() << sr;
	QJsonObject json;
	json = QJsonDocument::fromJson(responseByte).object();
	qDebug() << json;
	qDebug() << json.value("data");
	QJsonArray json1 = json.value("data").toArray();

	qDebug() << json1;

	//for (int i = 0; i < json1.size(); i++)
	//{
	//	QJsonValue iconArray = json1.at(i);
	//	QJsonObject icon = iconArray.toObject();
	//	QString id = icon["id"].toString();
	//	QString iconTxt = icon["iconTxt"].toString();
	//	QString iconName = icon["iconName"].toString();
	//	qDebug() << "id=" << id << "iconTxt=" << iconTxt << "iconName=" << iconName;
	//}
	QJsonValue val1 = json1.at(0);
	QJsonObject json3 = val1.toObject();
	qDebug() << json3;
	qDebug() << json3.value("urls");

	QJsonObject url4 = json3.value("urls").toObject();
	qDebug() << url4;
	QString s1 = url4.value("original").toString();
	qDebug() << s1;







	QNetworkAccessManager *m_pHttpMgr1 = new QNetworkAccessManager();
	//设置url
	//QString url1 = "https://api.lolicon.app/setu/?apikey=23327833606bf37cbb86f3";
	//QString url = "https://i.pixiv.cat/img-original/img/2020/09/06/23/55/59/84206039_p0.jpg";
	QNetworkRequest requestInfo1;
	requestInfo1.setUrl(QUrl(s1));

	//添加事件循环机制，返回后再运行后面的
	QEventLoop eventLoop1;
	QNetworkReply *reply1 = m_pHttpMgr1->get(requestInfo1);
	connect(reply1, SIGNAL(finished()), &eventLoop1, SLOT(quit()));
	eventLoop1.exec();       //block until finish
	//错误处理
	if (reply1->error() == QNetworkReply::NoError)
	{
		qDebug() << "request protobufHttp NoError";
	}
	else
	{
		qDebug() << "request protobufHttp handle errors here";
		QVariant statusCodeV = reply1->attribute(QNetworkRequest::HttpStatusCodeAttribute);
		//statusCodeV是HTTP服务器的相应码，reply->error()是Qt定义的错误码，可以参考QT的文档
		qDebug("request protobufHttp found error ....code: %d %d\n", statusCodeV.toInt(), (int)reply1->error());
		qDebug(qPrintable(reply1->errorString()));
	}
	//请求返回的结果
	QByteArray responseByte1 = reply1->readAll();

	auto currentPicture = new QPixmap;
	currentPicture->loadFromData(responseByte1);
	QDateTime now;


	qDebug() << curPath;
	QString filename;
	if (s1.right(3) == "png")
	{
		filename = curPath + "/" + sub + "/" + now.currentDateTime().toString("yyMMddhhmmss.png");
	}
	else
	{
		if (s1.right(3) == "jpg")
		{
			filename = curPath + "/" + sub + "/" + now.currentDateTime().toString("yyMMddhhmmss.jpg");
		}
	}

	currentPicture->save(filename);//保存图片
	qDebug() << filename;


	auto currentFileName = filename;
	a123 = currentFileName;
	emit jieshu();
}