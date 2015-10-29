#include "addanewteacher.h"
#pragma execution_character_set("utf-8")
void AddANewTeacher::init(){
    formlayout = new QFormLayout;
    formwidget = new QFrame;
    mainlayout = new QHBoxLayout;
    teachernumberinput = new QLineEdit;
    teachernameinput = new QLineEdit;
    emailinput = new QLineEdit;
    departmentinput = new QComboBox;
    phoneinput = new QLineEdit;
    submitbutton = new QPushButton("�e�X");
}
AddANewTeacher::AddANewTeacher(){
    init();
    setdepartment();

    QWidget* controllwidget = new QWidget;
    QHBoxLayout* controlllayout = new QHBoxLayout;
    controlllayout->addWidget(submitbutton);
    controllwidget->setLayout(controlllayout);

    teachernumberinput->setMaximumWidth(350);
    teachernumberinput->setAlignment(Qt::AlignHCenter);
    teachernumberinput->setStyleSheet("background-color:#ffffff;font-size:23px;font-family:Microsoft JhengHei");
    teachernameinput->setMaximumWidth(350);
    teachernameinput->setAlignment(Qt::AlignHCenter);
    teachernameinput->setStyleSheet("background-color:#ffffff;font-size:23px;font-family:Microsoft JhengHei");
    emailinput->setMaximumWidth(350);
    emailinput->setAlignment(Qt::AlignHCenter);
    emailinput->setStyleSheet("background-color:#ffffff;font-size:23px;font-family:Microsoft JhengHei");
    phoneinput->setMaximumWidth(350);
    phoneinput->setAlignment(Qt::AlignHCenter);
    phoneinput->setStyleSheet("background-color:#ffffff;font-size:23px;font-family:Microsoft JhengHei");
    departmentinput->setMaximumWidth(350);
    departmentinput->setStyleSheet("background-color:#ffffff;font-size:23px;font-family:Microsoft JhengHei");
    departmentinput->setEditable(true);
    departmentinput->lineEdit()->setReadOnly(true);
    departmentinput->lineEdit()->setAlignment(Qt::AlignHCenter);
    submitbutton->setMaximumWidth(120);

    formlayout->addRow("��¾���s���G",teachernumberinput);
    formlayout->addRow("��¾���m�W�G",teachernameinput);
    formlayout->addRow("���ݨt�ҡG",departmentinput);
    formlayout->addRow("�q�l�l��G",emailinput);
    formlayout->addRow("����(�q��)�G",phoneinput);
    formlayout->addRow(controllwidget);
    formlayout->setMargin(30);
    formlayout->setSpacing(30);
    formwidget->setLayout(formlayout);
    formwidget->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);
    connect(submitbutton,SIGNAL(clicked()),this,SLOT(submit()));

    formwidget->setFrameShape(QFrame::Panel);
    formwidget->setFrameShadow(QFrame::Raised);
    formwidget->setStyleSheet("background-color:#fbfbfb;font-size:23px;font-family:Microsoft JhengHei");
    //setStyleSheet("border: 1px solid black");
    mainlayout->addWidget(formwidget);
    setLayout(mainlayout);
}
void AddANewTeacher::setdepartment(){
    QSqlQuery query("select * from department");
    query.exec();
    QStringList department;
    qDebug() << query.size();
    for(int i = 0;i < query.size();i++){
        query.next();
        department << query.value(0).toString()+" "+query.value(1).toString();
    }
    departmentinput->insertItems(0,department);
}
void AddANewTeacher::submit(){
    QMessageBox msg;
    msg.layout()->setMargin(50);
    msg.layout()->setSpacing(20);
    QFont font;
    font.setFamily("�L�n������");
    font.setPixelSize(15);
    msg.setFont(font);
    QSqlQuery submitdata;
    submitdata.prepare("insert into teacher (teachernumber, teachername, departmentnumber, email, phone) values (:teachernumber, :teachername, :departmentnumber, :email, :phone)");
    QString mention = "";
    if(!teachernumberinput->text().isEmpty()){
        QSqlQuery check("select * from teacher where teachernumber = '"+teachernumberinput->text()+"'");
        check.exec();
        if(check.size()){
            msg.setWindowTitle("ĵ�i");
            msg.setIcon(QMessageBox::Critical);
            msg.setText("�ӱ�¾���s���w�s�b���Ʈw");
            msg.exec();
            return;
        }
    }
    if(teachernumberinput->text().length() == 5){
        if(teachernumberinput->text().at(0).isLetter()){
            for(int i = 1;i < 5;i++){
                if(!teachernumberinput->text().at(i).isNumber()){
                    msg.setWindowTitle("ĵ�i");
                    msg.setIcon(QMessageBox::Critical);
                    msg.setText("��"+QString::number(i+1)+"�Ӧr�������Ʀr");
                    msg.exec();
                    return;
                }
            }
            submitdata.bindValue(":teachernumber",teachernumberinput->text().toUpper());
        }else{
            msg.setWindowTitle("ĵ�i");
            msg.setIcon(QMessageBox::Critical);
            msg.setText("��1�Ӧr�������^��r��");
            msg.exec();
            return;
        }
    }else{
        msg.setWindowTitle("ĵ�i");
        msg.setIcon(QMessageBox::Critical);
        msg.setText("��¾���s������5�Ӧr�զ�(1�^��+4�Ʀr)");
        msg.exec();
        return;
    }
    if(teachernameinput->text().isEmpty()){
        msg.setWindowTitle("ĵ�i");
        msg.setIcon(QMessageBox::Critical);
        msg.setText("��¾���m�W���i����");
        msg.exec();
        return;
    }else{
        submitdata.bindValue(":teachername",teachernameinput->text());
    }
    submitdata.bindValue(":departmentnumber",departmentinput->currentText().split(" ").at(0));
    if(emailinput->text().isEmpty()){
        mention += "�q�l�l��\n";
    }else{
        if(emailinput->text().contains('@')){
            if(emailinput->text().split("@").length() == 2){
                if(emailinput->text().split("@").at(0).length() && emailinput->text().split("@").at(1).length()){
                     submitdata.bindValue(":email",emailinput->text());
                }else{
                    msg.setWindowTitle("ĵ�i");
                    msg.setIcon(QMessageBox::Critical);
                    msg.setText("�п�J���T���q�l�l��榡");
                    msg.exec();
                    return;
                }
            }else{
                msg.setWindowTitle("ĵ�i");
                msg.setIcon(QMessageBox::Critical);
                msg.setText("�п�J���T���q�l�l��榡");
                msg.exec();
                return;
            }
        }else{
            msg.setWindowTitle("ĵ�i");
            msg.setIcon(QMessageBox::Critical);
            msg.setText("�п�J���T���q�l�l��榡");
            msg.exec();
            return;
        }
    }
    if(phoneinput->text().isEmpty()){
        mention += "����(�q��)\n";
    }else{
        submitdata.bindValue(":phone",phoneinput->text());
    }
    if(mention.isEmpty()){
        if(submitdata.exec()){
            QImage icon;
            icon.load("right.png");
            icon = icon.scaledToWidth(50);
            msg.setWindowTitle("����");
            msg.setIconPixmap(QPixmap::fromImage(icon));
            msg.setText("�Ѯv��Ƶn�����\");
            msg.exec();
        }else{
            QImage icon;
            icon.load("error.png");
            icon = icon.scaledToWidth(50);
            msg.setWindowTitle("���~");
            msg.setIconPixmap(QPixmap::fromImage(icon));
            msg.setText("�Ѯv��Ƶn������");
            msg.exec();
        }
    }else{
        mention.chop(1);
        QMessageBox questmsg;
        questmsg.setWindowTitle("����");
        questmsg.setText("�H�U���٨S��J������");
        questmsg.setInformativeText(mention+"\n\n�аݤ��n��J���Ʈw��");
        questmsg.setIcon(QMessageBox::Warning);
        questmsg.layout()->setMargin(15);
        questmsg.layout()->setSpacing(10);
        QFont font;
        font.setPixelSize(15);
        font.setFamily("�L�n������");
        questmsg.setFont(font);
        questmsg.addButton(QMessageBox::Yes);
        questmsg.addButton(QMessageBox::No);
        if(questmsg.exec() == QMessageBox::Yes){
            if(submitdata.exec()){
                QImage icon;
                icon.load("right.png");
                icon = icon.scaledToWidth(50);
                msg.setWindowTitle("����");
                msg.setIconPixmap(QPixmap::fromImage(icon));
                msg.setText("��Ƥw�g�J");
                msg.exec();
            }else{
                QImage icon;
                icon.load("error.png");
                icon = icon.scaledToWidth(50);
                msg.setWindowTitle("���~");
                msg.setIconPixmap(QPixmap::fromImage(icon));
                msg.setText("��Ƽg�J����");
                msg.exec();
            }
        }
    }
}
