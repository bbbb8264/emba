#include "mainwindow.h"
#include <QtWidgets>
#include <QtSql>
#include "addanewstudent.h"
#include "searchstudent.h"
#include "studentpersonalwindow.h"
#include "addstudenttocourse.h"
#include "selectstudent.h"
#include "MySqlRelationalTableModel.h"
#include "studentpersonalwindowmenu.h"
#include "studentpersonalwindowmenubutton.h"
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>
#pragma execution_character_set("utf-8")
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    init();
    setmenu();
    setWindowTitle("EMBA");
    setDB();
    StudentPersonalWindow* a = new StudentPersonalWindow("R0777");
    setCentralWidget(a);
    //menu->addMenu(new;QMenu("主選單"));
    /*menu* v = new menu(this);
    setCentralWidget(v);
    statusBar();
    setWindowTitle(tr("EMBA管理系統"));
    menuBar()->addMenu(tr(" 檔案 "));
    main1 = new QLabel(tr("報考"));
    main1->setFixedSize(100,100);
    QVBoxLayout *layout = new QVBoxLayout;
    layout->setMargin(5);
    layout->addWidget(main1);
    wid->setLayout(layout);
    setDB();
    query("show tables;");
    query.next();
    main1->setText(query.value(0).toString());*/
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
    action = new QAction("查詢單一學生資料",this);
    connect(action,SIGNAL(triggered()),this,SLOT(opensearchstudent()));
    studentsearchmenu->addAction(action);
    action = new QAction("新增學生至課程當中",this);
    connect(action,SIGNAL(triggered()),this,SLOT(openstudenttocourse()));
    coursemenu->addAction(action);
    mainmenu->addMenu(studentdatamenu);
    mainmenu->addMenu(studentsearchmenu);
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
}
void MainWindow::opensearchstudent()
{
    isStudentToCourseOpened = false;
    isStudentToCourse2Opened = false;
    if(isSearchStudentOpened){
        searchStudentStackedWidget->setCurrentIndex(0);
    }else{
        isSearchStudentOpened = true;
        searchStudentStackedWidget = new QStackedWidget;
        openedSearchStudent = new SearchStudent;
        searchStudentStackedWidget->addWidget(openedSearchStudent);
        connect(openedSearchStudent->tableview,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(opensearchstudent2(QModelIndex)));
        setCentralWidget(searchStudentStackedWidget);
    }
}

void MainWindow::opensearchstudent2(QModelIndex index){
    qDebug() << openedSearchStudent->model->data(openedSearchStudent->model->index(index.row(),1)).toString();
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
    isStudentToCourseOpened = false;
    isStudentToCourse2Opened = false;
    isSearchStudentOpened = false;
    isSearchStudent2Opened = false;
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
    isSearchStudentOpened = false;
    isSearchStudent2Opened = false;
    if(isStudentToCourseOpened){
        studentToCourseStackedWidget->setCurrentIndex(0);
    }else{
        isStudentToCourseOpened = true;
        studentToCourseStackedWidget = new QStackedWidget;
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
    isStudentToCourseOpened = false;
    isStudentToCourse2Opened = false;
    setCentralWidget(new QWidget);
}
