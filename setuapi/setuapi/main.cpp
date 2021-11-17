#include "setuapi.h"
#include"widget1.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    setuapi w;
    w.show();


	//widget1 w1;
	//w1.show();



    return a.exec();
}
