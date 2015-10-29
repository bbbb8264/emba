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
    submitbutton = new QPushButton("送出");
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

    formlayout->addRow("教職員編號：",teachernumberinput);
    formlayout->addRow("教職員姓名：",teachernameinput);
    formlayout->addRow("所屬系所：",departmentinput);
    formlayout->addRow("電子郵件：",emailinput);
    formlayout->addRow("分機(電話)：",phoneinput);
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
    font.setFamily("微軟正黑體");
    font.setPixelSize(15);
    msg.setFont(font);
    QSqlQuery submitdata;
    submitdata.prepare("insert into teacher (teachernumber, teachername, departmentnumber, email, phone) values (:teachernumber, :teachername, :departmentnumber, :email, :phone)");
    QString mention = "";
    if(!teachernumberinput->text().isEmpty()){
        QSqlQuery check("select * from teacher where teachernumber = '"+teachernumberinput->text()+"'");
        check.exec();
        if(check.size()){
            msg.setWindowTitle("警告");
            msg.setIcon(QMessageBox::Critical);
            msg.setText("該教職員編號已存在於資料庫");
            msg.exec();
            return;
        }
    }
    if(teachernumberinput->text().length() == 5){
        if(teachernumberinput->text().at(0).isLetter()){
            for(int i = 1;i < 5;i++){
                if(!teachernumberinput->text().at(i).isNumber()){
                    msg.setWindowTitle("警告");
                    msg.setIcon(QMessageBox::Critical);
                    msg.setText("第"+QString::number(i+1)+"個字母必為數字");
                    msg.exec();
                    return;
                }
            }
            submitdata.bindValue(":teachernumber",teachernumberinput->text().toUpper());
        }else{
            msg.setWindowTitle("警告");
            msg.setIcon(QMessageBox::Critical);
            msg.setText("第1個字母必為英文字母");
            msg.exec();
            return;
        }
    }else{
        msg.setWindowTitle("警告");
        msg.setIcon(QMessageBox::Critical);
        msg.setText("教職員編號必由5個字組成(1英文+4數字)");
        msg.exec();
        return;
    }
    if(teachernameinput->text().isEmpty()){
        msg.setWindowTitle("警告");
        msg.setIcon(QMessageBox::Critical);
        msg.setText("教職員姓名不可為空");
        msg.exec();
        return;
    }else{
        submitdata.bindValue(":teachername",teachernameinput->text());
    }
    submitdata.bindValue(":departmentnumber",departmentinput->currentText().split(" ").at(0));
    if(emailinput->text().isEmpty()){
        mention += "電子郵件\n";
    }else{
        if(emailinput->text().contains('@')){
            if(emailinput->text().split("@").length() == 2){
                if(emailinput->text().split("@").at(0).length() && emailinput->text().split("@").at(1).length()){
                     submitdata.bindValue(":email",emailinput->text());
                }else{
                    msg.setWindowTitle("警告");
                    msg.setIcon(QMessageBox::Critical);
                    msg.setText("請輸入正確的電子郵件格式");
                    msg.exec();
                    return;
                }
            }else{
                msg.setWindowTitle("警告");
                msg.setIcon(QMessageBox::Critical);
                msg.setText("請輸入正確的電子郵件格式");
                msg.exec();
                return;
            }
        }else{
            msg.setWindowTitle("警告");
            msg.setIcon(QMessageBox::Critical);
            msg.setText("請輸入正確的電子郵件格式");
            msg.exec();
            return;
        }
    }
    if(phoneinput->text().isEmpty()){
        mention += "分機(電話)\n";
    }else{
        submitdata.bindValue(":phone",phoneinput->text());
    }
    if(mention.isEmpty()){
        if(submitdata.exec()){
            QImage icon;
            icon.load("right.png");
            icon = icon.scaledToWidth(50);
            msg.setWindowTitle("完成");
            msg.setIconPixmap(QPixmap::fromImage(icon));
            msg.setText("老師資料登錄成功");
            msg.exec();
        }else{
            QImage icon;
            icon.load("error.png");
            icon = icon.scaledToWidth(50);
            msg.setWindowTitle("錯誤");
            msg.setIconPixmap(QPixmap::fromImage(icon));
            msg.setText("老師資料登錄失敗");
            msg.exec();
        }
    }else{
        mention.chop(1);
        QMessageBox questmsg;
        questmsg.setWindowTitle("提示");
        questmsg.setText("以下為還沒填入的項目");
        questmsg.setInformativeText(mention+"\n\n請問仍要輸入到資料庫嗎");
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
            if(submitdata.exec()){
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
}
