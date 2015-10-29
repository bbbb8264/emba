#include "addanewthesis.h"
#pragma execution_character_set("utf-8")

void AddANewThesis::init(){
    studentinput = new QLineEdit;
    thesisnameinput = new QLineEdit;
    yearinput = new QLineEdit;
    QLineEdit* teacherinput = new QLineEdit;
    setlineeditsize(teacherinput);
    teacherinputvector.push_back(teacherinput);
    addteacherbutton = new QPushButton("新增老師欄位");
    submitbutton = new QPushButton("送出");
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

    mainlayout->addRow("論文學生：",studentinput);
    mainlayout->addRow("題目名稱：",thesisnameinput);
    mainlayout->addRow("學年度：",yearinput);
    mainlayout->addRow("指導老師：",teacherinputvector[0]);
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
