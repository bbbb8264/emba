#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QtSql>
class AddStudentToCourse;
class SelectStudent;
class SearchStudent;
class StudentPersonalWindow;
class SearchTeacher;
class TeacherPersonalWindow;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void openaddanewcourse();
    void openaddanewstudent();
    void opensearchstudent();
    void opensearchstudent2(QModelIndex);
    void openstudenttocourse();
    void openstudenttocourse2(QStringList,QStringList);
    void cleanStudentToCourseOpened();
    void openaddanewteacher();
    void opensearchteacher();
    void opensearchteacher2(QModelIndex);
    void setStudentToCourseOpenedToFalse();
    void setSearchStudentOpenedToFalse();
    void setSearchTeacherOpenedToFalse();
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
    QMenu* teachermenu;
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
    SearchTeacher* openedSearchTeacher;
    StudentPersonalWindow* openedSearchStudent2;
    bool isSearchTeacherOpened = false;
    TeacherPersonalWindow* openedSearchTeacher2;
    QStackedWidget* searchTeacherStackedWidget;
    bool isSearchTeacher2Opened = false;
};

#endif // MAINWINDOW_H
