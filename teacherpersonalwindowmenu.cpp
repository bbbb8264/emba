#include "teacherpersonalwindowmenu.h"
#include "personalwindowmenubutton.h"
#pragma execution_character_set("utf-8")
void TeacherPersonalWindowMenu::init(){
    modifyteacherdatalabel = new PersonalWindowMenuButton;
    browsecourserecordlabel = new PersonalWindowMenuButton;
    browsethesisrecordlabel = new PersonalWindowMenuButton;
    backlabel = new PersonalWindowMenuButton;
    mainlayout = new QFormLayout;
}

TeacherPersonalWindowMenu::TeacherPersonalWindowMenu(){
    init();

    modifyteacherdatalabel->setText("修改老師資料");
    browsecourserecordlabel->setText("查看開課紀錄");
    browsethesisrecordlabel->setText("查看論文指導紀錄");
    backlabel->setText("返回搜尋老師");

    setlabelattribute(modifyteacherdatalabel);
    setlabelattribute(browsecourserecordlabel);
    setlabelattribute(browsethesisrecordlabel);
    setlabelattribute(backlabel);

    mainlayout->addRow(modifyteacherdatalabel);
    mainlayout->addRow(browsecourserecordlabel);
    mainlayout->addRow(browsethesisrecordlabel);
    mainlayout->addRow(backlabel);

    mainlayout->setSpacing(30);
    mainlayout->setMargin(0);

    setLayout(mainlayout);
}

void TeacherPersonalWindowMenu::setlabelattribute(QLabel* label){
    label->setFrameShadow(QFrame::Raised);
    label->setFrameShape(QFrame::Panel);
    label->setAlignment(Qt::AlignCenter);
    label->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
    label->setMinimumWidth(500);
    label->setMinimumHeight(80);
    label->setStyleSheet("background-color:#fbfbfb;font-size:25px;font-family:Microsoft JhengHei");
}

