#include "teacherpersonalwindowmodifydata.h"
#pragma execution_character_set("utf-8")
void TeacherPersonalWindowModiyfyData::init(){
    teachernumberlabel = new QLabel;
    teachernamelabel = new QLineEdit;
    departmentlabel = new QComboBox;
    emaillabel = new QLineEdit;
    phonelabel = new QLineEdit;
    uplayout = new QFormLayout;
    upwidget = new QWidget;
    mainlayout = new QVBoxLayout;
    buttonlayout = new QHBoxLayout;
    buttonwidget = new QWidget;
    backbutton = new QPushButton("返回");
    submitbutton = new QPushButton("送出");
}
TeacherPersonalWindowModiyfyData::TeacherPersonalWindowModiyfyData(QString teachernumber){
    this->teachernumber = teachernumber;

    init();

    query.prepare( "select teachername, departmentnumber, email, phone from teacher where teachernumber = '"+teachernumber+"'" );
    query.exec();
    query.next();

    msg.layout()->setMargin(50);
    msg.layout()->setSpacing(20);
    QFont font;
    font.setFamily("微軟正黑體");
    font.setPixelSize(15);
    msg.setFont(font);

    setInitialValue();

    teachernumberlabel->setStyleSheet("background-color:#fbfbfb;font-size:25px;font-family:Microsoft JhengHei");
    teachernamelabel->setStyleSheet("background-color:#ffffff;font-size:25px;font-family:Microsoft JhengHei");
    departmentlabel->setStyleSheet("background-color:#ffffff;font-size:25px;font-family:Microsoft JhengHei");
    emaillabel->setStyleSheet("background-color:#ffffff;font-size:25px;font-family:Microsoft JhengHei");
    phonelabel->setStyleSheet("background-color:#ffffff;font-size:25px;font-family:Microsoft JhengHei");

    uplayout->addRow("教職員編號：",teachernumberlabel);
    uplayout->addRow("姓名：",teachernamelabel);
    uplayout->addRow("所屬系所：",departmentlabel);
    uplayout->addRow("電子郵件：",emaillabel);
    uplayout->addRow("分機(電話)：",phonelabel);

    upwidget->setLayout(uplayout);
    uplayout->setMargin(50);
    uplayout->setSpacing(50);
    upwidget->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);

    backbutton->setFixedWidth(150);
    backbutton->setFixedHeight(45);
    submitbutton->setFixedWidth(150);
    submitbutton->setFixedHeight(45);
    connect(submitbutton,SIGNAL(clicked()),this,SLOT(submitdata()));

    buttonlayout->addWidget(backbutton);
    buttonlayout->addWidget(submitbutton);
    buttonwidget->setLayout(buttonlayout);
    buttonwidget->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Maximum);

    mainlayout->addWidget(upwidget);
    mainlayout->setAlignment(upwidget,Qt::AlignHCenter);
    mainlayout->addWidget(buttonwidget);
    mainlayout->setSpacing(20);
    mainlayout->setMargin(20);
    setFixedWidth(800);
    setStyleSheet("background-color:#fbfbfb;font-size:25px;font-family:Microsoft JhengHei");
    //setStyleSheet("border: 1px solid black");
    setFrameShape(QFrame::Panel);
    setFrameShadow(QFrame::Raised);
    setLayout(mainlayout);
    setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Minimum);
}
void TeacherPersonalWindowModiyfyData::setInitialValue(){
    teachernumberlabel->setText(teachernumber);
    if(!query.value(0).toString().isEmpty()){
        teachernamelabel->setText(query.value(0).toString());
    }
    QSqlQuery finddepartment("select * from department");
    finddepartment.exec();
    QStringList departmentlist;
    int currentindex = -1;
    for(int i = 0;i < finddepartment.size();i++){
        finddepartment.next();
        departmentlist << finddepartment.value(0).toString()+" "+finddepartment.value(1).toString();
        if(finddepartment.value(0).toString() == query.value(1).toString()){
            currentindex = i;
        }
    }
    departmentlabel->addItems(departmentlist);
    departmentlabel->setCurrentIndex(currentindex);
    if(!query.value(2).toString().isEmpty()){
        emaillabel->setText(query.value(2).toString());
    }
    if(!query.value(3).toString().isEmpty()){
        phonelabel->setText(query.value(3).toString());
    }
}
void TeacherPersonalWindowModiyfyData::submitdata(){
    QString mention;
    QSqlQuery submit;
    submit.prepare("update teacher set teachername = :teachername, departmentnumber = :departmentnumber, email = :email, phone = :phone where teachernumber = '"+teachernumber+"'");
    if(teachernamelabel->text().isEmpty()){
        msg.setWindowTitle("警告");
        msg.setIcon(QMessageBox::Critical);
        msg.setText("老師姓名不可以為空");
        msg.exec();
        return;
    }else{
        submit.bindValue(":teachername",teachernamelabel->text());
    }
    submit.bindValue(":departmentnumber",departmentlabel->currentText().split(" ").at(0));
    if(emaillabel->text().isEmpty()){
        mention += "電子郵件\n";
    }else{
        if(emaillabel->text().contains('@')){
            if(emaillabel->text().split("@").length() == 2){
                if(emaillabel->text().split("@").at(0).length() && emaillabel->text().split("@").at(1).length()){
                     submit.bindValue(":email",emaillabel->text());
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
    if(phonelabel->text().isEmpty()){
        mention += "分機(電話)\n";
    }else{
        submit.bindValue(":phone",phonelabel->text());
    }
    if(mention.isEmpty()){
        if(submit.exec()){
            QImage icon;
            icon.load("right.png");
            icon = icon.scaledToWidth(50);
            msg.setWindowTitle("完成");
            msg.setIconPixmap(QPixmap::fromImage(icon));
            msg.setText("老師資料修改成功");
            msg.exec();
            emit submitedsuccess();
        }else{
            QImage icon;
            icon.load("error.png");
            icon = icon.scaledToWidth(50);
            msg.setWindowTitle("錯誤");
            msg.setIconPixmap(QPixmap::fromImage(icon));
            msg.setText("老師資料修改失敗");
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
            if(submit.exec()){
                QImage icon;
                icon.load("right.png");
                icon = icon.scaledToWidth(50);
                msg.setWindowTitle("完成");
                msg.setIconPixmap(QPixmap::fromImage(icon));
                msg.setText("老師資料修改成功");
                msg.exec();
                emit submitedsuccess();
            }else{
                QImage icon;
                icon.load("error.png");
                icon = icon.scaledToWidth(50);
                msg.setWindowTitle("錯誤");
                msg.setIconPixmap(QPixmap::fromImage(icon));
                msg.setText("老師資料修改失敗");
                msg.exec();
            }
        }
    }
}
