#include "studentpersonalwindow.h"
#include "studentpersonalwindowmenu.h"
#include "studentpersonalwindowbrowsedata.h"
#include "personalwindowmenubutton.h"
#include "studentpersonalwindowmodifydata.h"
#include "studentpersonalwindowcoursedata.h"
#pragma execution_character_set("utf-8")
void StudentPersonalWindow::init(){
    mainlayout = new QHBoxLayout;
    basicinformationlayout = new QVBoxLayout;
    basicinformationwidget = new QFrame;
    ticketnumberlabel = new QLabel;
    levellabel = new QLabel;
    genderlabel = new QLabel;
    namelabel = new QLabel;
    studentnumberlabel = new QLabel;
    studentidentitylabel = new QLabel;
    picturelabel = new QLabel;
    basicinformationformlayout = new QFormLayout;
    basicinformationformwidget = new QWidget;
    controllmenu = new StudentPersonalWindowMenu;
    browsedatawidget = new StudentPersonalWindowBrowseData(studentnumber);
    modifydatawidget = new StudentPersonalWindowModiyfyData(studentnumber);
    coursedatawidget = new StudentPersonalWindowCourseData(studentnumber);
}

StudentPersonalWindow::StudentPersonalWindow(QString studentnumber){
    //setStyleSheet("border: 1px solid black");
    this->studentnumber = studentnumber;
    init();

    query.prepare( "select * from student where studentnumber = :studentnumber" );
    query.bindValue(":studentnumber",studentnumber);
    query.exec();
    query.next();

    setlabelinformation();

    basicinformationformlayout->addRow("准考證號碼：",ticketnumberlabel);
    basicinformationformlayout->addRow("報考身分：",studentidentitylabel);
    basicinformationformlayout->addRow("學號：",studentnumberlabel);
    basicinformationformlayout->addRow("姓名：",namelabel);
    basicinformationformlayout->addRow("性別：",genderlabel);
    basicinformationformlayout->addRow("畢業級數：",levellabel);
    basicinformationformwidget->setLayout(basicinformationformlayout);
    basicinformationformwidget->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);
    basicinformationlayout->addWidget(picturelabel);
    basicinformationlayout->addWidget(basicinformationformwidget);
    basicinformationlayout->setAlignment(picturelabel,Qt::AlignHCenter);
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
    connect(controllmenu->browsestudentdatalabel,SIGNAL(clicked()),this,SLOT(openbrowsedatawidget()));
    connect(browsedatawidget->backbutton,SIGNAL(clicked()),this,SLOT(closebrowsedatawidget()));

    connect(controllmenu->modifystudentdatalabel,SIGNAL(clicked()),this,SLOT(openmodifydatawidget()));
    connect(modifydatawidget->backbutton,SIGNAL(clicked()),this,SLOT(closemodifydatawidget()));
    connect(modifydatawidget,SIGNAL(submitedpicture()),this,SLOT(refreshpicture()));
    connect(modifydatawidget,SIGNAL(submitedname()),this,SLOT(refreshname()));
    connect(modifydatawidget,SIGNAL(submitedgender()),this,SLOT(refreshgender()));
    connect(modifydatawidget,SIGNAL(submitedstudentidentity()),this,SLOT(refreshstudentidentity()));

    connect(controllmenu->browsecourserecordlabel,SIGNAL(clicked()),this,SLOT(openbrowsecourserecordwidget()));
    connect(coursedatawidget->backbutton,SIGNAL(clicked()),this,SLOT(closebrowsecourserecordwidget()));

    mainlayout->addWidget(basicinformationwidget);
    mainlayout->addWidget(controllmenu);
    mainlayout->addWidget(browsedatawidget);
    mainlayout->addWidget(modifydatawidget);
    mainlayout->addWidget(coursedatawidget);
    browsedatawidget->setVisible(false);
    modifydatawidget->setVisible(false);
    coursedatawidget->setVisible(false);
    mainlayout->setAlignment(basicinformationwidget,Qt::AlignTop);
    mainlayout->setAlignment(browsedatawidget,Qt::AlignTop);
    mainlayout->setAlignment(modifydatawidget,Qt::AlignTop);
    mainlayout->setSpacing(30);
    mainlayout->setMargin(30);
    setLayout(mainlayout);
}

