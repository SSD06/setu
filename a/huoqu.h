#ifndef HUOQU_H
#define HUOQU_H
#include<QThread>
#include <QtWidgets/QApplication>
#include <QtNetwork/QtNetwork>
#include<QtAndroidExtras/QtAndroid>
#include <QtAndroid>
#include<QMessageBox>
#include<QJsonArray>
#include<QJsonDocument>
#include<QJsonObject>
#include<QFile>
class huoqu : public QThread
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
    const QString apiurl = "https://api.lolicon.app/setu/v2/?";
    QString tag;
    int isR18;
    int threadnum;
    bool stop=false;
    //QSharedPointer<QPixmap>currentPicture;
    QString url;
    QString s1;
    QByteArray responseByte;
    QString filename;
    QFile f1;

signals:
    void jieshu(QString filename);
};

#endif // HUOQU_H
