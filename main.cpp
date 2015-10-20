#include "mainwindow.h"
#include <QApplication>
#include <QtWidgets>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    MainWindow w;
    w.show();
    w.move(10,10);
    return a.exec();
}
