#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QtSql;
class QAction;
class QActionGroup;
class QLabel;
class QMenu;
class QButton;
class QSqlDatabase;
class QPushButton;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void openaddanewstudent();
    void opensearchstudent();
    void openstudenttocourse();
public:
    MainWindow(QWidget *parent = 0);
    void setDB();
    ~MainWindow();
    void setwid(QWidget* wid);
    void setmenu();
    void init();
    QLabel* main1;
    QMenuBar* mainmenubar;
    QMenu* mainmenu;
    QMenu* studentdatamenu;
    QMenu* studentsearchmenu;
    QMenu* coursemenu;
    QAction* action;
};

#endif // MAINWINDOW_H
