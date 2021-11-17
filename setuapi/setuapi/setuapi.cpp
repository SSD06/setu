#pragma execution_character_set("utf-8")
#include "setuapi.h"
#include"widget1.h"
#include"quanju.h"
#include"xunh.h"
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
#include"huoqu.h"
#include<qvector.h>
//QString url = "https://api.lolicon.app/setu/?apikey=23327833606bf37cbb86f3";
QString url1 = "https://api.lolicon.app/setu/?apikey=";

QString key1 = "23327833606bf37cbb86f3";
QString key2 = "08248891606b09299f3560";
QString key = key1;
QString url = url1 + key;



setuapi::setuapi(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	QString  curPath = QDir::currentPath();
	QDir dir(curPath);
	
	QString sub = "色图";
	dir.mkdir(sub);
	ui.radioButton->setChecked(true);
	qDebug() << url;
	connect(ui.radioButton, &QRadioButton::clicked, [=]() {
		url = url1 + key;
		isr18 = 0;
		qDebug() << "ffffff";
		});
	connect(ui.radioButton_2, &QRadioButton::clicked, [=]() {
		url = url1 + key + "&r18=1";
		isr18 = 1;
		});
	connect(ui.radioButton_3, &QRadioButton::clicked, [=]() {
		url = url1 + key + "&r18=2";
		isr18 = 2;
		});

	//widget1 *w1 = new widget1(this);



	////w1->setAttribute(Qt::WA_DeleteOnClose);
	////w1->setWindowFlag(Qt::Window, true);
	////w1.setWindowOpacity(1);



	//ui.centralWidget->close();
	//w1->show();
	//connect(w1->ui.pushButton, &QPushButton::clicked, [=]() {
	//	ui.centralWidget->show();

	//	});



	//this->setWindowOpacity(0.5);


	/*QVector<huoqu*>t;
	t.push_back(new huoqu());*/

	huoqu *t1 = new huoqu();
	xunh *t2 = new xunh(t1,this);
	t2->start();
	//connect(this, &setuapi::wan, [=]() {
	//	t1->quit();

	////	t1->start();
	//	
	//	emit chongx();
	//	});
	//connect(this, &setuapi::chongx, [=]() {
	//	if (t1->isFinished() == true)
	//	{
	//		qDebug() << "线程重启成功";
	//		t1->start();
	//	}
	//	
	//	});

	connect(t1, &huoqu::hais, [=]() {
		ui.label_2->setText(cishu);
		});

	connect(t1, &huoqu::jieshu, [=]() {
		QString filename;
		filename = a123;
		auto currentFileName = filename;

		QImage Image;
		Image.load(filename);
		QPixmap pixmap = QPixmap::fromImage(Image);

		int with = ui.label->width();
		int height = ui.label->height();
		//QMovie *move = new QMovie(currentFileName);
		QPixmap fitpixmap = pixmap.scaled(with, height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

		ui.label->setPixmap(fitpixmap);


		//ui.label->setMovie(move);

		ui.label->setScaledContents(true);

		emit wan();
		});


	connect(ui.pushButton_2, &QPushButton::clicked, [=]() {
	loop:

		switch (isz)
		{
		case 1:
			isz = 0;
			t1->start();
			ui.pushButton_2->setText("停止");
			break;
		case 0:
			isz = 1;
			t1->quit();
			ui.pushButton_2->setText("随机色图");
			break;

		case 2:

			break;
		default:
			break;
		}
		//if (isz == 0)//0停止1启动2暂停
		//{
		//	isz = 1;
		//	t1->start();
		//}

		//if (isz==1)
		//{
		//	isz = 0;
		//	ui.pushButton_2->setText("停止");
		//}

		//if (true)
		//{
		//	t1->quit();
		//	isz = 1;
		//	ui.pushButton_2->setText("随机色图");
		//}


		//t1->start();




		//t[0]->start();
		//QNetworkAccessManager *m_pHttpMgr = new QNetworkAccessManager();
		////设置url
		//qDebug() << url;
		////QString url = "https://i.pixiv.cat/img-original/img/2020/09/06/23/55/59/84206039_p0.jpg";
		//QNetworkRequest requestInfo;
		//requestInfo.setUrl(QUrl(url));

		////添加事件循环机制，返回后再运行后面的
		//QEventLoop eventLoop;
		//QNetworkReply *reply = m_pHttpMgr->get(requestInfo);
		//connect(reply, SIGNAL(finished()), &eventLoop, SLOT(quit()));
		//eventLoop.exec();       //block until finish
		////错误处理
		//if (reply->error() == QNetworkReply::NoError)
		//{
		//	qDebug() << "request protobufHttp NoError";
		//}
		//else
		//{
		//	/*key = key2;
		//	url = url1 + key;*/
		//	qDebug() << "request protobufHttp handle errors here";
		//	QVariant statusCodeV = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
		//	//statusCodeV是HTTP服务器的相应码，reply->error()是Qt定义的错误码，可以参考QT的文档
		//	qDebug("request protobufHttp found error ....code: %d %d\n", statusCodeV.toInt(), (int)reply->error());
		//	qDebug(qPrintable(reply->errorString()));
		//}
		////请求返回的结果
		//QByteArray responseByte = reply->readAll();
		//qDebug() << responseByte;
		//QString sr = responseByte;
		//qDebug() << sr;

		//QString s2 = sr.mid(sr.indexOf("quota"));
		//s2 = s2.mid(7, s2.indexOf("quota_min") - 9);

		//int i2 = s2.toInt();

		//QString s3 = "今日还剩";//    + QString::number(i2);
		//if (key == key1)
		//{
		//	s3 += QString::number(i2 + 300);
		//}
		//else
		//{
		//	if (key == key2)
		//	{
		//		s3 += QString::number(i2);
		//	}
		//}

		//s3 += "次可用";

		//qDebug() << s3;

		//ui.label_2->setText(s3);
		//qDebug() << s2;
		//if (i2 == 0)
		//{
		//	if (key != key2)
		//	{
		//		key = key2;
		//		if (ui.radioButton->isChecked())
		//		{
		//			url = url1 + key;
		//		}
		//		else
		//		{
		//			if (ui.radioButton_2->isChecked())
		//			{
		//				url = url1 + key + "&r18=1";
		//			}
		//			else
		//			{
		//				if (ui.radioButton_3->isChecked())
		//				{
		//					url = url1 + key + "&r18=2";
		//				}
		//			}
		//		}
		//	}

		//	//goto loop;

		//}
		////sr.indexOf("jpg");
		//QString s = sr.mid(sr.indexOf("https"));
		//qDebug() << s;
		//QString s1 = s.mid(0, s.indexOf("r18") - 3);
		//qDebug() << s1;

		//s1 = s1.replace("\\/", "/");
		//qDebug() << s1;
		//qDebug() << s1.right(3);
		//qDebug() << " ";

		//QNetworkAccessManager *m_pHttpMgr1 = new QNetworkAccessManager();
		////设置url
		////QString url1 = "https://api.lolicon.app/setu/?apikey=23327833606bf37cbb86f3";
		////QString url = "https://i.pixiv.cat/img-original/img/2020/09/06/23/55/59/84206039_p0.jpg";
		//QNetworkRequest requestInfo1;
		//requestInfo1.setUrl(QUrl(s1));

		////添加事件循环机制，返回后再运行后面的
		//QEventLoop eventLoop1;
		//QNetworkReply *reply1 = m_pHttpMgr1->get(requestInfo1);
		//connect(reply1, SIGNAL(finished()), &eventLoop1, SLOT(quit()));
		//eventLoop1.exec();       //block until finish
		////错误处理
		//if (reply1->error() == QNetworkReply::NoError)
		//{
		//	qDebug() << "request protobufHttp NoError";
		//}
		//else
		//{
		//	qDebug() << "request protobufHttp handle errors here";
		//	QVariant statusCodeV = reply1->attribute(QNetworkRequest::HttpStatusCodeAttribute);
		//	//statusCodeV是HTTP服务器的相应码，reply->error()是Qt定义的错误码，可以参考QT的文档
		//	qDebug("request protobufHttp found error ....code: %d %d\n", statusCodeV.toInt(), (int)reply1->error());
		//	qDebug(qPrintable(reply1->errorString()));
		//}
		////请求返回的结果
		//QByteArray responseByte1 = reply1->readAll();


		//auto currentPicture = new QPixmap;
		//currentPicture->loadFromData(responseByte1);
		//QDateTime now;


		//qDebug() << curPath;
		QString filename;
		//if (s1.right(3) == "png")
		//{
		//	filename = curPath + "/" + sub + "/" + now.currentDateTime().toString("yyMMddhhmmss.png");
		//}
		//else
		//{
		//	if (s1.right(3) == "jpg")
		//	{
		//		filename = curPath + "/" + sub + "/" + now.currentDateTime().toString("yyMMddhhmmss.jpg");
		//	}
		//}

		//currentPicture->save(filename);//保存图片
		//qDebug() << filename;

		//filename = a123;
		//auto currentFileName = filename;

		////可以在onpaint中 用QPixmap 显示currentPicture，则这种方法则不需要保存

		////显示图片，
		//QImage Image;
		//Image.load(filename);
		//QPixmap pixmap = QPixmap::fromImage(Image);

		//int with = ui.label->width();
		//int height = ui.label->height();
		////QMovie *move = new QMovie(currentFileName);
		//QPixmap fitpixmap = pixmap.scaled(with, height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

		//ui.label->setPixmap(fitpixmap);


		////ui.label->setMovie(move);




		//ui.label->setScaledContents(true);



		//	move->start();






		//QNetworkAccessManager *manager;
		//manager = new QNetworkAccessManager(this);
		//connect(manager, SIGNAL(finished(QNetworkReply*)),this, SLOT(replyFinished(QNetworkReply*)));
		//manager->get(QNetworkRequest(QUrl("https://i.pixiv.cat/img-original/img/2020/09/06/23/55/59/84206039_p0.jpg")));

		//if (reply->error() == QNetworkReply::NoError)
		//{
		//	//获取字节流构造 QPixmap 对象
			//currentPicture->loadFromData(reply->readAll());
			//QDateTime now;
			//QString filename = now.currentDateTime().toString("yyMMddhhmmss.jpg");
			//currentPicture->save(filename);//保存图片
			//currentFileName = filename;

			////可以在onpaint中 用QPixmap 显示currentPicture，则这种方法则不需要保存

			////显示图片，
			//QMovie *move = new QMovie(currentFileName);
			//ImageLabel->setMovie(move);
			//move->start();
		//}



		/*QImage image;
		image.load("F:0.jpg");
		QPainter painter(&image);
		QImage result = image.scaled(ui.label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
		ui.label->setPixmap(QPixmap::fromImage(result));*/



		//qDebug() << "QSslSocket=" << QSslSocket::sslLibraryBuildVersionString();
		//qDebug() << "OpenSSL支持情况:" << QSslSocket::supportsSsl();

		});




















}
