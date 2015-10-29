#include "mainwindow.h"
#include "addanewstudent.h"
#include "addanewcourse.h"
#include "searchstudent.h"
#include "studentpersonalwindow.h"
#include "addstudenttocourse.h"
#include "selectstudent.h"
#include "MySqlRelationalTableModel.h"
#include "studentpersonalwindowmenu.h"
#include "teacherpersonalwindow.h"
#include "teacherpersonalwindowmenu.h"
#include "personalwindowmenubutton.h"
#include "searchteacher.h"
#include "addanewteacher.h"
#include "addanewthesis.h"
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>
#pragma execution_character_set("utf-8")

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    /*init();
    setmenu();
    setWindowTitle("EMBA");
    setDB();
    QWidget* wid = new QWidget;
    QHBoxLayout* lay = new QHBoxLayout;
    AddANewThesis* wid2 = new AddANewThesis;
    lay->addWidget(wid2);
    wid->setLayout(lay);
    setCentralWidget(wid);*/
}
void MainWindow::setDB(){
    QSqlDatabase DB = QSqlDatabase::addDatabase("QMYSQL");
    DB.setHostName( "localhost" );
    DB.setDatabaseName( "emba" );
    DB.setUserName( "root" );
    DB.setPassword( "1234" );
    if( !DB.open() )
    {
        qDebug() << DB.lastError();
        qFatal( "Failed to connect." );
    }
    qDebug( "Connected!" );
}
void MainWindow::setwid(QWidget *wid){
    setCentralWidget(wid);
}

MainWindow::~MainWindow()
{
}
void MainWindow::setmenu()
{
    action = new QAction("新增一筆學生資料",this);
    connect(action,SIGNAL(triggered()),this,SLOT(openaddanewstudent()));
    studentdatamenu->addAction(action);
    action = new QAction("查詢學生資料",this);
    connect(action,SIGNAL(triggered()),this,SLOT(opensearchstudent()));
    studentdatamenu->addAction(action);
    action = new QAction("新增一筆課程資料",this);
    connect(action,SIGNAL(triggered()),this,SLOT(openaddanewcourse()));
    coursemenu->addAction(action);
    action = new QAction("將學生加入至課程當中",this);
    connect(action,SIGNAL(triggered()),this,SLOT(openstudenttocourse()));
    coursemenu->addAction(action);
    action = new QAction("新增一筆老師資料",this);
    connect(action,SIGNAL(triggered()),this,SLOT(openaddanewteacher()));
    teachermenu->addAction(action);
    action = new QAction("查詢老師資料",this);
    connect(action,SIGNAL(triggered()),this,SLOT(opensearchteacher()));
    teachermenu->addAction(action);
    mainmenu->addMenu(studentdatamenu);
    mainmenu->addMenu(teachermenu);
    mainmenu->addMenu(coursemenu);
    mainmenubar->addMenu(mainmenu);
    setMenuBar(mainmenubar);
}
void MainWindow::init()
{
    mainmenubar = new QMenuBar;
    mainmenu = new QMenu(tr("主選單"));
    studentdatamenu = new QMenu("維護學生資料");
    studentsearchmenu = new QMenu("查詢學生資訊");
    coursemenu = new QMenu("維護課程資料");
    teachermenu = new QMenu("維護老師資料");
}
void MainWindow::opensearchstudent()
{
    if(isSearchStudentOpened){
        searchStudentStackedWidget->setCurrentIndex(0);
    }else{
        isSearchStudentOpened = true;
        searchStudentStackedWidget = new QStackedWidget;
        connect(searchStudentStackedWidget,SIGNAL(destroyed()),this,SLOT(setSearchStudentOpenedToFalse()));
        openedSearchStudent = new SearchStudent;
        searchStudentStackedWidget->addWidget(openedSearchStudent);
        connect(openedSearchStudent->tableview,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(opensearchstudent2(QModelIndex)));
        setCentralWidget(searchStudentStackedWidget);
    }
}

void MainWindow::opensearchstudent2(QModelIndex index){
    int row = index.row();
    QString studentnumber = openedSearchStudent->model->data(openedSearchStudent->model->index(row,1)).toString();
    if(isSearchStudent2Opened){
        searchStudentStackedWidget->removeWidget(openedSearchStudent2);
        delete openedSearchStudent2;
    }else{
        isSearchStudent2Opened = true;
    }
    openedSearchStudent2 = new StudentPersonalWindow(studentnumber);
    connect(openedSearchStudent2->controllmenu->backlabel,SIGNAL(clicked()),this,SLOT(opensearchstudent()));
    searchStudentStackedWidget->addWidget(openedSearchStudent2);
    searchStudentStackedWidget->setCurrentIndex(1);
}

