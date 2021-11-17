#pragma once
#include <qthread.h>
#include"huoqu.h"
#include"setuapi.h"
#include"quanju.h"
class xunh :
	public QThread
{
	Q_OBJECT
public:
	huoqu *t1;
	setuapi *k1;
	xunh(huoqu *t,setuapi *k);
protected:
	void run() Q_DECL_OVERRIDE;
private:


signals:
};

