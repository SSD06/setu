#ifndef DOWNLOADTHREAD_H
#define DOWNLOADTHREAD_H

#include<QVector>
#include<GetUrlThread.h>
#include<QWaitCondition>
#include<QSharedPointer>

class DownloadThread : public QThread
{
    Q_OBJECT
    friend class DownloadThreadPool;
public:
    //static DownloadThread &GlobalInstance();
    bool getStop() const;
    void setStop(bool value);

private:
    DownloadThread();
    bool Stop=false;
    QMutex mutex;

protected:

    virtual void run() override;

signals:
    void filename(QString);
};
class DownloadThreadPool:public QObject
{
    Q_OBJECT

public:
    static DownloadThreadPool &GlobalInstance();
    QWaitCondition waitcondition;
    void start();
    void stop();
    uint getThreadNum() const;
    void setThreadNum(const uint &value);

    bool getStop() const;
    void setStop(bool value);


    QQueue<QString>& getQueue_filename();

private:
    bool Stop=false;
    uint ThreadNum;
    QVector<QSharedPointer<DownloadThread>> threadpool;
    DownloadThreadPool();
    QQueue<QString> queue_filename;
};


#endif // DOWNLOADTHREAD_H
