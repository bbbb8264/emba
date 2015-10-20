#include "studentpersonalwindowmenu.h"
#include "studentpersonalwindowmenubutton.h"
#pragma execution_character_set("utf-8")
void StudentPersonalWindowMenu::init(){
    browsestudentdatalabel = new StudentPersonalWindowMenuButton;
    modifystudentdatalabel = new StudentPersonalWindowMenuButton;
    browsecourserecordlabel = new StudentPersonalWindowMenuButton;
    browsethesisrecordlabel = new StudentPersonalWindowMenuButton;
    backlabel = new StudentPersonalWindowMenuButton;
    mainlayout = new QFormLayout;
}

StudentPersonalWindowMenu::StudentPersonalWindowMenu(){
    init();

    browsestudentdatalabel->setText("�d�ݾǥ͸��");
    modifystudentdatalabel->setText("�ק�ǥ͸��");
    browsecourserecordlabel->setText("�d�ݾǥͭ׽Ҭ���");
    browsethesisrecordlabel->setText("�d�ݾǥͽפ����");
    backlabel->setText("��^�j�M�ǥ�");

    setlabelattribute(browsestudentdatalabel);
    setlabelattribute(modifystudentdatalabel);
    setlabelattribute(browsecourserecordlabel);
    setlabelattribute(browsethesisrecordlabel);
    setlabelattribute(backlabel);

    mainlayout->addRow(browsestudentdatalabel);
    mainlayout->addRow(modifystudentdatalabel);
    mainlayout->addRow(browsecourserecordlabel);
    mainlayout->addRow(browsethesisrecordlabel);
    mainlayout->addRow(backlabel);

    mainlayout->setSpacing(30);
    mainlayout->setMargin(0);

    setLayout(mainlayout);
}

void StudentPersonalWindowMenu::setlabelattribute(QLabel* label){
    label->setFrameShadow(QFrame::Raised);
    label->setFrameShape(QFrame::Panel);
    label->setAlignment(Qt::AlignCenter);
    label->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
    label->setMinimumWidth(500);
    label->setMinimumHeight(80);
    label->setStyleSheet("background-color:#fbfbfb;font-size:25px;font-family:Microsoft JhengHei");
}
