#include "setuapi.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
	//QFile file(":/setuapi/lightblue.css");
	//file.open(QFile::ReadOnly | QFile::Text);
	//QTextStream stream(&file);
	//a.setStyleSheet(stream.readAll());
    setuapi w;
    w.show();
    return a.exec();
}
