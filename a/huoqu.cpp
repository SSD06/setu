#include "huoqu.h"
#include"quanju.h"
#include<QLineEdit>
huoqu::huoqu()
{

}
void huoqu::run()
{
    if (isr18 == 0)
    {
        url = url1+tag ;
    }
    else
    {
        if (isr18 == 1)
        {
            url = url1 +tag+ "&r18=1";
        }
        else
        {
            if (isr18 == 2)
            {
                url = url1  +tag+ "&r18=2";
            }
        }
    }
    QNetworkAccessManager *m_pHttpMgr = new QNetworkAccessManager();
    //设置url
   //qDebug() << url;
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
       //qDebug() << "request protobufHttp NoError";
    }
    else
    {
        /*key = key2;
        url = url1 + key;*/
       //qDebug() << "request protobufHttp handle errors here";
        QVariant statusCodeV = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
        //statusCodeV是HTTP服务器的相应码，reply->error()是Qt定义的错误码，可以参考QT的文档
       //qDebug("request protobufHttp found error ....code: %d %d\n", statusCodeV.toInt(), (int)reply->error());
       //qDebug(qPrintable(reply->errorString()));
    }
    //请求返回的结果
    QByteArray responseByte = reply->readAll();
   //qDebug() << responseByte;
    QString sr = responseByte;
   //qDebug() << sr;

//    QString s2=sr.mid(sr.indexOf("quota"));
//    s2=s2.mid(7,s2.indexOf("quota_min")-9);

//    int i2= s2.toInt();

//    QString s3 = QStringLiteral("今日还剩");//    + QString::number(i2);
//    if (key==key1)
//    {
//        s3 += QString::number(i2 + 300);
//    }
//    else
//    {
//        if (key==key2)
//        {
//            s3 += QString::number(i2);
//        }
//    }

//      s3 += QStringLiteral("次可用");

//   //qDebug() << s3;
//    cishu=s3;
   // emit hais();



   // ui->label_2->setText(s3);
   //qDebug() << s2;



    //sr.indexOf("jpg");
    QString s = sr.mid(sr.indexOf("https"));
   //qDebug() << s;
    QString s1 = s.mid(0,s.indexOf("r18")-3);
   //qDebug() << s1;

    s1 = s1.replace("\\/","/");
    s1 = s1.mid(0, s1.size() - 5);
   //qDebug() << s1;
   //qDebug() << " ";

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
       //qDebug() << "request protobufHttp NoError";
    }
    else
    {
       //qDebug() << "request protobufHttp handle errors here";
        QVariant statusCodeV = reply1->attribute(QNetworkRequest::HttpStatusCodeAttribute);
        //statusCodeV是HTTP服务器的相应码，reply->error()是Qt定义的错误码，可以参考QT的文档
       //qDebug("request protobufHttp found error ....code: %d %d\n", statusCodeV.toInt(), (int)reply1->error());
       //qDebug(qPrintable(reply1->errorString()));
    }
    //请求返回的结果
    QByteArray responseByte1 = reply1->readAll();

    auto currentPicture = new QPixmap;
    currentPicture->loadFromData(responseByte1);
    QDateTime now;
   // QString filename =  tr("/storage/emulated/0/色图/")+now.currentDateTime().toString("yyMMddhhmmss.jpg");
    QString filename;
        if (s1.right(3) == "png")
        {
            filename =tr("/storage/emulated/0/色图/") + now.currentDateTime().toString("yyMMddhhmmss.png");
        }
        else
        {
            if (s1.right(3) == "jpg")
            {
                filename = tr("/storage/emulated/0/色图/") + now.currentDateTime().toString("yyMMddhhmmss.jpg");
            }
        }
    currentPicture->save(filename);//保存图片
    auto currentFileName = filename;
    a123=currentFileName;
    emit jieshu();
    //可以在onpaint中 用QPixmap 显示currentPicture，则这种方法则不需要保存

    //显示图片，
//    QImage Image;
//    Image.load(filename);
//    QPixmap pixmap = QPixmap::fromImage(Image);

//    int with = ui->label->width();
//    int height = ui->label->height();
//   // QMovie *move = new QMovie(currentFileName);
//    QPixmap fitpixmap = pixmap.scaled(with, height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

//    ui->label->setPixmap(fitpixmap);

//    ui->label->setScaledContents(true);



}
