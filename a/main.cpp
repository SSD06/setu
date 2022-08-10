#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include<QTextStream>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    QFile file(":/lightblue.css");
//    file.open(QFile::ReadOnly | QFile::Text);
//    QTextStream stream(&file);
//    a.setStyleSheet(stream.readAll());
    MainWindow w;
    w.show();
    return a.exec();
}
