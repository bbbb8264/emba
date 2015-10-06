#ifndef MENU
#define MENU
#include <QWidget>
#include <QMainWindow>
#include "mainwindow.h"
#include <qlabel.h>
class QLabel;
class QVBoxLayout;
class menu : public QWidget
{
public:
    menu(MainWindow*);
    QLabel* l;
};

#endif // MENU

