#include "studentpersonalwindowbrowsedata.h"
#pragma execution_character_set("utf-8")
void StudentPersonalWindowBrowseData::init(){
    locationlabel = new QLabel;
    addresslabel = new QLabel;
    emaillabel = new QLabel;
    birthdaylabel = new QLabel;
    telephonedaylabel = new QLabel;
    telephonenightlabel = new QLabel;
    mobilelabel = new QLabel;
    graduatedschoollabel = new QLabel;
    graduateddepartmentlabel = new QLabel;
    companynamelabel = new QLabel;
    companycurrentpositionlabel = new QLabel;
    mainlayout = new QVBoxLayout;
    uplayout = new QHBoxLayout;
    upwidget = new QWidget;
    formlayout1 = new QFormLayout;
    formwidget1 = new QWidget;
    formlayout2 = new QFormLayout;
    formwidget2 = new QWidget;
    backbutton = new QPushButton("��^");
}
StudentPersonalWindowBrowseData::StudentPersonalWindowBrowseData(QString studentnumber){
    setStyleSheet("border: 1px solid black");
    this->studentnumber = studentnumber;

    init();

    setlabelinformation();

    locationlabel->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);
    addresslabel->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);
    emaillabel->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);
    birthdaylabel->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);
    telephonedaylabel->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);
    telephonenightlabel->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);
    mobilelabel->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);
    graduatedschoollabel->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);
    graduateddepartmentlabel->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);
    companynamelabel->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);
    companycurrentpositionlabel->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);

    /*mainlayout->addRow("�Ҧb�a�ϡG",locationlabel);
    mainlayout->addRow("�q�T�a�}�G",addresslabel);
    mainlayout->addRow("�q�l�l��G",emaillabel);
    mainlayout->addRow("�ͤ�G",birthdaylabel);
    mainlayout->addRow("�q��(��)�G",telephonedaylabel);
    mainlayout->addRow("�q��(�])�G",telephonenightlabel);
    mainlayout->addRow("����q�ܡG",mobilelabel);
    mainlayout->addRow("���~�ǮաG",graduatedschoollabel);
    mainlayout->addRow("���~��t�G",graduateddepartmentlabel);
    mainlayout->addRow("���q�W��",companynamelabel);
    mainlayout->addRow("¾��G",companycurrentpositionlabel);
    mainlayout->setSpacing(15);
    mainlayout->setAlignment(Qt::AlignCenter);
    mainlayout->setFormAlignment(Qt::AlignHCenter);
    mainlayout->setMargin(30);*/

    formlayout1->addRow("�Ҧb�a�ϡG",locationlabel);
    formlayout1->addRow("�q�T�a�}�G",addresslabel);
    formlayout1->addRow("�q�l�l��G",emaillabel);
    formlayout1->addRow("�ͤ�G",birthdaylabel);
    formlayout1->addRow("�q��(��)�G",telephonedaylabel);
    formlayout1->addRow("�q��(�])�G",telephonenightlabel);
    formlayout1->setSpacing(30);
    formwidget1->setLayout(formlayout1);
    formwidget1->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);

    formlayout2->addRow("����q�ܡG",mobilelabel);
    formlayout2->addRow("���~�ǮաG",graduatedschoollabel);
    formlayout2->addRow("���~��t�G",graduateddepartmentlabel);
    formlayout2->addRow("���q�W�١G",companynamelabel);
    formlayout2->addRow("¾��G",companycurrentpositionlabel);
    formlayout2->setSpacing(30);
    formwidget2->setLayout(formlayout2);
    formwidget2->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);

    uplayout->addWidget(formwidget1);
    uplayout->addWidget(formwidget2);
    uplayout->setSpacing(30);
    uplayout->setAlignment(formwidget2,Qt::AlignTop);
    uplayout->setAlignment(formwidget1,Qt::AlignTop);
    upwidget->setLayout(uplayout);
    upwidget->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);

    backbutton->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);
    backbutton->setMinimumHeight(30);
    backbutton->setMinimumWidth(120);

    mainlayout->addWidget(upwidget);
    mainlayout->addWidget(backbutton);
    mainlayout->setAlignment(upwidget,Qt::AlignHCenter);
    mainlayout->setAlignment(backbutton,Qt::AlignHCenter);

    setMinimumWidth(800);
    setMinimumHeight(500);
    setFrameShape(QFrame::Panel);
    setFrameShadow(QFrame::Raised);
    setStyleSheet("background-color:#fbfbfb;font-size:25px;font-family:Microsoft JhengHei");
    setLayout(mainlayout);
    setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Minimum);
}
void StudentPersonalWindowBrowseData::setlabelinformation(){
    query.prepare( "select * from student where studentnumber = :studentnumber" );
    query.bindValue(":studentnumber",studentnumber);
    query.exec();
    query.next();
    if(query.value(2).isNull()){
        locationlabel->setText("�|����g");
    }else{
        locationlabel->setText(query.value(2).toString());
    }
    if(query.value(8).isNull()){
        addresslabel->setText("�|����g");
    }else{
        addresslabel->setText(query.value(8).toString());
    }
    if(query.value(9).isNull()){
        emaillabel->setText("�|����g");
    }else{
        emaillabel->setText(query.value(9).toString());
    }
    if(query.value(10).isNull()){
        birthdaylabel->setText("�|����g");
    }else{
        birthdaylabel->setText(query.value(10).toString());
    }
    if(query.value(11).isNull()){
        telephonedaylabel->setText("�|����g");
    }else{
        telephonedaylabel->setText(query.value(11).toString());
    }
    if(query.value(12).isNull()){
        telephonenightlabel->setText("�|����g");
    }else{
        telephonenightlabel->setText(query.value(12).toString());
    }
    if(query.value(13).isNull()){
        mobilelabel->setText("�|����g");
    }else{
        mobilelabel->setText(query.value(13).toString());
    }
    if(query.value(14).isNull()){
        graduatedschoollabel->setText("�|����g");
    }else{
        graduatedschoollabel->setText(query.value(14).toString());
    }
    if(query.value(15).isNull()){
        graduateddepartmentlabel->setText("�|����g");
    }else{
        graduateddepartmentlabel->setText(query.value(15).toString());
    }
    if(query.value(16).isNull()){
        companynamelabel->setText("�|����g");
    }else{
        companynamelabel->setText(query.value(16).toString());
    }
    if(query.value(17).isNull()){
        companycurrentpositionlabel->setText("�|����g");
    }else{
        companycurrentpositionlabel->setText(query.value(17).toString());
    }
}
