#include "addanewthesis.h"
#pragma execution_character_set("utf-8")

void AddANewThesis::init(){
    studentinput = new QLineEdit;
    thesisnameinput = new QLineEdit;
    yearinput = new QLineEdit;
    QLineEdit* teacherinput = new QLineEdit;
    setlineeditsize(teacherinput);
    teacherinputvector.push_back(teacherinput);
    addteacherbutton = new QPushButton("�s�W�Ѯv���");
    submitbutton = new QPushButton("�e�X");
    mainlayout = new QFormLayout;
}
AddANewThesis::AddANewThesis(){
    init();

    setlineeditsize(studentinput);
    setlineeditsize(thesisnameinput);
    setlineeditsize(yearinput);
    addteacherbutton->setFixedHeight(40);
    addteacherbutton->setFixedWidth(150);
    submitbutton->setFixedHeight(50);
    submitbutton->setFixedWidth(250);

    mainlayout->addRow("�פ�ǥ͡G",studentinput);
    mainlayout->addRow("�D�ئW�١G",thesisnameinput);
    mainlayout->addRow("�Ǧ~�סG",yearinput);
    mainlayout->addRow("���ɦѮv�G",teacherinputvector[0]);
    mainlayout->addRow(addteacherbutton);
    mainlayout->addRow(submitbutton);
    mainlayout->setAlignment(addteacherbutton,Qt::AlignHCenter);
    mainlayout->setAlignment(submitbutton,Qt::AlignHCenter);
    mainlayout->setSpacing(50);
    mainlayout->setMargin(50);

    setLayout(mainlayout);
    setFrameShape(QFrame::Panel);
    setFrameShadow(QFrame::Raised);
    setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);
    setStyleSheet("background-color:#fbfbfb;font-size:23px;font-family:Microsoft JhengHei");
}
void AddANewThesis::setlineeditsize(QLineEdit *lineedit){
    lineedit->setMinimumWidth(350);
    lineedit->setMaximumWidth(500);
    lineedit->setStyleSheet("background-color:#ffffff;font-size:23px;font-family:Microsoft JhengHei");
}
