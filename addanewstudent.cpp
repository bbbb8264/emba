#include "addanewstudent.h"
#include <qlabel.h>
#include <qpainter.h>
#include <qfile.h>
#include <string>
#include <QtWidgets>
#include <QtSql>
#pragma execution_character_set("utf-8")
#include <filedialog.h>
AddANewStudent::AddANewStudent()
{
    //setStyleSheet("border: 1px solid black");
    init();
    setFrameShape(QFrame::Panel);
    setFrameShadow(QFrame::Raised);
    setLineWidth(1);
    msg.layout()->setMargin(20);
    msg.layout()->setSpacing(10);
    QFont font;
    font.setFamily("�L�n������");
    font.setPixelSize(15);
    msg.setFont(font);
    picturewidget->setAlignment(Qt::AlignTop);
    picturewidget->setFrameStyle(QFrame::Panel | QFrame::Raised);
    picturewidget->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Maximum);
    mainpicturelayout->addWidget(picturewidget);
    mainpicturelayout->addWidget(remind);
    mainpicturewidget->setLayout(mainpicturelayout);
    mainpicturewidget->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);
    mainpicturewidget->setMinimumHeight(450);
    mainpicturelayout->setAlignment(Qt::AlignTop);
    mainpicturelayout->setAlignment(remind,Qt::AlignHCenter);
    remind->setStyleSheet("font-size:20px;font-family:Microsoft JhengHei");
    connect(picturewidget,SIGNAL(inserted()),this,SLOT(deleteremind()));
    mainlayout->addWidget(mainpicturewidget);
    mainlayout->setMargin(0);
    setLayout(mainlayout);
    studentnumberedit->setMinimumWidth(200);
    nameedit->setMinimumWidth(200);

    genderlayout->addWidget(male);
    genderlayout->addWidget(female);

    male->setStyleSheet("");
    female->setStyleSheet("");

    gendergroup->setLayout(genderlayout);
    gendergroup->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);

    contactformlayout->addRow("�q��(��) :",telephoneday);
    contactformlayout->addRow("�q��(�]) :",telephonenight);
    contactformlayout->addRow("������X :",mobile);

    telephoneday->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Maximum);
    telephonenight->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Maximum);
    mobile->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Maximum);

    contactgroup->setLayout(contactformlayout);
    contactgroup->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Maximum);

    companyformlayout->addRow("���q�W�� :",companyname);
    companyformlayout->addRow("�ثe¾�� :",companyposition);

    companyname->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Maximum);
    companyposition->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Maximum);

    companygroup->setLayout(companyformlayout);
    companygroup->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Maximum);

    submitlayout->setAlignment(Qt::AlignCenter);
    submitlayout->addWidget(submitbutton);

    submitwidget->setLayout(submitlayout);

    submitbutton->setMaximumWidth(100);

    direction->setFixedWidth(200);
    graduateschool->setFixedWidth(200);
    graduatedepartment->setFixedWidth(200);

    creditclasslayout->addWidget(creditclassbuttonyes);
    creditclasslayout->addWidget(creditclassbuttonno);
    creditclassgroup->setLayout(creditclasslayout);
    creditclassgroup->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Maximum);

    formlayout2->addRow("�Ҧb�a�� :",direction);
    formlayout2->addRow("���~�Ǯ� :",graduateschool);
    formlayout2->addRow("���~��t :",graduatedepartment);
    formlayout2->addRow("�O�_�ѥ[�Ǥ��Z:",creditclassgroup);
    formlayout2->addRow(companygroup);

    direction->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Maximum);
    graduateschool->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Maximum);
    graduatedepartment->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Maximum);
    creditclassgroup->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Maximum);

    QWidget* raise = new QWidget;
    raise->setFixedHeight(100);

    formlayout2->addRow(raise);
    formlayout2->addRow("",submitbutton);
    formlayout2->setLabelAlignment(Qt::AlignHCenter);
    formlayout2->setAlignment(Qt::AlignHCenter);

    formwidget2->setMinimumHeight(470);
    formwidget2->setLayout(formlayout2);

    formlayout->addRow("����Ҹ��X :",ticketnumber);
    formlayout->addRow("�Ǹ� :",studentnumberedit);
    formlayout->addRow("�m�W :",nameedit);
    formlayout->addRow("�ʧO :",gendergroup);
    formlayout->addRow("�ͤ� :",dateinput);
    formlayout->addRow("�q�T�a�} :",address);
    formlayout->addRow("�q�l�l�� :",emailaddress);
    formlayout->addRow("���Ҩ��� :",studentidentity);
    formlayout->addRow(contactgroup);
    ticketnumber->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Maximum);
    studentnumberedit->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Maximum);
    nameedit->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Maximum);
    gendergroup->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Maximum);
    dateinput->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Maximum);
    address->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Maximum);
    emailaddress->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Maximum);
    studentidentity->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Maximum);

    formwidget->setLayout(formlayout);
    formwidget->setMinimumHeight(470);
    formwidget->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);
    formwidget2->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);
    mainlayout->addWidget(formwidget);
    mainlayout->addWidget(formwidget2);
    mainlayout->setMargin(20);
    mainlayout->setSpacing(20);
    setMaximumHeight(500);
    setMaximumWidth(1200);
    setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);
    connect(submitbutton,SIGNAL(clicked()),this,SLOT(submited()));
    setformfont();
}
void AddANewStudent::setting()
{
    pictureSizeLimit = true;
    pictureMaxHeightPx = 800;
    pictureMaxWidthPx = 800;
}

