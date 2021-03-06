﻿#include "addstudenttocourse.h"
#include "conditionset.h"
#include "conditionwidget.h"
#include "deletebutton.h"
#include "checkboxidentitymodel.h"
#include "mysqlrelationaltablemodel.h"
#include "choosestudenttocoursecoursemodel.h"
#include "checkbox_delegate.h"
#include <qsqlrelationaltablemodel.h>
#pragma execution_character_set("utf-8")
void AddStudentToCourse::init()
{
    mainlayout = new QHBoxLayout;
    conditionwidget = new QFrame;
    conditionlayout = new QVBoxLayout;
    conditionsettingwidget = new QFrame;
    conditionsettinglayout = new QHBoxLayout;
    conditionsetting = new QComboBox;
    conditionsettingexpression = new QLineEdit;
    conditionshowwidget = new QFrame;
    conditionshowlayout = new QVBoxLayout;
    conditionlast = NULL;
    resultwidget = new QWidget;
    resultlayout = new QVBoxLayout;
    resultaddwidget = new QWidget;
    resultaddlayout = new QHBoxLayout;
    resultshowwidget = new QWidget;
    proxy = new CheckBoxIdentityModel(5);
    controllwidget = new QWidget;
    controlllayout = new QHBoxLayout;
    submitbutton = new QPushButton("下一步");
    uncheckallbutton = new QPushButton("全部取消");
    selectallbutton = new QPushButton("全部選取");
}
AddStudentToCourse::AddStudentToCourse()
{
    //setStyleSheet("border: 1px solid black");
    init();
    setfont();
    conditions << "課程名稱" << "指導老師姓名" << "學年度";
    conditionsetting->setMinimumWidth(150);
    conditionsetting->addItems(conditions);
    conditionsettinglayout->addWidget(conditionsetting);
    conditionsettinglayout->addWidget(conditionsettingexpression);
    connect(conditionsettingexpression,SIGNAL(returnPressed()),this,SLOT(addacondition()));
    conditionsettingwidget->setFrameShape(QFrame::StyledPanel);
    conditionsettingwidget->setLayout(conditionsettinglayout);
    conditionsettingwidget->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);

    conditionshowlayout->setAlignment(Qt::AlignTop);
    conditionshowwidget->setFrameShape(QFrame::StyledPanel);
    conditionshowwidget->setMaximumWidth(326);
    conditionshowwidget->setLayout(conditionshowlayout);

    conditionlayout->addWidget(conditionsettingwidget);
    conditionlayout->addWidget(conditionshowwidget);
    conditionwidget->setLayout(conditionlayout);

    //resultlayout->addWidget(resultaddwidget);

    model = new ChooseStudentToCourseCourseModel;
    model->setQuery("select year,semester,coursename,teachername,coursenumber from teacher,courseinformation where courseinformation.teachernumber = teacher.teachernumber");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("學年"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("學期"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("課程名稱"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("老師名稱"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("勾選欄"));
    proxy->setSourceModel(model);
    tableview = new QTableView;
    QHeaderView* headerview = tableview->horizontalHeader();
    headerview->setSectionResizeMode(QHeaderView::Stretch);
    headerview->setStyleSheet("QHeaderView::section {background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #00FFFF, stop: 0.8 #40E0D0, stop:1 #87CECB);color: white;padding-left: 4px;border: 1px solid #87CECB;}");
    headerview->setMinimumHeight(30);
    QHeaderView* headerview2 =tableview->verticalHeader();
    headerview2->setStyleSheet("QHeaderView::section {background-color: #808080;color: white;padding-left: 4px;}");
    tableview->setHorizontalHeader(headerview);
    tableview->setVerticalHeader(headerview2);
    tableview->setModel(proxy);
    tableview->setColumnHidden(4,true);
    tableview->setMinimumWidth(500);
    tableview->setMinimumHeight(300);
    CheckBoxDelegate* delegate = new CheckBoxDelegate;
    tableview->setItemDelegateForColumn(5,delegate);
    //connect(tableview,SIGNAL(clicked(const QModelIndex &)),proxy,SLOT(setcheck(const QModelIndex &)));
    tableview->setFrameShape(QFrame::StyledPanel);

    submitbutton->setFixedWidth(100);
    submitbutton->setFixedHeight(25);
    connect(submitbutton,SIGNAL(clicked()),this,SLOT(nextstep()));
    selectallbutton->setFixedWidth(100);
    selectallbutton->setFixedHeight(25);
    connect(selectallbutton,SIGNAL(clicked()),this,SLOT(selectall()));
    uncheckallbutton->setFixedWidth(100);
    uncheckallbutton->setFixedHeight(25);
    connect(uncheckallbutton,SIGNAL(clicked()),this,SLOT(uncheckall()));

    controlllayout->addWidget(selectallbutton);
    controlllayout->addWidget(uncheckallbutton);
    controlllayout->addWidget(submitbutton);
    controllwidget->setLayout(controlllayout);
    resultlayout->addWidget(tableview);
    resultlayout->addWidget(controllwidget);
    resultwidget->setLayout(resultlayout);

    mainlayout->addWidget(conditionwidget);
    mainlayout->addWidget(resultwidget);
    setLayout(mainlayout);
}
void AddStudentToCourse::addacondition()
{
    conditionset* temp;
    if(makecondition(temp)){
        makefilter(temp);
        addtolinkedlist(temp);
        scanconditionset();
        qDebug() << maketotalfilter();
        model->setQuery(maketotalfilter());
        proxy->resetcheckstate(proxy->rowCount());
        setcondition(temp);
    }
}

void AddStudentToCourse::setfont()
{
    QFont font;
    font.setPixelSize(15);
    font.setFamily("微軟正黑體");
    conditionwidget->setFont(font);
}

void AddStudentToCourse::setcondition(conditionset* currentconditionset)
{
    currentconditionset->condition = new ConditionWidget(currentconditionset);
    conditionshowlayout->addWidget(currentconditionset->condition);
    connect(currentconditionset->condition->closebutton,SIGNAL(click(conditionset*&)),this,SLOT(deleteacondition(conditionset*&)));
}

bool AddStudentToCourse::makecondition(conditionset*& temp)
{
    temp = new conditionset;
    temp->target = conditionsetting->currentText();
    temp->expression = conditionsettingexpression->text();
    temp->expression.remove(QChar(' '), Qt::CaseInsensitive);
    if(temp->expression.isEmpty())
    {
        QMessageBox msg(QMessageBox::Warning,"提示","你沒有輸入任何資料");
        msg.layout()->setMargin(15);
        msg.layout()->setSpacing(10);
        msg.exec();
        return false;
    }
    if(temp->expression.at(0) == '>' || temp->expression.at(0) == '<'){
        temp->operate += temp->expression.at(0);
        temp->expression.remove(0,1);
        if(temp->expression.isEmpty())
        {
            QMessageBox msg(QMessageBox::Warning,"提示","缺少比較用的資料");
            msg.layout()->setMargin(15);
            msg.layout()->setSpacing(10);
            msg.exec();
            return false;
        }
        if(temp->expression.at(0) == '='){
            temp->operate += "=";
            temp->expression.remove(0,1);
            if(temp->expression.isEmpty())
            {
                QMessageBox msg(QMessageBox::Warning,"提示","缺少比較用的資料");
                msg.layout()->setMargin(15);
                msg.layout()->setSpacing(10);
                msg.exec();
                return false;
            }
        }
        if(temp->expression != 0)
            if(temp->expression.toInt() == 0)
            {
                QMessageBox msg(QMessageBox::Warning,"提示","你輸入的不是數字");
                msg.layout()->setMargin(15);
                msg.layout()->setSpacing(10);
                msg.exec();
                return false;
            }
    }
    else if(temp->expression.at(0) == '='){
        temp->operate += "=";
        temp->expression.remove(0,1);
    }
    else{
        temp->operate += "=";
    }
    return true;
}

void AddStudentToCourse::makefilter(conditionset *temp)
{
    if(temp->target == "課程名稱"){
        if(temp->operate == "=" || temp->operate == "look like"){
            temp->filter = "courseinformation.coursename LIKE '%" + temp->expression +"%'";
            temp->operate = "look like";
        }else{
            temp->filter = "studentnumber " + temp->operate + " '" + temp->expression +"'";
        }
    }else if(temp->target == "指導老師姓名"){
        temp->filter = "teacher.teachername " + temp->operate + " '" + temp->expression + "'";
    }else if(temp->target == "學年度"){
        temp->filter = "courseinformation.year " + temp->operate + " '" + temp->expression + "'";
    }
}

void AddStudentToCourse::addtolinkedlist(conditionset *temp)
{
    if(addatmiddle(temp))
    {}else
    {
        addatlast(temp);
    }
}

void AddStudentToCourse::addatlast(conditionset *temp)
{
    if(conditionlast != NULL)
    {
        conditionlast->next = temp;
        temp->pre = conditionlast;
        conditionlast = temp;
        conditionlast->next = NULL;
    }else{
        conditionlast = temp;
        conditionlast->next = NULL;
        conditionlast->pre = NULL;
    }
}
bool AddStudentToCourse::addatmiddle(conditionset *temp)
{
    conditionset* temp2 = conditionlast;
    while(temp2 != NULL && temp2->target != temp->target)
    {
        temp2 = temp2->pre;
    }
    if(temp2 == NULL)
    {
        return false;
    }
    else
    {
        if(temp->operate == "=")
        {
            conditionset* temp3 = temp2->next;
            temp2->next = temp;
            if(temp3 != NULL)
                temp3->pre = temp;
            temp->next = temp3;
            temp->pre = temp2;
            if(temp->next == NULL)
                conditionlast = temp;
            return true;
        }
        else
        {
            while(temp2->pre != NULL && temp2->pre->target == temp->target){
                temp2 = temp2->pre;
            }
            if(temp2->pre != NULL)
                temp2->pre->next = temp;
            temp->pre = temp2->pre;
            temp2->pre = temp;
            temp->next = temp2;
            return true;
        }
    }
}

QString AddStudentToCourse::maketotalfilter()
{
    conditionset* temp = conditionlast;
    QString filter;
    bool first = true;
    while(temp != NULL)
    {
        QString nowtarget = temp->target;
        bool multiequal = false;
        if(temp->operate == "=")
        {
            if(first){
                first = false;
            }else{
                filter += " and ";
            }
        }
        if(temp->operate == "=" && temp->pre != NULL && temp->pre->operate == "=")
        {
            filter += "(";
            multiequal = true;
        }
        bool equalfirst = true;
        while(temp != NULL && temp->operate == "=" && temp->target == nowtarget)
        {
            if(equalfirst){
                equalfirst = false;
            }else{
                filter += " or ";
            }
            filter += "(" + temp->filter + ")";
            temp = temp->pre;
        }
        if(multiequal)
        {
            filter += ")";
        }
        while(temp != NULL && temp->operate != "=" && temp->target == nowtarget)
        {
            if(first){
                first = false;
            }else{
                filter += " and ";
            }
            filter += "(" + temp->filter + ")";
            temp = temp->pre;
        }
    }
    if(filter.isEmpty()){
        return "select year,semester,coursename,teachername from teacher,courseinformation where courseinformation.teachernumber = teacher.teachernumber";
    }else{
        return "select year,semester,coursename,teachername from teacher,courseinformation where courseinformation.teachernumber = teacher.teachernumber and " + filter;
    }
}

void AddStudentToCourse::scanconditionset()
{
    conditionset* temp = conditionlast;
    qDebug() << "scan start";
    while(temp != NULL)
    {
        qDebug() << "target: " << temp->target;
        qDebug() << "operate: " << temp->operate;
        qDebug() << "expression: " << temp->expression;
        qDebug() << "filter: " << temp->filter;
        qDebug() << "";
        temp = temp->pre;
    }
    qDebug() << "scan finish";
}

void AddStudentToCourse::deleteacondition(conditionset*& con)
{
    conditionset* temp = con;
    if(conditionlast == con)
    {
        conditionlast = conditionlast->pre;
    }
    if(con->pre != NULL)
        con->pre->next = con->next;
    if(con->next != NULL)
        con->next->pre = con->pre;
    con = NULL;
    temp->condition->setVisible(false);
    delete temp->condition;
    delete temp;
    model->setQuery(maketotalfilter());
    proxy->resetcheckstate(proxy->rowCount());
}
void AddStudentToCourse::nextstep(){
    QStringList courselist;
    QStringList coursename;
    for(int i = 0;i < proxy->rowCount();i++){
        QModelIndex index = proxy->index(i,5);
        if(proxy->data(index,Qt::CheckStateRole).toBool()){
            courselist.push_back(proxy->data(proxy->index(i,4)).toString());
            coursename.push_back(proxy->data(proxy->index(i,2)).toString());
        }
    }
    qDebug() << QString::number(courselist.size());
    for(int i = 0;i < courselist.size();i++){
        qDebug() << courselist.at(i);
    }
    if(courselist.length() > 0){
        emit submit(courselist,coursename);
    }else{
        QMessageBox msg;
        msg.layout()->setMargin(20);
        msg.layout()->setSpacing(10);
        QFont font;
        font.setFamily("微軟正黑體");
        font.setPixelSize(15);
        msg.setFont(font);
        QImage icon;
        icon.load("error.png");
        icon = icon.scaledToWidth(50);
        msg.setWindowTitle("錯誤");
        msg.setIconPixmap(QPixmap::fromImage(icon));
        msg.setText("選擇的課程至少要有一項");
        msg.exec();
    }
}
void AddStudentToCourse::selectall(){
    proxy->selectall();
    tableview->viewport()->repaint();
}
void AddStudentToCourse::uncheckall(){
    proxy->uncheckall();
    tableview->viewport()->repaint();
}
