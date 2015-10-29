#include "teacherpersonalwindow.h"
#include "teacherpersonalwindowmenu.h"
#include "teacherpersonalwindowmodifydata.h"
#include "personalwindowmenubutton.h"
#include "teacherpersonalwindowcoursedata.h"
/*#include "studentpersonalwindowbrowsedata.h"
#include "studentpersonalwindowmenubutton.h"
#include "studentpersonalwindowcoursedata.h"*/
#pragma execution_character_set("utf-8")
void TeacherPersonalWindow::init(){
    mainlayout = new QHBoxLayout;
    basicinformationlayout = new QVBoxLayout;
    basicinformationwidget = new QFrame;
    teachernumberlabel = new QLabel;
    emaillabel = new QLabel;
    phonelabel = new QLabel;
    namelabel = new QLabel;
    departmentnumberlabel = new QLabel;
    departmentnamelabel = new QLabel;
    basicinformationformlayout = new QFormLayout;
    basicinformationformwidget = new QWidget;
    controllmenu = new TeacherPersonalWindowMenu;
    modifydatawidget = new TeacherPersonalWindowModiyfyData(teachernumber);
    coursedatawidget = new TeacherPersonalWindowCourseData(teachernumber);
    /*browsedatawidget = new StudentPersonalWindowBrowseData(studentnumber);
    modifydatawidget = new StudentPersonalWindowModiyfyData(studentnumber);
    coursedatawidget = new StudentPersonalWindowCourseData(studentnumber);*/
}

TeacherPersonalWindow::TeacherPersonalWindow(QString teachernumber){
    //setStyleSheet("border: 1px solid black");
    this->teachernumber = teachernumber;
    init();

    query.prepare( "select teachernumber, teachername, teacher.departmentnumber , departmentname , email, phone from teacher,department where teacher.departmentnumber = department.departmentnumber and teachernumber = '"+teachernumber+"'" );
    query.exec();
    query.next();

    setlabelinformation();

    basicinformationformlayout->addRow("教職員編號：",teachernumberlabel);
    basicinformationformlayout->addRow("姓名：",namelabel);
    basicinformationformlayout->addRow("系所編號：",departmentnumberlabel);
    basicinformationformlayout->addRow("系所名稱：",departmentnamelabel);
    basicinformationformlayout->addRow("電子郵件：",emaillabel);
    basicinformationformlayout->addRow("分機(電話)：",phonelabel);

    basicinformationformwidget->setLayout(basicinformationformlayout);
    basicinformationformwidget->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);
    basicinformationlayout->addWidget(basicinformationformwidget);
    basicinformationlayout->setMargin(20);
    basicinformationlayout->setSpacing(20);
    basicinformationwidget->setLayout(basicinformationlayout);
    basicinformationwidget->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);
    basicinformationwidget->setFrameShape(QFrame::Panel);
    basicinformationwidget->setFrameShadow(QFrame::Raised);
    basicinformationwidget->setLineWidth(1);
    basicinformationwidget->setStyleSheet("background-color:#fbfbfb;font-size:20px;font-family:Microsoft JhengHei");

    //controllmenu->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);

    controllmenu->setMaximumWidth(800);
    /*connect(controllmenu->browsestudentdatalabel,SIGNAL(clicked()),this,SLOT(openbrowsedatawidget()));
    connect(browsedatawidget->backbutton,SIGNAL(clicked()),this,SLOT(closebrowsedatawidget()));*/

    connect(modifydatawidget->backbutton,SIGNAL(clicked()),this,SLOT(closemodifydatawidget()));
    connect(modifydatawidget,SIGNAL(submitedsuccess()),this,SLOT(refreshbasicinformation()));
    connect(controllmenu->modifyteacherdatalabel,SIGNAL(clicked()),this,SLOT(openmodifydatawidget()));
    connect(modifydatawidget->backbutton,SIGNAL(clicked()),this,SLOT(closemodifydatawidget()));
    connect(controllmenu->browsecourserecordlabel,SIGNAL(clicked()),this,SLOT(openbrowsecourserecordwidget()));
    connect(coursedatawidget->backbutton,SIGNAL(clicked()),this,SLOT(closebrowsecourserecordwidget()));

    mainlayout->addWidget(basicinformationwidget);
    mainlayout->addWidget(controllmenu);
    mainlayout->addWidget(modifydatawidget);
    mainlayout->addWidget(coursedatawidget);
    coursedatawidget->setVisible(false);
    modifydatawidget->setVisible(false);
    mainlayout->setAlignment(basicinformationwidget,Qt::AlignTop);
    mainlayout->setAlignment(modifydatawidget,Qt::AlignTop);
    mainlayout->setSpacing(30);
    mainlayout->setMargin(30);
    setLayout(mainlayout);
}

void TeacherPersonalWindow::setlabelinformation(){
    if(query.value(0).isNull()){
        teachernumberlabel->setText("尚未填寫");
    }else{
        teachernumberlabel->setText(query.value(0).toString());
    }
    if(query.value(1).isNull()){
        namelabel->setText("尚未填寫");
    }else{
        namelabel->setText(query.value(1).toString());
    }
    departmentnumberlabel->setText(query.value(2).toString());
    departmentnamelabel->setText(query.value(3).toString());
    if(query.value(4).isNull()){
        emaillabel->setText("尚未填寫");
    }else{
        emaillabel->setText(query.value(4).toString());
    }
    if(query.value(5).isNull()){
        phonelabel->setText("尚未填寫");
    }else{
        phonelabel->setText(query.value(5).toString());
    }
}

void TeacherPersonalWindow::openmodifydatawidget(){
    controllmenu->setVisible(false);
    modifydatawidget->setVisible(true);
}
void TeacherPersonalWindow::closemodifydatawidget(){
    modifydatawidget->setVisible(false);
    controllmenu->setVisible(true);
}
void TeacherPersonalWindow::openbrowsecourserecordwidget(){
    controllmenu->setVisible(false);
    coursedatawidget->setVisible(true);
}
void TeacherPersonalWindow::closebrowsecourserecordwidget(){
    coursedatawidget->setVisible(false);
    controllmenu->setVisible(true);
}

void TeacherPersonalWindow::refreshbasicinformation(){
    QSqlQuery refresh("select teachername, teacher.departmentnumber , departmentname, email, phone from teacher,department where department.departmentnumber = teacher.departmentnumber and teachernumber = '"+teachernumber+"'");
    refresh.exec();
    refresh.next();
    if(refresh.value(0).isNull()){
        namelabel->setText("尚未填寫");
    }else{
        namelabel->setText(refresh.value(0).toString());
    }
    departmentnumberlabel->setText(refresh.value(1).toString());
    departmentnamelabel->setText(refresh.value(2).toString());
    if(refresh.value(3).isNull()){
        emaillabel->setText("尚未填寫");
    }else{
        emaillabel->setText(refresh.value(3).toString());
    }
    if(refresh.value(4).isNull()){
        phonelabel->setText("尚未填寫");
    }else{
        phonelabel->setText(refresh.value(4).toString());
    }
}