void MainWindow::openaddanewstudent()
{
    AddANewStudent* wid = new AddANewStudent;
    QWidget* wi = new QWidget;
    QHBoxLayout* lay = new QHBoxLayout;
    lay->addWidget(wid);
    lay->setAlignment(wid,Qt::AlignCenter);
    wi->setLayout(lay);
    setCentralWidget(wi);
}
void MainWindow::openstudenttocourse()
{
    if(isStudentToCourseOpened){
        studentToCourseStackedWidget->setCurrentIndex(0);
    }else{
        isStudentToCourseOpened = true;
        studentToCourseStackedWidget = new QStackedWidget;
        connect(studentToCourseStackedWidget,SIGNAL(destroyed()),this,SLOT(setStudentToCourseOpenedToFalse()));
        openedStudentToCourse = new AddStudentToCourse;
        studentToCourseStackedWidget->addWidget(openedStudentToCourse);
        connect(openedStudentToCourse,SIGNAL(submit(QStringList,QStringList)),this,SLOT(openstudenttocourse2(QStringList,QStringList)));
        setCentralWidget(studentToCourseStackedWidget);
    }
}
void MainWindow::openstudenttocourse2(QStringList course,QStringList coursename)
{
    if(isStudentToCourse2Opened){
        studentToCourseStackedWidget->removeWidget(openedStudentToCourse2);
        delete openedStudentToCourse2;
    }else{
        isStudentToCourse2Opened = true;
    }
    openedStudentToCourse2 = new SelectStudent(course,coursename);
    connect(openedStudentToCourse2->previousbutton,SIGNAL(clicked()),this,SLOT(openstudenttocourse()));
    connect(openedStudentToCourse2,SIGNAL(cleanPrevious()),this,SLOT(cleanStudentToCourseOpened()));
    studentToCourseStackedWidget->addWidget(openedStudentToCourse2);
    studentToCourseStackedWidget->setCurrentIndex(1);
}
void MainWindow::cleanStudentToCourseOpened(){
    setCentralWidget(new QWidget);
}

void MainWindow::openaddanewcourse(){
    AddANewCourse* wid = new AddANewCourse;
    setCentralWidget(wid);
}
void MainWindow::openaddanewteacher(){
    AddANewTeacher* wid = new AddANewTeacher;
    setCentralWidget(wid);
}
void MainWindow::opensearchteacher(){
    if(isSearchTeacherOpened){
        searchTeacherStackedWidget->setCurrentIndex(0);
    }else{
        isSearchTeacherOpened = true;
        searchTeacherStackedWidget = new QStackedWidget;
        connect(searchTeacherStackedWidget,SIGNAL(destroyed()),this,SLOT(setSearchTeacherOpenedToFalse()));
        openedSearchTeacher = new SearchTeacher;
        searchTeacherStackedWidget->addWidget(openedSearchTeacher);
        connect(openedSearchTeacher->tableview,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(opensearchteacher2(QModelIndex)));
        setCentralWidget(searchTeacherStackedWidget);
    }
}
void MainWindow::opensearchteacher2(QModelIndex index){
    int row = index.row();
    QString teachernumber = openedSearchTeacher->model->data(openedSearchTeacher->model->index(row,0)).toString();
    if(isSearchTeacher2Opened){
        searchTeacherStackedWidget->removeWidget(openedSearchTeacher2);
        delete openedSearchTeacher2;
    }else{
        isSearchTeacher2Opened = true;
    }
    openedSearchTeacher2 = new TeacherPersonalWindow(teachernumber);
    connect(openedSearchTeacher2->controllmenu->backlabel,SIGNAL(clicked()),this,SLOT(opensearchteacher()));
    searchTeacherStackedWidget->addWidget(openedSearchTeacher2);
    searchTeacherStackedWidget->setCurrentIndex(1);
}

void MainWindow::setStudentToCourseOpenedToFalse(){
    isStudentToCourseOpened = false;
    isStudentToCourse2Opened = false;
}
void MainWindow::setSearchStudentOpenedToFalse(){
    isSearchStudentOpened = false;
    isSearchStudent2Opened = false;
}
void MainWindow::setSearchTeacherOpenedToFalse(){
    isSearchTeacherOpened = false;
    isSearchTeacher2Opened = false;
}
