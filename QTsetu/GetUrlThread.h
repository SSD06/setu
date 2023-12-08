#ifndef GETURLTHREAD_H
#define GETURLTHREAD_H

#include <QObject>
#include<QThread>
#include<QQueue>
#include<QThreadPool>
#include<QMutex>
#include<QMutexLocker>
class GetUrlThread : public QThread
{
    Q_OBJECT
public:
    enum R18_enum:uint
    {
        R18_OFF=0,
        R18_ON=1,
        R18_ALL
    };
    struct UrlFileInfo
    {
        UrlFileInfo(QString url,QString filename):Url(url),Filename(filename)
        {}
        QString Url;
        QString Filename;
        bool operator==(const UrlFileInfo &a)
        {
            if(a.Url==Url&&a.Filename==Filename)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

    };

    //static GetUrlThread *GlobalInstance();
    static GetUrlThread &GlobalInstance();
    const QString apiurl="https://api.lolicon.app/setu/v2";

    QQueue<UrlFileInfo> &getUrlfileinfoqueue();
    UrlFileInfo DequeueUrlfileinfo();
    void EnqueueUrlfileinfo(const UrlFileInfo &info);
    QString getTag() const;
    void setTag(const QString &value);

    uint getR18() const;
    void setR18(const uint &value);

    uint getNum() const;
    void setNum(const uint &value);

    bool getStop() const;
    void setStop(bool value);

private:
    //static GetUrlThread *instance;
    GetUrlThread();
    bool Stop=false;
    QString Tag;
    uint R18;
    uint num;
    QMutex queue_mutex;
    QQueue<UrlFileInfo> urlfileinfoqueue;
    const QRegExp regexp = QRegExp("[\\\\/:*?\"<>|]");
    QStringList USER_AGENTS;
protected:
    virtual void run() override;

signals:
    void Queuenum(uint num);
    void Enqueue();
};

#endif // GETURLTHREAD_H
