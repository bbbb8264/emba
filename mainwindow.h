#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
class QAction;
class QActionGroup;
class QLabel;
class QMenu;
class QButton;
class QSqlDatabase;
class QPushButton;
class AddStudentToCourse;
class QStackedWidget;
class SelectStudent;
class SearchStudent;
class StudentPersonalWindow;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void openaddanewstudent();
    void opensearchstudent();
    void opensearchstudent2(QModelIndex);
    void openstudenttocourse();
    void openstudenttocourse2(QStringList,QStringList);
    void cleanStudentToCourseOpened();
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
    QStackedWidget* studentToCourseStackedWidget;
    bool isStudentToCourseOpened = false;
    bool isStudentToCourse2Opened = false;
    AddStudentToCourse* openedStudentToCourse;
    SelectStudent* openedStudentToCourse2;
    QStackedWidget* searchStudentStackedWidget;
    bool isSearchStudentOpened = false;
    bool isSearchStudent2Opened = false;
    SearchStudent* openedSearchStudent;
    StudentPersonalWindow* openedSearchStudent2;
};

#endif // MAINWINDOW_H
