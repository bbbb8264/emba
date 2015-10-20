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
    font.setFamily("微軟正黑體");
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

    contactformlayout->addRow("電話(日) :",telephoneday);
    contactformlayout->addRow("電話(夜) :",telephonenight);
    contactformlayout->addRow("手機號碼 :",mobile);

    telephoneday->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Maximum);
    telephonenight->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Maximum);
    mobile->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Maximum);

    contactgroup->setLayout(contactformlayout);
    contactgroup->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Maximum);

    companyformlayout->addRow("公司名稱 :",companyname);
    companyformlayout->addRow("目前職位 :",companyposition);

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

    formlayout2->addRow("所在地區 :",direction);
    formlayout2->addRow("畢業學校 :",graduateschool);
    formlayout2->addRow("畢業科系 :",graduatedepartment);
    formlayout2->addRow("是否參加學分班:",creditclassgroup);
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

    formlayout->addRow("准考證號碼 :",ticketnumber);
    formlayout->addRow("學號 :",studentnumberedit);
    formlayout->addRow("姓名 :",nameedit);
    formlayout->addRow("性別 :",gendergroup);
    formlayout->addRow("生日 :",dateinput);
    formlayout->addRow("通訊地址 :",address);
    formlayout->addRow("電子郵件 :",emailaddress);
    formlayout->addRow("報考身分 :",studentidentity);
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
    font->setFamily("微軟正黑體");
    formwidget->setFont(*font);
    formwidget2->setFont(*font);
}
void AddANewStudent::init()
{
    creditclassbuttonyes = new QRadioButton("是");
    creditclassbuttonno = new QRadioButton("否");
    creditclassgroup = new QGroupBox;
    creditclasslayout = new QHBoxLayout;
    male = new QRadioButton("男");
    female = new QRadioButton("女");
    genderlayout = new QHBoxLayout;
    mainlayout = new QHBoxLayout;
    submitwidget = new QWidget;
    submitlayout = new QHBoxLayout;
    formlayout2 = new QFormLayout;
    formwidget2 = new QWidget;
    nameedit = new QLineEdit;
    gendergroup = new QGroupBox;
    companygroup = new QGroupBox("目前服務單位");
    companyformlayout = new QFormLayout;
    contactgroup = new QGroupBox("聯絡方式");
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
    remind = new QLabel("點選上傳相片");
    submitbutton = new QPushButton("送出");
}
void AddANewStudent::submited()
{
    QSqlQuery query;
    query.prepare( "insert into student (ticketnumber, studentnumber, direction, studentidentity, graduatelevel, name, picture, gender, address, emailaddress, birthday, telephoneday, telephonenight, mobile, graduateschool, graduatedepartment, companyname, currentposition, creditclass) values(:ticketnumber, :studentnumber, :direction, :studentidentity, :graduatelevel, :name, :picture, :gender, :address, :emailaddress, :birthday, :telephoneday, :telephonenight, :mobile, :graduateschool, :graduatedepartment, :companyname, :currentposition, :creditclass)" );
    QString mentionstring = "";
    if(ticketnumber->text().isEmpty()){
        msg.setWindowTitle("警告");
        msg.setIcon(QMessageBox::Critical);
        msg.setText("准考證號碼為必填項目");
        msg.exec();
        return;
    }else{
        QString ticket = ticketnumber->text().toUpper();
        QSqlQuery check("select * from student where ticketnumber = '"+ticket+"'");
        if(check.size()){
            msg.setWindowTitle("警告");
            msg.setIcon(QMessageBox::Critical);
            msg.setText("資料庫已有該准考證號碼");
            msg.exec();
            return;
        }
        query.bindValue(":ticketnumber",ticketnumber->text());
    }
    if(studentnumberedit->text().isEmpty()){
        msg.setWindowTitle("警告");
        msg.setIcon(QMessageBox::Critical);
        msg.setText("學號為必填項目");
        msg.exec();
        return;
    }
    else{
        QString studentnumber = studentnumberedit->text().toUpper();
        QSqlQuery check("select * from student where studentnumber = '"+studentnumber+"'");
        if(check.size()){
            msg.setWindowTitle("警告");
            msg.setIcon(QMessageBox::Critical);
            msg.setText("資料庫已有該學號");
            msg.exec();
            return;
        }
        if(studentnumber.left(2) != "R0"){
            msg.setWindowTitle("警告");
            msg.setIcon(QMessageBox::Critical);
            msg.setText("學號前兩碼必為R0");
            msg.exec();
            return;
        }
        if(studentnumber.left(5).right(3) != "000" && studentnumber.left(5).right(3).toInt() == 0){
            msg.setWindowTitle("警告");
            msg.setIcon(QMessageBox::Critical);
            msg.setText("無法從學號提取出畢業年度(三到五碼不是數字?)");
            msg.exec();
            return;
        }else{
            int graduate = studentnumber.left(5).right(3).toInt();
            graduate -= 597;
            if(graduate < 50){
                msg.setWindowTitle("警告");
                msg.setIcon(QMessageBox::Critical);
                msg.setText("從學號提取的畢業年度錯誤");
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
        mentionstring += "姓名" ;
    }else{
        query.bindValue(":name",nameedit->text());
    }
    if(direction->text().isEmpty()){
        if(!mentionstring.isEmpty())
            mentionstring += "\n";
        mentionstring += "所在地區" ;
    }else{
        query.bindValue(":direction",direction->text());
    }
    if(address->text().isEmpty()){
        if(!mentionstring.isEmpty())
            mentionstring += "\n";
        mentionstring += "通訊地址" ;
    }else{
        query.bindValue(":address",address->text());
    }
    if(emailaddress->text().isEmpty()){
        if(!mentionstring.isEmpty())
            mentionstring += "\n";
        mentionstring += "電子郵件" ;
    }else{
        query.bindValue(":emailaddress",emailaddress->text());
    }
    if(telephoneday->text().isEmpty()){
        if(!mentionstring.isEmpty())
            mentionstring += "\n";
        mentionstring += "電話(日)" ;
    }else{
        query.bindValue(":telephoneday",telephoneday->text());
    }
    if(telephonenight->text().isEmpty()){
        if(!mentionstring.isEmpty())
            mentionstring += "\n";
        mentionstring += "電話(夜)" ;
    }else{
        query.bindValue(":telephonenight",telephonenight->text());
    }
    if(mobile->text().isEmpty()){
        if(!mentionstring.isEmpty())
            mentionstring += "\n";
        mentionstring += "手機電話" ;
    }else{
        query.bindValue(":mobile",mobile->text());
    }
    if(studentidentity->text().isEmpty()){
        if(!mentionstring.isEmpty())
            mentionstring += "\n";
        mentionstring += "報考身分" ;
    }else{
        query.bindValue(":studentidentity",studentidentity->text());
    }
    if(graduateschool->text().isEmpty()){
        if(!mentionstring.isEmpty())
            mentionstring += "\n";
        mentionstring += "畢業學校" ;
    }else{
        query.bindValue(":graduateschool",graduateschool->text());
    }
    if(graduatedepartment->text().isEmpty()){
        if(!mentionstring.isEmpty())
            mentionstring += "\n";
        mentionstring += "畢業科系" ;
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
        mentionstring += "個人照片" ;
    }

    if(male->isChecked() || female->isChecked()){
        if(male->isChecked()){
            query.bindValue(":gender","男");
        }else{
            query.bindValue(":gender","女");
        }
    }else{
        if(!mentionstring.isEmpty())
            mentionstring += "\n";
        mentionstring += "性別" ;
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
        mentionstring += "學分班選擇" ;
    }
    query.bindValue(":birthday",dateinput->text());

    if(companyname->text().isEmpty()){
        if(!mentionstring.isEmpty())
            mentionstring += "\n";
        mentionstring += "公司名稱" ;
    }else{
        query.bindValue(":companyname",companyname->text());
    }
    if(companyposition->text().isEmpty()){
        if(!mentionstring.isEmpty())
            mentionstring += "\n";
        mentionstring += "公司電話" ;
    }else{
        query.bindValue(":currentposition",companyposition->text());
    }
    if(mentionstring.isEmpty()){
        if(query.exec()){
            QImage icon;
            icon.load("right.png");
            icon = icon.scaledToWidth(50);
            msg.setWindowTitle("完成");
            msg.setIconPixmap(QPixmap::fromImage(icon));
            msg.setText("資料已寫入");
            msg.exec();
        }else{
            QImage icon;
            icon.load("error.png");
            icon = icon.scaledToWidth(50);
            msg.setWindowTitle("錯誤");
            msg.setIconPixmap(QPixmap::fromImage(icon));
            msg.setText("資料寫入失敗");
            msg.exec();
        }
    }else{
        QMessageBox questmsg;
        questmsg.setWindowTitle("提示");
        questmsg.setText("以下為還沒填入的項目");
        questmsg.setInformativeText(mentionstring+"\n\n請問仍要輸入到資料庫嗎");
        questmsg.setIcon(QMessageBox::Warning);
        questmsg.layout()->setMargin(15);
        questmsg.layout()->setSpacing(10);
        QFont font;
        font.setPixelSize(15);
        font.setFamily("微軟正黑體");
        questmsg.setFont(font);
        questmsg.addButton(QMessageBox::Yes);
        questmsg.addButton(QMessageBox::No);
        if(questmsg.exec() == QMessageBox::Yes){
            if(query.exec()){
                QImage icon;
                icon.load("right.png");
                icon = icon.scaledToWidth(50);
                msg.setWindowTitle("完成");
                msg.setIconPixmap(QPixmap::fromImage(icon));
                msg.setText("資料已寫入");
                msg.exec();
            }else{
                QImage icon;
                icon.load("error.png");
                icon = icon.scaledToWidth(50);
                msg.setWindowTitle("錯誤");
                msg.setIconPixmap(QPixmap::fromImage(icon));
                msg.setText("資料寫入失敗");
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