void StudentPersonalWindow::setlabelinformation(){
    picturelabel->setFrameShadow(QFrame::Raised);
    picturelabel->setFrameShape(QFrame::Panel);
    if(query.value(6).isNull()){
        img.load("nullperson.jpg");
        img = img.scaledToWidth(250);
        picturelabel->setPixmap(QPixmap::fromImage(img));
    }else{
        QByteArray byteArray;
        byteArray = query.value(6).toByteArray();
        img.loadFromData(byteArray);
        img = img.scaledToWidth(250);
        picturelabel->setPixmap(QPixmap::fromImage(img));
    }
    if(query.value(0).isNull()){
        ticketnumberlabel->setText("尚未填寫");
    }else{
        ticketnumberlabel->setText(query.value(0).toString());
    }
    levellabel->setText(query.value(4).toString());
    studentnumberlabel->setText(studentnumber);
    if(query.value(7).isNull()){
        genderlabel->setText("尚未填寫");
    }else{
        genderlabel->setText(query.value(7).toString());
    }
    if(query.value(5).isNull()){
        namelabel->setText("尚未填寫");
    }else{
        namelabel->setText(query.value(5).toString());
    }
    if(query.value(3).isNull()){
        studentidentitylabel->setText("尚未填寫");
    }else{
        studentidentitylabel->setText(query.value(3).toString());
    }
}
void StudentPersonalWindow::refreshpicture(){
    QSqlQuery refresh;
    refresh.prepare("select picture from student where studentnumber = :studentnumber");
    refresh.bindValue(":studentnumber",studentnumber);
    refresh.exec();
    refresh.next();
    if(refresh.value(0).isNull()){
        img.load("nullperson.jpg");
        img = img.scaledToWidth(250);
        picturelabel->setPixmap(QPixmap::fromImage(img));
    }else{
        QByteArray byteArray;
        byteArray = refresh.value(0).toByteArray();
        img.loadFromData(byteArray);
        img = img.scaledToWidth(250);
        picturelabel->setPixmap(QPixmap::fromImage(img));
    }
}
void StudentPersonalWindow::refreshname(){
    QSqlQuery refresh;
    refresh.prepare("select name from student where studentnumber = :studentnumber");
    refresh.bindValue(":studentnumber",studentnumber);
    refresh.exec();
    refresh.next();
    if(refresh.value(0).isNull()){
        namelabel->setText("尚未填寫");
    }else{
        namelabel->setText(refresh.value(0).toString());
    }
}
void StudentPersonalWindow::refreshgender(){
    QSqlQuery refresh;
    refresh.prepare("select gender from student where studentnumber = :studentnumber");
    refresh.bindValue(":studentnumber",studentnumber);
    refresh.exec();
    refresh.next();
    if(refresh.value(0).isNull()){
        genderlabel->setText("尚未填寫");
    }else{
        genderlabel->setText(refresh.value(0).toString());
    }
}
void StudentPersonalWindow::refreshstudentidentity(){
    QSqlQuery refresh;
    refresh.prepare("select studentidentity from student where studentnumber = :studentnumber");
    refresh.bindValue(":studentnumber",studentnumber);
    refresh.exec();
    refresh.next();
    if(refresh.value(0).isNull()){
        studentidentitylabel->setText("尚未填寫");
    }else{
        studentidentitylabel->setText(refresh.value(0).toString());
    }
}

void StudentPersonalWindow::openbrowsedatawidget(){
    controllmenu->setVisible(false);
    browsedatawidget->setlabelinformation();
    browsedatawidget->setVisible(true);
}
void StudentPersonalWindow::closebrowsedatawidget(){
    browsedatawidget->setVisible(false);
    controllmenu->setVisible(true);
}
void StudentPersonalWindow::openmodifydatawidget(){
    controllmenu->setVisible(false);
    modifydatawidget->setVisible(true);
}
void StudentPersonalWindow::closemodifydatawidget(){
    modifydatawidget->setVisible(false);
    controllmenu->setVisible(true);
}
void StudentPersonalWindow::openbrowsecourserecordwidget(){
    controllmenu->setVisible(false);
    coursedatawidget->setVisible(true);
}
void StudentPersonalWindow::closebrowsecourserecordwidget(){
    coursedatawidget->setVisible(false);
    controllmenu->setVisible(true);
}
