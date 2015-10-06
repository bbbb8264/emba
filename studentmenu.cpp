#include "studentmenu.h"
#include <QGridLayout>
#include <QtWidgets>

StudentMenu::StudentMenu(){
    QLabel* l = new QLabel("學生");
    QFont font = l->font();
    font.setPointSize(30);
    l->setFont(font);
    setMaximumWidth(500);
    l->setMaximumWidth(400);
    QPushButton* a = makeButton("新增單筆資料");
    QPushButton* b = makeButton("查詢單筆修課紀錄");
    QPushButton* c = makeButton("修改單筆資料");
    QPushButton* d = makeButton("刪除單筆資料");
    QPushButton* e = makeButton("");
    QGridLayout* layout = new QGridLayout;
    layout->setSpacing(40);

    layout->setMargin(50);
    layout->addWidget(l,1,1,1,2,Qt::AlignCenter);
    layout->addWidget(a,2,1);
    layout->addWidget(b,2,2);
    layout->addWidget(c,3,1);
    layout->addWidget(d,3,2);
    layout->addWidget(e,4,1);
    setLayout(layout);
}
QPushButton* StudentMenu::makeButton(string text)
{
    QPushButton* a = new QPushButton(tr(text.c_str()));
//    QSizePolicy* size = new QSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
 //   a->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    a->setMinimumWidth(160);
    a->setMaximumWidth(200);
    a->setMinimumHeight(90);
    a->setMaximumHeight(110);
    QFont font = a->font();
    font.setPointSize(10);
    a->setFont(font);
    return a;
}
