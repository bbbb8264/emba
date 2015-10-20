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
    backbutton = new QPushButton("返回");
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

    /*mainlayout->addRow("所在地區：",locationlabel);
    mainlayout->addRow("通訊地址：",addresslabel);
    mainlayout->addRow("電子郵件：",emaillabel);
    mainlayout->addRow("生日：",birthdaylabel);
    mainlayout->addRow("電話(日)：",telephonedaylabel);
    mainlayout->addRow("電話(夜)：",telephonenightlabel);
    mainlayout->addRow("手機電話：",mobilelabel);
    mainlayout->addRow("畢業學校：",graduatedschoollabel);
    mainlayout->addRow("畢業科系：",graduateddepartmentlabel);
    mainlayout->addRow("公司名稱",companynamelabel);
    mainlayout->addRow("職位：",companycurrentpositionlabel);
    mainlayout->setSpacing(15);
    mainlayout->setAlignment(Qt::AlignCenter);
    mainlayout->setFormAlignment(Qt::AlignHCenter);
    mainlayout->setMargin(30);*/

    formlayout1->addRow("所在地區：",locationlabel);
    formlayout1->addRow("通訊地址：",addresslabel);
    formlayout1->addRow("電子郵件：",emaillabel);
    formlayout1->addRow("生日：",birthdaylabel);
    formlayout1->addRow("電話(日)：",telephonedaylabel);
    formlayout1->addRow("電話(夜)：",telephonenightlabel);
    formlayout1->setSpacing(30);
    formwidget1->setLayout(formlayout1);
    formwidget1->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);

    formlayout2->addRow("手機電話：",mobilelabel);
    formlayout2->addRow("畢業學校：",graduatedschoollabel);
    formlayout2->addRow("畢業科系：",graduateddepartmentlabel);
    formlayout2->addRow("公司名稱：",companynamelabel);
    formlayout2->addRow("職位：",companycurrentpositionlabel);
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
        locationlabel->setText("尚未填寫");
    }else{
        locationlabel->setText(query.value(2).toString());
    }
    if(query.value(8).isNull()){
        addresslabel->setText("尚未填寫");
    }else{
        addresslabel->setText(query.value(8).toString());
    }
    if(query.value(9).isNull()){
        emaillabel->setText("尚未填寫");
    }else{
        emaillabel->setText(query.value(9).toString());
    }
    if(query.value(10).isNull()){
        birthdaylabel->setText("尚未填寫");
    }else{
        birthdaylabel->setText(query.value(10).toString());
    }
    if(query.value(11).isNull()){
        telephonedaylabel->setText("尚未填寫");
    }else{
        telephonedaylabel->setText(query.value(11).toString());
    }
    if(query.value(12).isNull()){
        telephonenightlabel->setText("尚未填寫");
    }else{
        telephonenightlabel->setText(query.value(12).toString());
    }
    if(query.value(13).isNull()){
        mobilelabel->setText("尚未填寫");
    }else{
        mobilelabel->setText(query.value(13).toString());
    }
    if(query.value(14).isNull()){
        graduatedschoollabel->setText("尚未填寫");
    }else{
        graduatedschoollabel->setText(query.value(14).toString());
    }
    if(query.value(15).isNull()){
        graduateddepartmentlabel->setText("尚未填寫");
    }else{
        graduateddepartmentlabel->setText(query.value(15).toString());
    }
    if(query.value(16).isNull()){
        companynamelabel->setText("尚未填寫");
    }else{
        companynamelabel->setText(query.value(16).toString());
    }
    if(query.value(17).isNull()){
        companycurrentpositionlabel->setText("尚未填寫");
    }else{
        companycurrentpositionlabel->setText(query.value(17).toString());
    }
}
