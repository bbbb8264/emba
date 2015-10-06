
#include "menu.h"
#include <QtWidgets>

menu::menu(MainWindow* parent){
    l = new QLabel("123");
    QVBoxLayout* lay = new QVBoxLayout;
    lay->addWidget(l);
    this->setLayout(lay);
    QWidget* a = new QWidget;
    QVBoxLayout* lay2 = new QVBoxLayout;
    QLabel* ll = new QLabel("456");
    lay2->addWidget(ll);
    a->setLayout(lay2);
    parent->setCentralWidget(a);
}
