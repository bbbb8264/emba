#include "addanewcourse.h"
#include <QtSql>
#pragma execution_character_set("utf-8")

void AddANewCourse::init(){
    mainlayout = new QHBoxLayout;
    formlayout1 = new QFormLayout;
    formwidget1 = new QFrame;
    coursenumberinput = new QLineEdit;
    coursenameinput = new QLineEdit;
    yearinput = new QLineEdit;
    creditinput = new QLineEdit;
    semesterinput = new QComboBox;
    coursetypeinput = new QComboBox;
    teacherinput = new QLineEdit;
    submitbutton = new QPushButton("�e�X");
}

AddANewCourse::AddANewCourse(){
    init();

    QStringList semester;
    semester << "�W" << "�U";
    semesterinput->insertItems(0,semester);
    QStringList coursetype;
    coursetype << "����" << "����" << "�޲z���" << "�޲z�M��" << "���";
    coursetypeinput->insertItems(0,coursetype);
    if(!(QDate::currentDate().month() >= 5 && QDate::currentDate().month() <= 10)){
        semesterinput->setCurrentIndex(1);
    }
    creditinput->setValidator( new QIntValidator(0, 5, this) );
    yearinput->setValidator( new QIntValidator(100, 200, this) );
    yearinput->setText(QString::number(QDate::currentDate().year()-1911));

    coursenumberinput->setMaximumWidth(350);
    coursenumberinput->setAlignment(Qt::AlignHCenter);
    coursenumberinput->setStyleSheet("background-color:#ffffff;font-size:23px;font-family:Microsoft JhengHei");
    coursetypeinput->setMaximumWidth(350);
    coursetypeinput->setStyleSheet("background-color:#ffffff;font-size:23px;font-family:Microsoft JhengHei");
    coursetypeinput->setEditable(true);
    coursetypeinput->lineEdit()->setReadOnly(true);
    coursetypeinput->lineEdit()->setAlignment(Qt::AlignHCenter);
    coursenameinput->setMaximumWidth(350);
    coursenameinput->setAlignment(Qt::AlignHCenter);
    coursenameinput->setStyleSheet("background-color:#ffffff;font-size:23px;font-family:Microsoft JhengHei");
    creditinput->setMaximumWidth(350);
    creditinput->setStyleSheet("background-color:#ffffff;font-size:23px;font-family:Microsoft JhengHei");
    creditinput->setAlignment(Qt::AlignHCenter);
    yearinput->setMaximumWidth(350);
    yearinput->setStyleSheet("background-color:#ffffff;font-size:23px;font-family:Microsoft JhengHei");
    yearinput->setAlignment(Qt::AlignHCenter);
    semesterinput->setMaximumWidth(350);
    semesterinput->setEditable(true);
    semesterinput->lineEdit()->setReadOnly(true);
    semesterinput->lineEdit()->setAlignment(Qt::AlignHCenter);
    semesterinput->setStyleSheet("background-color:#ffffff;font-size:23px;font-family:Microsoft JhengHei");
    teacherinput->setMaximumWidth(350);
    teacherinput->setMinimumWidth(150);
    teacherinput->setStyleSheet("background-color:#ffffff;font-size:23px;font-family:Microsoft JhengHei");
    teacherinput->setAlignment(Qt::AlignHCenter);
    submitbutton->setMaximumWidth(120);
    teacherinput->setPlaceholderText("��¾���s��,�m�W");

    QWidget* controllwidget = new QWidget;
    QHBoxLayout* controlllayout = new QHBoxLayout;
    controlllayout->addWidget(submitbutton);
    controllwidget->setLayout(controlllayout);

    QStringList wordList;

    QSqlQuery query("select teachernumber,teachername from teacher");
    query.exec();
    for(int i = 0;i < query.size();i++){
        query.next();
        wordList << query.value(0).toString()+" "+query.value(1).toString();
    }

    QStringListModel* string_list_model = new QStringListModel(wordList, this);
    completer = new QCompleter(this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    completer->setModel(string_list_model);
    teacherinput->setCompleter(completer);
    completer->setFilterMode(Qt::MatchContains);
    connect(submitbutton,SIGNAL(clicked()),this,SLOT(submit()));

    formlayout1->addRow("�ҵ{�s���G",coursenumberinput);
    formlayout1->addRow("�ҵ{����",coursetypeinput);
    formlayout1->addRow("�ҵ{�W�١G",coursenameinput);
    formlayout1->addRow("�Ǥ��ơG",creditinput);
    formlayout1->addRow("�}�ҾǦ~�G",yearinput);
    formlayout1->addRow("�}�ҾǴ��G",semesterinput);
    formlayout1->addRow("���ɦѮv�G",teacherinput);
    formlayout1->addRow(controllwidget);
    formlayout1->setMargin(30);
    formlayout1->setSpacing(30);

    formwidget1->setLayout(formlayout1);
    formwidget1->setFrameShape(QFrame::Panel);
    formwidget1->setFrameShadow(QFrame::Raised);
    formwidget1->setStyleSheet("background-color:#fbfbfb;font-size:23px;font-family:Microsoft JhengHei");

    //setStyleSheet("border: 1px solid black");
    mainlayout->addWidget(formwidget1);
    mainlayout->setAlignment(formwidget1,Qt::AlignCenter);
    setLayout(mainlayout);
}
void AddANewCourse::submit(){
    QMessageBox msg;
    msg.layout()->setMargin(50);
    msg.layout()->setSpacing(20);
    QFont font;
    font.setFamily("�L�n������");
    font.setPixelSize(15);
    msg.setFont(font);
    QSqlQuery submitdata;
    submitdata.prepare("insert into courseinformation (coursenumber, coursename, year, semester, coursetype, teachernumber, credit) values (:coursenumber, :coursename, :year, :semester, :coursetype, :teachernumber, :credit)");
    if(coursenumberinput->text().isEmpty()){
        msg.setWindowTitle("ĵ�i");
        msg.setIcon(QMessageBox::Critical);
        msg.setText("�ҵ{�s�������񶵥�");
        msg.exec();
        return;
    }else{
        QSqlQuery check("select coursenumber from courseinformation where coursenumber = '"+coursenumberinput->text()+"'");
        check.exec();
        if(check.size()){
            msg.setWindowTitle("ĵ�i");
            msg.setIcon(QMessageBox::Critical);
            msg.setText("��Ʈw�w���@���s����"+coursenumberinput->text()+"���ҵ{");
            msg.exec();
            return;
        }else{
            submitdata.bindValue(":coursenumber",coursenumberinput->text().toUpper());
        }
    }
    submitdata.bindValue(":coursetype","ct0"+QString::number(coursetypeinput->currentIndex()+1));
    if(coursenameinput->text().isEmpty()){
        msg.setWindowTitle("ĵ�i");
        msg.setIcon(QMessageBox::Critical);
        msg.setText("�ҵ{�W�٬����񶵥�");
        msg.exec();
        return;
    }else{
        submitdata.bindValue(":coursename",coursenameinput->text());
    }
    if(yearinput->text().isEmpty()){
        msg.setWindowTitle("ĵ�i");
        msg.setIcon(QMessageBox::Critical);
        msg.setText("�}�ҾǦ~�׬����񶵥�");
        msg.exec();
        return;
    }else{
        submitdata.bindValue(":year",yearinput->text().toInt());
    }
    submitdata.bindValue(":semester",semesterinput->currentText());
    if(creditinput->text().isEmpty()){
        msg.setWindowTitle("ĵ�i");
        msg.setIcon(QMessageBox::Critical);
        msg.setText("�Ǥ��Ƭ����񶵥�");
        msg.exec();
        return;
    }else{
        submitdata.bindValue(":credit",creditinput->text().toInt());
    }
    if(teacherinput->text().isEmpty()){
        msg.setWindowTitle("ĵ�i");
        msg.setIcon(QMessageBox::Critical);
        msg.setText("�Ѯv�����񶵥�");
        msg.exec();
        return;
    }else{
        QStringList teacher = teacherinput->text().split(" ");
        QString teachernumber = teacher.at(0);
        teachernumber = teachernumber.toUpper();
        if(teacher.size() != 2){
            msg.setWindowTitle("ĵ�i");
            msg.setIcon(QMessageBox::Critical);
            msg.setText("���ˬd�Ѯv��J�榡�O�_��\n�Ѯv�s�� �Ѯv�m�W\n�����Ϊťդ��j");
            msg.exec();
            return;
        }
        QString teachername = teacherinput->text().split(" ").at(teacherinput->text().split(" ").size()-1);
        QSqlQuery check("select teachername from teacher where teachernumber = '"+teachernumber+"'");
        check.exec();
        if(!check.size()){
            msg.setWindowTitle("ĵ�i");
            msg.setIcon(QMessageBox::Critical);
            msg.setText("��Ʈw�䤣��s����"+teachernumber+"���Ѯv");
            msg.exec();
            return;
        }else{
            check.next();
            if(check.value(0).toString() != teachername){
                msg.setWindowTitle("ĵ�i");
                msg.setIcon(QMessageBox::Critical);
                msg.setText("�s��"+teachernumber+"���Ѯv�m�W����"+teachername+"\n���ˬd�m�W�O�_����");
                msg.exec();
                return;
            }else{
                submitdata.bindValue(":teachernumber",teachernumber);
                if(submitdata.exec()){
                    QImage icon;
                    icon.load("right.png");
                    icon = icon.scaledToWidth(50);
                    msg.setWindowTitle("����");
                    msg.setIconPixmap(QPixmap::fromImage(icon));
                    msg.setText("�s�W�ҵ{���\");
                    msg.exec();
                }else{
                    QImage icon;
                    icon.load("error.png");
                    icon = icon.scaledToWidth(50);
                    msg.setWindowTitle("���~");
                    msg.setIconPixmap(QPixmap::fromImage(icon));
                    msg.setText("�s�W�ҵ{����");
                    msg.exec();
                }
            }
        }
    }
}
