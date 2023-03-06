#pragma execution_character_set("utf-8")
#include "huoqu.h"
huoqu::huoqu()
{
	/*m_pHttpMgr.reset(new QNetworkAccessManager());
	m_pHttpMgr1.reset(new QNetworkAccessManager());*/
	//eventLoop.reset(new QEventLoop);
	//eventLoop1.reset(new QEventLoop);
	//currentPicture.reset(new QPixmap());
	curPath = QDir::currentPath();
}
void huoqu::run()
{
	while (!stop)
	{
		//QNetworkAccessManager* m_pHttpMgr = new QNetworkAccessManager();
		QSharedPointer<QNetworkAccessManager> m_pHttpMgr(new QNetworkAccessManager());
		//设置url
		//qDebug() << url;
		//QString url = "https://i.pixiv.cat/img-original/img/2020/09/06/23/55/59/84206039_p0.jpg";
		QNetworkRequest requestInfo;
		requestInfo.setUrl(QUrl(url));

		//添加事件循环机制，返回后再运行后面的
		QEventLoop eventLoop;
		QNetworkReply* reply = m_pHttpMgr->get(requestInfo);
		//QSharedPointer<QNetworkReply> reply(m_pHttpMgr->get(requestInfo));
		//connect(reply.get(), SIGNAL(finished()), &eventLoop, SLOT(quit()));
		connect(reply, SIGNAL(finished()), &eventLoop, SLOT(quit()));
		eventLoop.exec();       //block until finish
		//disconnect(reply.get(), SIGNAL(finished()), &eventLoop, SLOT(quit()));
		disconnect(reply, SIGNAL(finished()), &eventLoop, SLOT(quit()));
		//错误处理
		if (reply->error() == QNetworkReply::NoError&& !stop)
		{
			//qDebug() << "request protobufHttp NoError 1";
		}
		else
		{

			//qDebug() << "request protobufHttp handle errors here 1";
			//delete reply;
			reply->deleteLater();
			reply = nullptr;
			continue;
			//QVariant statusCodeV = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
			//statusCodeV是HTTP服务器的相应码，reply->error()是Qt定义的错误码，可以参考QT的文档
			//qDebug("request protobufHttp found error ....code: %d %d\n", statusCodeV.toInt(), (int)reply->error());
			//qDebug(qPrintable(reply->errorString()));
		}
		//请求返回的结果
		responseByte = reply->readAll();
		//delete reply;
		reply->deleteLater();
		reply = nullptr;
		s1 = QJsonDocument::fromJson(responseByte).object().value("data").toArray().at(0).toObject().value("urls").toObject().value("original").toString();
		if (s1.isEmpty())
		{
			continue;
		}
		QString title = QJsonDocument::fromJson(responseByte).object().value("data").toArray().at(0).toObject().value("title").toString();
		QString pid = QString::number(QJsonDocument::fromJson(responseByte).object().value("data").toArray().at(0).toObject().value("pid").toInt());
		//qDebug() << s1;
		//qDebug() << QJsonDocument::fromJson(responseByte).object().value("data").toArray().at(0).toObject().value("title").toString();
		filename = curPath + "/" + sub + "/"+ QString("%1%2.%3").arg(title).arg(pid).arg(s1.right(3));
		f1.setFileName(filename);
		if (f1.exists())
		{
			continue;
		}
		
		//QNetworkAccessManager* m_pHttpMgr1 = new QNetworkAccessManager();
		QSharedPointer<QNetworkAccessManager> m_pHttpMgr1(new QNetworkAccessManager());
		//设置url
		//QString url1 = "https://api.lolicon.app/setu/?apikey=23327833606bf37cbb86f3";
		//QString url = "https://i.pixiv.cat/img-original/img/2020/09/06/23/55/59/84206039_p0.jpg";
		QNetworkRequest requestInfo1;
		requestInfo1.setUrl(QUrl(s1));

		//添加事件循环机制，返回后再运行后面的
		QEventLoop eventLoop1;
		QNetworkReply* reply1 = m_pHttpMgr1->get(requestInfo1);
		//QSharedPointer<QNetworkReply> reply1(m_pHttpMgr->get(requestInfo));
		//connect(reply1.get(), SIGNAL(finished()), &eventLoop1, SLOT(quit()));
		connect(reply1, SIGNAL(finished()), &eventLoop1, SLOT(quit()));
		eventLoop1.exec();       //block until finish
		//disconnect(reply1.get(), SIGNAL(finished()), &eventLoop1, SLOT(quit()));
		disconnect(reply1, SIGNAL(finished()), &eventLoop1, SLOT(quit()));
		//错误处理
		if (reply1->error() == QNetworkReply::NoError && !stop)
		{
			//qDebug() << "request protobufHttp NoError 2";
		}
		else
		{
			//qDebug() << "request protobufHttp handle errors here 2";
			//delete reply1;
			reply1->deleteLater();
			reply1 = nullptr;
			continue;
			//QVariant statusCodeV = reply1->attribute(QNetworkRequest::HttpStatusCodeAttribute);
			//statusCodeV是HTTP服务器的相应码，reply->error()是Qt定义的错误码，可以参考QT的文档
			//qDebug("request protobufHttp found error ....code: %d %d\n", statusCodeV.toInt(), (int)reply1->error());
			//qDebug(qPrintable(reply1->errorString()));
		}
		//请求返回的结果
		responseByte = reply1->readAll();
		//delete reply1;
		reply1->deleteLater();
		reply1 = nullptr;
		if (!f1.open(QIODevice::WriteOnly)) {
			continue;
		}
		f1.write(responseByte);
		f1.close();
		//currentPicture->loadFromData(responseByte);
		//filename = curPath + "/" + sub + "/" + QString::number(threadnum) + QDateTime::currentDateTime().toString("yyMMddhhmmss.%1").arg(s1.right(3));
		//currentPicture->save(filename);//保存图片
		//qDebug() << filename;
		emit jieshu(filename);
	}
}

bool huoqu::getStop() const
{
	return stop;
}

void huoqu::setStop(bool value)
{
	stop = value;
}

void huoqu::seturl()
{
	url = apiurl;
	if (isR18 == 0)
	{
		url = url + tag;
	}
	else if (isR18 == 1)
	{
		url = url + tag + "&r18=1";
	}
	else if (isR18 == 2)
	{
		url = url + tag + "&r18=2";
	}
	//requestInfo.setUrl(QUrl(url));
}

int huoqu::getThreadnum() const
{
	return threadnum;
}

void huoqu::setThreadnum(int value)
{
	threadnum = value;
}

int huoqu::getIsR18() const
{
	return isR18;
}

void huoqu::setIsR18(int value)
{
	isR18 = value;
}

huoqu::~huoqu()
{
	/*m_pHttpMgr.clear();
	m_pHttpMgr1.clear();*/
	//currentPicture.clear();
	f1.close();
}

QString huoqu::getTag() const
{
	return tag;
}

void huoqu::setTag(const QString& value)
{
	tag = "tag=" + value;
}