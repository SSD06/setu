#include "GetUrlThread.h"
#include<QNetworkAccessManager>
#include<QNetworkReply>
#include<QNetworkRequest>
#include<QEventLoop>
#include<QUrlQuery>
#include<QJsonDocument>
#include<QJsonArray>
#include<QJsonObject>
#include<QFile>

GetUrlThread::GetUrlThread()
{
    USER_AGENTS<<"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/70.0.3538.77 Safari/537.36";
    USER_AGENTS<<"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/79.0.3945.88 Safari/537.36'";
    USER_AGENTS<<"Mozilla/5.0 (Windows NT 6.2; WOW64) AppleWebKit/537.36 (KHTML like Gecko) Chrome/44.0.2403.155 Safari/537.36";
    USER_AGENTS<<"Mozilla/5.0 (Windows NT 6.1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/41.0.2228.0 Safari/537.36";
    USER_AGENTS<<"Mozilla/5.0 (Macintosh; Intel Mac OS X 10_10_1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/41.0.2227.1 Safari/537.36 Chrome 41.0.2227.0";
    USER_AGENTS<<"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/41.0.2227.0 Safari/537.36";
    USER_AGENTS<<"Mozilla/5.0 (Windows NT 6.3; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/41.0.2226.0 Safari/537.36";
    USER_AGENTS<<"Mozilla/5.0 (Windows NT 6.3; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/41.0.2225.0 Safari/537.36";
}

bool GetUrlThread::getStop() const
{
    return Stop;
}

void GetUrlThread::setStop(bool value)
{
    Stop = value;
}

uint GetUrlThread::getNum() const
{
    return num;
}

void GetUrlThread::setNum(const uint &value)
{
    num = value;
}

uint GetUrlThread::getR18() const
{
    return R18;
}

void GetUrlThread::setR18(const uint &value)
{
    R18 = value;
}

QString GetUrlThread::getTag() const
{
    return Tag;
}

void GetUrlThread::setTag(const QString &value)
{
    Tag = value;
}


//GetUrlThread *GetUrlThread::GlobalInstance()
//{
//    if(instance==nullptr)
//    {
//        instance=new GetUrlThread();
//    }
//    return instance;
//}

GetUrlThread &GetUrlThread::GlobalInstance()
{
    static GetUrlThread a;
    return a;
}

QQueue<GetUrlThread::UrlFileInfo>& GetUrlThread::getUrlfileinfoqueue()
{
    return urlfileinfoqueue;
}

GetUrlThread::UrlFileInfo GetUrlThread::DequeueUrlfileinfo()
{
    QMutexLocker locker(&queue_mutex);
    auto a=urlfileinfoqueue.dequeue();
    emit Queuenum(urlfileinfoqueue.size());
    return  a;

}

void GetUrlThread::EnqueueUrlfileinfo(const UrlFileInfo &info)
{
    QMutexLocker locker(&queue_mutex);
    urlfileinfoqueue.enqueue(info);
    emit Enqueue();
    emit Queuenum(urlfileinfoqueue.size());
}

void GetUrlThread::run()
{
    while (!Stop)
    {
        QNetworkAccessManager *m_pHttpMgr=new QNetworkAccessManager();
        QNetworkRequest requestInfo;
        qsrand(QTime(0,0,0).msecsTo(QTime::currentTime()));
        auto head=USER_AGENTS.at(qrand()%USER_AGENTS.size());
        requestInfo.setHeader(QNetworkRequest::UserAgentHeader,head);
        //qDebug()<<requestInfo.header(QNetworkRequest::UserAgentHeader);
        QUrl url(apiurl);
        QUrlQuery query;
        query.addQueryItem("r18",QString::number(R18));
        if(!Tag.isEmpty())
        {
            query.addQueryItem("tag",Tag);
        }
        query.addQueryItem("num",QString::number(20));
        url.setQuery(query);
        requestInfo.setUrl(url);
        QEventLoop eventLoop;
        QNetworkReply* reply = m_pHttpMgr->get(requestInfo);
        connect(reply,&QNetworkReply::finished, &eventLoop,&QEventLoop::quit);
        eventLoop.exec();
        if(reply->error()==QNetworkReply::NoError&&!Stop)
        {
            QByteArray responseByte = reply->readAll();
            //qDebug()<<responseByte;
            m_pHttpMgr->deleteLater();
            reply->deleteLater();
            auto jsonDocument=QJsonDocument::fromJson(responseByte);
            qDebug()<<jsonDocument;
            if(!jsonDocument.isObject())
            {
                continue;
            }
            auto datas=jsonDocument.object().value("data").toArray();
            if(datas.isEmpty())
            {
                continue;
            }
            for(auto data:datas)
            {

                auto fileurl=data.toObject().value("urls").toObject().value("original").toString();
                QString title = data.toObject().value("title").toString();
                title.replace(regexp,"-");
                QString ext=data.toObject().value("ext").toString();
                QString pid = QString::number(data.toObject().value("pid").toInt());
                auto filename=QString("./色图/%1%2.%3").arg(title).arg(pid).arg(ext);
                auto fileinfo=UrlFileInfo(fileurl,filename);
                if(QFile::exists(filename)||urlfileinfoqueue.contains(fileinfo))
                {
                    continue;
                }
                EnqueueUrlfileinfo(fileinfo);
            }
//            for(auto a:urlfileinfoqueue)
//            {
//                qDebug()<<a.Url;
//                qDebug()<<a.Filename;
//            }
        }
        else
        {
            qDebug()<<"访问失败"<<reply->error();
            m_pHttpMgr->deleteLater();
            reply->deleteLater();
            continue;
        }
    }
}


