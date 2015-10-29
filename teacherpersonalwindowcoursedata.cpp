#include "teacherpersonalwindowcoursedata.h"
#pragma execution_character_set("utf-8")
void TeacherPersonalWindowCourseData::init(){
    mainlayout = new QVBoxLayout;
    backbutton = new QPushButton("返回");
}

TeacherPersonalWindowCourseData::TeacherPersonalWindowCourseData(QString teachernumber){
    init();

    this->teachernumber = teachernumber;
    query.prepare("select count(*) from courseinformation where courseinformation.teachernumber = :teachernumber");
    query.bindValue(":teachernumber",teachernumber);
    query.exec();
    query.next();
    if(query.value(0).toInt()){
        QLabel* title = new QLabel("以下為你曾經開過的課程");
        title->setStyleSheet("font-size:24px;font-family:Microsoft JhengHei");
        QSqlQueryModel* model = new QSqlQueryModel;
        model->setQuery("select coursenumber, coursetypename, coursename , year , semester , credit from courseinformation,coursetype where courseinformation.teachernumber = '"+teachernumber+"' and coursetype.coursetypenumber = courseinformation.coursetype");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("課程編號"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("課程類型"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("課程名稱"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("學年度"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("學期"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("學分數"));
        QTableView* tableview = new QTableView;
        tableview->setModel(model);
        QHeaderView* headerview = tableview->horizontalHeader();
        headerview->setSectionResizeMode(QHeaderView::Stretch);
        headerview->setStyleSheet("QHeaderView::section {font-family:Microsoft JhengHei;background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #00FF92, stop: 0.8 #00DA8A, stop:1 #00F18A);color: white;padding-left: 4px;border: 1px solid #87CECB;}");
        headerview->setMinimumHeight(30);
        tableview->verticalHeader()->setStyleSheet("QHeaderView::section {background-color: #808080;color: white;padding-left: 4px;}");
        tableview->setStyleSheet("background-color:#fEfefe;font-size:12px;font-family:Microsoft JhengHei");
        tableview->setMinimumWidth(750);
        tableview->setMinimumHeight(350);

        mainlayout->addWidget(title);
        mainlayout->addWidget(tableview);
        mainlayout->setAlignment(title,Qt::AlignCenter);
        mainlayout->setMargin(30);
        mainlayout->setSpacing(30);
        setMaximumWidth(800);
    }else{
        QLabel* title = new QLabel("你目前還沒有開任何課程");
        title->setStyleSheet("font-size:30px;font-family:Microsoft JhengHei");
        title->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
        title->setMinimumHeight(200);
        title->setAlignment(Qt::AlignCenter);
        mainlayout->setAlignment(title,Qt::AlignHCenter);
        mainlayout->addWidget(title);
        mainlayout->setMargin(50);
        setMaximumWidth(800);
    }
    mainlayout->addWidget(backbutton);
    backbutton->setStyleSheet("font-size:18px;");
    backbutton->setMinimumHeight(40);
    backbutton->setMinimumWidth(150);
    mainlayout->setAlignment(backbutton,Qt::AlignHCenter);
    setStyleSheet("background-color:#fbfbfb;font-size:12px;font-family:Microsoft JhengHei");
    //setStyleSheet("border: 1px solid black");
    setLayout(mainlayout);
    setFrameShape(QFrame::Panel);
    setFrameShadow(QFrame::Raised);
}
