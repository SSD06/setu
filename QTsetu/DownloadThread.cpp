#include "DownloadThread.h"
#include<QFile>
#include<QNetworkAccessManager>
#include<QNetworkReply>
#include<QNetworkRequest>
#include<QEventLoop>
#include<QUrlQuery>
#include<QJsonDocument>
#include<QJsonArray>
#include<QJsonObject>
DownloadThread::DownloadThread()
{

}

bool DownloadThread::getStop() const
{
    return Stop;
}

void DownloadThread::setStop(bool value)
{
    Stop = value;
}

void DownloadThread::run()
{

    while (!Stop)
    {
        while(GetUrlThread::GlobalInstance().getUrlfileinfoqueue().isEmpty()&&!Stop)
        {
            mutex.lock();
            DownloadThreadPool::GlobalInstance().waitcondition.wait(&mutex);
            mutex.unlock();
        }
        if(Stop)
        {
            break;
        }
        auto urlfileinfo=GetUrlThread::GlobalInstance().DequeueUrlfileinfo();
        QNetworkAccessManager *m_pHttpMgr=new QNetworkAccessManager();
        QNetworkRequest requestInfo;
        QUrl url(urlfileinfo.Url);
        requestInfo.setUrl(url);
        QEventLoop eventLoop;
        QNetworkReply* reply = m_pHttpMgr->get(requestInfo);
        connect(reply,&QNetworkReply::finished, &eventLoop,&QEventLoop::quit);
        eventLoop.exec();
        if(reply->error()==QNetworkReply::NoError&&!Stop)
        {
            QByteArray responseByte = reply->readAll();
            m_pHttpMgr->deleteLater();
            reply->deleteLater();
            QFile file(urlfileinfo.Filename);
            if(file.open(QIODevice::WriteOnly|QIODevice::Truncate))
            {
                file.write(responseByte);
                file.close();
                emit filename(urlfileinfo.Filename);
            }
        }
        else
        {
            m_pHttpMgr->deleteLater();
            reply->deleteLater();
            continue;
        }
    }
}

DownloadThreadPool &DownloadThreadPool::GlobalInstance()
{
    static DownloadThreadPool a;
    return a;
}

void DownloadThreadPool::start()
{
    for(uint i=0;i<ThreadNum;i++)
    {
        QSharedPointer<DownloadThread> p;
        p.reset(new DownloadThread());
        connect(p.get(),&DownloadThread::filename,this,[&](const QString &filename){
            queue_filename.enqueue(filename);
            //qDebug()<<"aaaaaaaaaaa"<<filename;
        });
        threadpool.push_back(p);
    }
    for(auto &thread:threadpool)
    {
        thread->setStop(false);
        thread->start();
    }
}

void DownloadThreadPool::stop()
{

    for(auto &thread:threadpool)
    {
        thread->setStop(true);

    }
    waitcondition.wakeAll();
    for(auto &thread:threadpool)
    {
        thread->quit();

    }
    while (true)
    {
        bool stopall=false;
        for(auto &thread:threadpool)
        {
            stopall = stopall || thread->isRunning();
        }
        if (stopall == false)
        {
            break;
        }
    }
    threadpool.clear();

}

uint DownloadThreadPool::getThreadNum() const
{
    return ThreadNum;
}

void DownloadThreadPool::setThreadNum(const uint &value)
{
    ThreadNum = value;
}

bool DownloadThreadPool::getStop() const
{
    return Stop;
}

void DownloadThreadPool::setStop(bool value)
{
    Stop = value;
}

DownloadThreadPool::DownloadThreadPool()
{

}

QQueue<QString>& DownloadThreadPool::getQueue_filename()
{
    return queue_filename;
}

