#include "searchteacher.h"
#include "conditionset.h"
#include "conditionwidget.h"
#include "deletebutton.h"
#pragma execution_character_set("utf-8")
void SearchTeacher::init()
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
}
SearchTeacher::SearchTeacher()
{
    //setStyleSheet("border: 1px solid black");
    init();
    setfont();
    msg.layout()->setMargin(50);
    msg.layout()->setSpacing(20);
    QFont font;
    font.setFamily("�L�n������");
    font.setPixelSize(15);
    msg.setFont(font);

    conditions << "��¾���s��" << "�m�W" << "���ݨt��" << "����(�q��)" << "�q�l�l��";
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

    model = new QSqlQueryModel;
    model->setQuery("select teachernumber, teachername, departmentname, email, phone from teacher,department where teacher.departmentnumber = department.departmentnumber");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("��¾���s��"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("�m�W"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("���ݨt��"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("�q�l�l��"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("����(�q��)"));
    tableview = new QTableView;
    QHeaderView* headerview = tableview->horizontalHeader();
    headerview->setSectionResizeMode(QHeaderView::Stretch);
    headerview->setStyleSheet("QHeaderView::section {background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #00FFFF, stop: 0.8 #40E0D0, stop:1 #87CECB);color: white;padding-left: 4px;border: 1px solid #87CECB;}");
    headerview->setMinimumHeight(30);
    QHeaderView* headerview2 =tableview->verticalHeader();
    headerview2->setStyleSheet("QHeaderView::section {background-color: #808080;color: white;padding-left: 4px;}");
    tableview->setHorizontalHeader(headerview);
    tableview->setVerticalHeader(headerview2);
    tableview->setModel(model);
    tableview->setMinimumWidth(500);
    tableview->setMinimumHeight(300);
    //connect(tableview,SIGNAL(clicked(const QModelIndex &)),proxy,SLOT(setcheck(const QModelIndex &)));
    tableview->setFrameShape(QFrame::StyledPanel);

    resultlayout->addWidget(tableview);
    resultwidget->setLayout(resultlayout);

    mainlayout->addWidget(conditionwidget);
    mainlayout->addWidget(resultwidget);
    setLayout(mainlayout);
}
void SearchTeacher::addacondition()
{
    conditionset* temp;
    if(makecondition(temp)){
        makefilter(temp);
        addtolinkedlist(temp);
        scanconditionset();
        qDebug() << "before make";
        qDebug() << maketotalfilter();
        model->setQuery(maketotalfilter());
        setcondition(temp);
    }
}

void SearchTeacher::setfont()
{
    QFont font;
    font.setPixelSize(15);
    font.setFamily("�L�n������");
    conditionwidget->setFont(font);
}

void SearchTeacher::setcondition(conditionset* currentconditionset)
{
    currentconditionset->condition = new ConditionWidget(currentconditionset);
    conditionshowlayout->addWidget(currentconditionset->condition);
    connect(currentconditionset->condition->closebutton,SIGNAL(click(conditionset*&)),this,SLOT(deleteacondition(conditionset*&)));
}

bool SearchTeacher::makecondition(conditionset*& temp)
{
    temp = new conditionset;
    temp->target = conditionsetting->currentText();
    temp->expression = conditionsettingexpression->text();
    temp->expression.remove(QChar(' '), Qt::CaseInsensitive);
    if(temp->expression.isEmpty())
    {
        QMessageBox msg(QMessageBox::Warning,"����","�A�S����J������");
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
            QMessageBox msg(QMessageBox::Warning,"����","�ʤ֤���Ϊ����");
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
                QMessageBox msg(QMessageBox::Warning,"����","�ʤ֤���Ϊ����");
                msg.layout()->setMargin(15);
                msg.layout()->setSpacing(10);
                msg.exec();
                return false;
            }
        }
        if(temp->expression != 0)
            if(temp->expression.toInt() == 0)
            {
                QMessageBox msg(QMessageBox::Warning,"����","�A��J�����O�Ʀr");
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

void SearchTeacher::makefilter(conditionset *temp)
{
    if(temp->target == "��¾���s��"){
        if(temp->operate == "=" || temp->operate == "look like"){
            temp->filter = "teachernumber LIKE '%" + temp->expression +"%'";
            temp->operate = "look like";
        }else{
            temp->filter = "teachernumber " + temp->operate + " '" + temp->expression +"'";
        }
    }else if(temp->target == "�m�W"){
        if(temp->operate == "=" || temp->operate == "look like"){
            temp->filter = "teachername LIKE '%" + temp->expression +"%'";
            temp->operate = "look like";
        }else{
            temp->filter = "teachername " + temp->operate + " '" + temp->expression +"'";
        }
    }else if(temp->target == "���ݨt��"){
        if(temp->operate == "=" || temp->operate == "look like"){
            temp->filter = "department.departmentnumber LIKE '%"+temp->expression+"%' or departmentname LIKE '%" + temp->expression +"%'";
            temp->operate = "look like";
        }else{
            temp->filter = "department.departmentnumber "+temp->operate+" '%"+temp->expression+"%' or departmentname "+temp->operate+" '%" + temp->expression +"%'";
        }
    }else if(temp->target == "����(�q��)"){
        if(temp->operate == "=" || temp->operate == "look like"){
            temp->filter = "phone LIKE '%" + temp->expression +"%'";
            temp->operate = "look like";
        }else{
            temp->filter = "phone " + temp->operate + " '" + temp->expression +"'";
        }
    }else if(temp->target == "�q�l�l��"){
        if(temp->operate == "=" || temp->operate == "look like"){
            temp->filter = "email LIKE '%" + temp->expression +"%'";
            temp->operate = "look like";
        }else{
            temp->filter = "email " + temp->operate + " '" + temp->expression +"'";
        }
    }
}

void SearchTeacher::addtolinkedlist(conditionset *temp)
{
    if(addatmiddle(temp))
    {}else
    {
        addatlast(temp);
    }
}

void SearchTeacher::addatlast(conditionset *temp)
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
bool SearchTeacher::addatmiddle(conditionset *temp)
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

QString SearchTeacher::maketotalfilter()
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
        return "select teachernumber, teachername, departmentname, email, phone from teacher,department where teacher.departmentnumber = department.departmentnumber";
    }else{
        return "select teachernumber, teachername, departmentname, email, phone from teacher,department where teacher.departmentnumber = department.departmentnumber and" + filter;
    }
}

void SearchTeacher::scanconditionset()
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

void SearchTeacher::deleteacondition(conditionset*& con)
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
}
