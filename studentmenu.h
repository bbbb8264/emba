#ifndef STUDENTMENU
#define STUDENTMENU

#endif // STUDENTMENU
#include <QWidget>
#include <QMainWindow>
#include <QPushButton>
#include <string.h>
#include "mainwindow.h"
using namespace std;

class StudentMenu : public QWidget
{
public:
    StudentMenu();
private:
    QPushButton* makeButton(string text);
};