void AddANewStudent::setformfont()
{
    QFont* font = new QFont;
    font->setPixelSize(18);
    font->setFamily("�L�n������");
    formwidget->setFont(*font);
    formwidget2->setFont(*font);
}
void AddANewStudent::init()
{
    creditclassbuttonyes = new QRadioButton("�O");
    creditclassbuttonno = new QRadioButton("�_");
    creditclassgroup = new QGroupBox;
    creditclasslayout = new QHBoxLayout;
    male = new QRadioButton("�k");
    female = new QRadioButton("�k");
    genderlayout = new QHBoxLayout;
    mainlayout = new QHBoxLayout;
    submitwidget = new QWidget;
    submitlayout = new QHBoxLayout;
    formlayout2 = new QFormLayout;
    formwidget2 = new QWidget;
    nameedit = new QLineEdit;
    gendergroup = new QGroupBox;
    companygroup = new QGroupBox("�ثe�A�ȳ��");
    companyformlayout = new QFormLayout;
    contactgroup = new QGroupBox("�p���覡");
    contactformlayout = new QFormLayout;
    formwidget = new QWidget;
    formlayout = new QFormLayout;
    studentnumberedit = new QLineEdit;
    formwidget = new QWidget;
    formlayout = new QFormLayout;
    companyname = new QLineEdit;
    companyposition = new QLineEdit;
    mobile = new QLineEdit;
    telephoneday = new QLineEdit;
    telephonenight = new QLineEdit;
    direction = new QLineEdit;
    ticketnumber = new QLineEdit;
    studentidentity = new QLineEdit;
    graduatelevel = new QLineEdit;
    address = new QLineEdit;
    emailaddress = new QLineEdit;
    graduateschool = new QLineEdit;
    graduatedepartment = new QLineEdit;
    dateinput = new QDateEdit;
    mainpicturelayout = new QVBoxLayout;
    mainpicturewidget = new QWidget;
    picturewidget = new ChangePicture;
    remind = new QLabel("�I��W�Ǭۤ�");
    submitbutton = new QPushButton("�e�X");
}
void AddANewStudent::submited()
{
    QSqlQuery query;
    query.prepare( "insert into student (ticketnumber, studentnumber, direction, studentidentity, graduatelevel, name, picture, gender, address, emailaddress, birthday, telephoneday, telephonenight, mobile, graduateschool, graduatedepartment, companyname, currentposition, creditclass) values(:ticketnumber, :studentnumber, :direction, :studentidentity, :graduatelevel, :name, :picture, :gender, :address, :emailaddress, :birthday, :telephoneday, :telephonenight, :mobile, :graduateschool, :graduatedepartment, :companyname, :currentposition, :creditclass)" );
    QString mentionstring = "";
    if(ticketnumber->text().isEmpty()){
        msg.setWindowTitle("ĵ�i");
        msg.setIcon(QMessageBox::Critical);
        msg.setText("����Ҹ��X�����񶵥�");
        msg.exec();
        return;
    }else{
        QString ticket = ticketnumber->text().toUpper();
        QSqlQuery check("select * from student where ticketnumber = '"+ticket+"'");
        if(check.size()){
            msg.setWindowTitle("ĵ�i");
            msg.setIcon(QMessageBox::Critical);
            msg.setText("��Ʈw�w���ӭ���Ҹ��X");
            msg.exec();
            return;
        }
        query.bindValue(":ticketnumber",ticketnumber->text());
    }
    if(studentnumberedit->text().isEmpty()){
        msg.setWindowTitle("ĵ�i");
        msg.setIcon(QMessageBox::Critical);
        msg.setText("�Ǹ������񶵥�");
        msg.exec();
        return;
    }
    else{
        QString studentnumber = studentnumberedit->text().toUpper();
        QSqlQuery check("select * from student where studentnumber = '"+studentnumber+"'");
        if(check.size()){
            msg.setWindowTitle("ĵ�i");
            msg.setIcon(QMessageBox::Critical);
            msg.setText("��Ʈw�w���ӾǸ�");
            msg.exec();
            return;
        }
        if(studentnumber.left(2) != "R0"){
            msg.setWindowTitle("ĵ�i");
            msg.setIcon(QMessageBox::Critical);
            msg.setText("�Ǹ��e��X����R0");
            msg.exec();
            return;
        }
        if(studentnumber.left(5).right(3) != "000" && studentnumber.left(5).right(3).toInt() == 0){
            msg.setWindowTitle("ĵ�i");
            msg.setIcon(QMessageBox::Critical);
            msg.setText("�L�k�q�Ǹ������X���~�~��(�T�줭�X���O�Ʀr?)");
            msg.exec();
            return;
        }else{
            int graduate = studentnumber.left(5).right(3).toInt();
            graduate -= 597;
            if(graduate < 50){
                msg.setWindowTitle("ĵ�i");
                msg.setIcon(QMessageBox::Critical);
                msg.setText("�q�Ǹ����������~�~�׿��~");
                msg.exec();
                return;
            }
            query.bindValue(":graduatelevel",graduate);
        }
        query.bindValue(":studentnumber",studentnumber);
    }
    if(nameedit->text().isEmpty()){
        if(!mentionstring.isEmpty())
            mentionstring += "\n";
        mentionstring += "�m�W" ;
    }else{
        query.bindValue(":name",nameedit->text());
    }
    if(direction->text().isEmpty()){
        if(!mentionstring.isEmpty())
            mentionstring += "\n";
        mentionstring += "�Ҧb�a��" ;
    }else{
        query.bindValue(":direction",direction->text());
    }
    if(address->text().isEmpty()){
        if(!mentionstring.isEmpty())
            mentionstring += "\n";
        mentionstring += "�q�T�a�}" ;
    }else{
        query.bindValue(":address",address->text());
    }
    if(emailaddress->text().isEmpty()){
        if(!mentionstring.isEmpty())
            mentionstring += "\n";
        mentionstring += "�q�l�l��" ;
    }else{
        query.bindValue(":emailaddress",emailaddress->text());
    }
    if(telephoneday->text().isEmpty()){
        if(!mentionstring.isEmpty())
            mentionstring += "\n";
        mentionstring += "�q��(��)" ;
    }else{
        query.bindValue(":telephoneday",telephoneday->text());
    }
    if(telephonenight->text().isEmpty()){
        if(!mentionstring.isEmpty())
            mentionstring += "\n";
        mentionstring += "�q��(�])" ;
    }else{
        query.bindValue(":telephonenight",telephonenight->text());
    }
    if(mobile->text().isEmpty()){
        if(!mentionstring.isEmpty())
            mentionstring += "\n";
        mentionstring += "����q��" ;
    }else{
        query.bindValue(":mobile",mobile->text());
    }
    if(studentidentity->text().isEmpty()){
        if(!mentionstring.isEmpty())
            mentionstring += "\n";
        mentionstring += "���Ҩ���" ;
    }else{
        query.bindValue(":studentidentity",studentidentity->text());
    }
    if(graduateschool->text().isEmpty()){
        if(!mentionstring.isEmpty())
            mentionstring += "\n";
        mentionstring += "���~�Ǯ�" ;
    }else{
        query.bindValue(":graduateschool",graduateschool->text());
    }
    if(graduatedepartment->text().isEmpty()){
        if(!mentionstring.isEmpty())
            mentionstring += "\n";
        mentionstring += "���~��t" ;
    }else{
        query.bindValue(":graduatedepartment",graduatedepartment->text());
    }
    if(picturewidget->pictureinsert){
        QByteArray byteArray;
        QBuffer buffer(&byteArray);
        picturewidget->img.save(&buffer, "JPG"); // writes the image in PNG format inside the buffer
        query.bindValue(":picture",byteArray);
    }else{
        if(!mentionstring.isEmpty())
            mentionstring += "\n";
        mentionstring += "�ӤH�Ӥ�" ;
    }

    if(male->isChecked() || female->isChecked()){
        if(male->isChecked()){
            query.bindValue(":gender","�k");
        }else{
            query.bindValue(":gender","�k");
        }
    }else{
        if(!mentionstring.isEmpty())
            mentionstring += "\n";
        mentionstring += "�ʧO" ;
    }
    if(creditclassbuttonyes->isChecked() || creditclassbuttonyes->isChecked()){
        if(creditclassbuttonyes->isChecked()){
            query.bindValue(":creditclass",1);
        }else{
            query.bindValue(":creditclass",0);
        }
    }else{
        if(!mentionstring.isEmpty())
            mentionstring += "\n";
        mentionstring += "�Ǥ��Z���" ;
    }
    query.bindValue(":birthday",dateinput->text());

    if(companyname->text().isEmpty()){
        if(!mentionstring.isEmpty())
            mentionstring += "\n";
        mentionstring += "���q�W��" ;
    }else{
        query.bindValue(":companyname",companyname->text());
    }
    if(companyposition->text().isEmpty()){
        if(!mentionstring.isEmpty())
            mentionstring += "\n";
        mentionstring += "���q�q��" ;
    }else{
        query.bindValue(":currentposition",companyposition->text());
    }
    if(mentionstring.isEmpty()){
        if(query.exec()){
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
    }else{
        QMessageBox questmsg;
        questmsg.setWindowTitle("����");
        questmsg.setText("�H�U���٨S��J������");
        questmsg.setInformativeText(mentionstring+"\n\n�аݤ��n��J���Ʈw��");
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
            if(query.exec()){
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
    /*QByteArray byteArray;
    QBuffer buffer(&byteArray);
    picturewidget->img.save(&buffer, "png"); // writes the image in PNG format inside the buffer
    QSqlQuery query;
    query.prepare( "insert into student(studentnumber,picture)values('bbbbbbb',:img)" );
    //query.bindValue(":img",byteArray);
    query.exec();*/
    /*QSqlQuery query;
    query.prepare( "select * from student where studentnumber = 'bbbbbbb'" );
    query.exec();
    query.next();
    QByteArray byteArray;
    byteArray = query.value(1).toByteArray();
    picturewidget->img.loadFromData(byteArray);
    picturewidget->setPixmap(QPixmap::fromImage(picturewidget->img));*/
}

void AddANewStudent::deleteremind(){
    remind->setText("");
}
