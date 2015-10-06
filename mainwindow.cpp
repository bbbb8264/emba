#include "mainwindow.h"
#include <QtWidgets>
#include <QtSql>
#include "studentmenu.h"
#include "addanewstudent.h"
#include "excel2.h"
#include "searchstudent.h"
#include "showastudent.h"
#include "addstudenttocourse.h"
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    init();
    setmenu();
    setWindowTitle("EMBA");

    setDB();
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
    mainmenu = new QMenu("主選單");
    studentdatamenu = new QMenu("維護學生資料");
    studentsearchmenu = new QMenu("查詢學生資訊");
    coursemenu = new QMenu("維護課程資料");
}
void MainWindow::opensearchstudent()
{/*
    StudentSelect* wid = new StudentSelect;
    setCentralWidget(wid);*/
}

void MainWindow::openaddanewstudent()
{
    AddANewStudent* wid = new AddANewStudent;
    setCentralWidget(wid);
}
void MainWindow::openstudenttocourse()
{
    AddStudentToCourse* wid = new AddStudentToCourse;
    setCentralWidget(wid);
}
