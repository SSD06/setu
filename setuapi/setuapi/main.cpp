#include "setuapi.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    setuapi w;
    w.show();
    return a.exec();
}
