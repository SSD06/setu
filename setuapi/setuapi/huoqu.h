#pragma once
#include <qthread.h>
class huoqu :public QThread
{
	Q_OBJECT
public:
	QString huo(QString url);
	QString url1 = "https://api.lolicon.app/setu/v2/?";

	QString key1 = "23327833606bf37cbb86f3";
	QString key2 = "08248891606b09299f3560";
	QString key = key1;
	QString url = url1;
protected:
	void run() Q_DECL_OVERRIDE;
private:


signals:
	void jieshu();
	void hais();
};

