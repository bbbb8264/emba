#include "studentpersonalwindowmodifydata.h"
#include "changepicture.h"
#pragma execution_character_set("utf-8")
void StudentPersonalWindowModiyfyData::init(){
    formlayout1 = new QFormLayout;
    formlayout2 = new QFormLayout;
    formlayout3 = new QFormLayout;
    formwidget1 = new QWidget;
    formwidget2 = new QWidget;
    formwidget3 = new QWidget;
    uplayout = new QHBoxLayout;
    upwidget = new QWidget;
    mainlayout = new QVBoxLayout;
    ticketnumberinput = new QLabel;
    studentnumberinput = new QLabel;
    locationinput = new QTextEdit;
    studentidentityinput = new QTextEdit;
    graduatelevel = new QLabel;
    nameinput = new QTextEdit;
    pictureinput = new ChangePicture;
    gendergroup = new QGroupBox;
    genderlayout = new QHBoxLayout;
    malebutton = new QRadioButton("男");
    femalebutton = new QRadioButton("女");
    addressinput = new QTextEdit;
    emailinput = new QTextEdit;
    birthdayinput = new QDateEdit;
    contactgroup = new QGroupBox("聯絡方式");
    contactlayout = new QFormLayout;
    telephonedayinput = new QTextEdit;
    telephonenightinput = new QTextEdit;
    mobileinput = new QTextEdit;
    graduateschoolinput = new QTextEdit;
    graduatedepartmentinput = new QTextEdit;
    companygroup = new QGroupBox("服務單位");
    companylayout = new QFormLayout;
    companynameinput = new QTextEdit;
    companypositioninput = new QTextEdit;
    creditgroup = new QGroupBox;
    creditlayout = new QHBoxLayout;
    credityes = new QRadioButton("是");
    creditno = new QRadioButton("否");
    submitbutton = new QPushButton("送出");
    backbutton = new QPushButton("返回");
    buttonlayout = new QHBoxLayout;
    buttonwidget = new QWidget;
    graduatelevelerror = new QLabel;
    picturelayout = new QVBoxLayout;
    picturewidget = new QWidget;
}
StudentPersonalWindowModiyfyData::StudentPersonalWindowModiyfyData(QString studentnumber){
    this->studentnumber = studentnumber;

    init();

    query.prepare( "select * from student where studentnumber = :studentnumber" );
    query.bindValue(":studentnumber",studentnumber);
    query.exec();
    query.next();

    msg.layout()->setMargin(20);
    msg.layout()->setSpacing(10);
    QFont font;
    font.setFamily("微軟正黑體");
    font.setPixelSize(15);
    msg.setFont(font);

    setInitialValue();

    setTextEditSize(locationinput);
    setTextEditSize(nameinput);
    setTextEditSize(addressinput);
    setTextEditSize(emailinput);
    setTextEditSize(nameinput);
    setTextEditSize(telephonedayinput);
    setTextEditSize(telephonenightinput);
    setTextEditSize(mobileinput);
    setTextEditSize(companynameinput);
    setTextEditSize(companypositioninput);
    setTextEditSize(graduateschoolinput);
    setTextEditSize(graduatedepartmentinput);
    setTextEditSize(studentidentityinput);

    picturelayout->addWidget(pictureinput);
    picturewidget->setLayout(picturelayout);
    picturelayout->setAlignment(pictureinput,Qt::AlignHCenter | Qt::AlignTop);
    picturewidget->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
    picturewidget->setMinimumHeight(300);

    formlayout1->addRow(picturewidget);
    formlayout1->addRow("通訊地址：",addressinput);
    formlayout1->addRow("電子郵件：",emailinput);
    formwidget1->setLayout(formlayout1);
    formwidget1->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);
    formlayout1->setFormAlignment(Qt::AlignHCenter);
    formlayout1->setAlignment(pictureinput,Qt::AlignHCenter);
    formlayout1->setAlignment(addressinput,Qt::AlignBottom);
    formlayout1->setAlignment(emailinput,Qt::AlignBottom);

    graduatelevelerror->setStyleSheet("color:red;font-size:15px;font-family:Microsoft JhengHei");
    graduatelevelerror->setVisible(false);
    graduatelevel->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);
    graduatelevel->setFixedHeight(36);
    studentnumberinput->setFixedHeight(36);
    ticketnumberinput->setFixedHeight(36);
    birthdayinput->setFixedHeight(36);
    birthdayinput->setStyleSheet("background-color:#ffffff;font-size:20px;font-family:Microsoft JhengHei");

    genderlayout->addWidget(malebutton);
    genderlayout->addWidget(femalebutton);
    gendergroup->setLayout(genderlayout);

    contactlayout->addRow("電話(日)：",telephonedayinput);
    contactlayout->addRow("電話(夜)：",telephonenightinput);
    contactlayout->addRow("手機：",mobileinput);
    contactgroup->setLayout(contactlayout);

    companylayout->addRow("公司名稱：",companynameinput);
    companylayout->addRow("職位：",companypositioninput);
    companygroup->setLayout(companylayout);

    formlayout2->addRow("準考證號碼：",ticketnumberinput);
    formlayout2->addRow("學號：",studentnumberinput);
    formlayout2->addRow("畢業級數：",graduatelevel);
    formlayout2->addRow("姓名",nameinput);
    formlayout2->addRow("性別：",gendergroup);
    formlayout2->addRow("生日：",birthdayinput);
    formlayout2->addRow("畢業學校：",graduateschoolinput);
    formlayout2->addRow("畢業科系：",graduatedepartmentinput);
    formlayout2->addRow("所在地區：",locationinput);
    formwidget2->setLayout(formlayout2);
    formwidget2->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);

    creditlayout->addWidget(credityes);
    creditlayout->addWidget(creditno);
    creditgroup->setLayout(creditlayout);

    locationinput->setMinimumWidth(120);

    formlayout3->addRow("報考身分別：",studentidentityinput);
    formlayout3->addRow("參加學分班：",creditgroup);
    formlayout3->addRow(companygroup);
    formlayout3->addRow(contactgroup);
    formwidget3->setLayout(formlayout3);
    formwidget3->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);

    uplayout->addWidget(formwidget1);
    uplayout->addWidget(formwidget2);
    uplayout->addWidget(formwidget3);
    upwidget->setLayout(uplayout);
    uplayout->setMargin(5);
    uplayout->setAlignment(formwidget1,Qt::AlignTop);
    uplayout->setAlignment(formwidget2,Qt::AlignTop);
    uplayout->setAlignment(formwidget3,Qt::AlignTop);
    upwidget->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);

    backbutton->setFixedWidth(150);
    backbutton->setFixedHeight(36);
    submitbutton->setFixedWidth(150);
    submitbutton->setFixedHeight(36);
    connect(submitbutton,SIGNAL(clicked()),this,SLOT(submitdata()));

    buttonlayout->addWidget(backbutton);
    buttonlayout->addWidget(submitbutton);
    buttonwidget->setLayout(buttonlayout);
    buttonwidget->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Maximum);

    mainlayout->addWidget(upwidget);
    mainlayout->addWidget(buttonwidget);
    mainlayout->setSpacing(20);
    setStyleSheet("background-color:#fbfbfb;font-size:20px;font-family:Microsoft JhengHei");
    //setStyleSheet("border: 1px solid black");
    setFrameShape(QFrame::Panel);
    setFrameShadow(QFrame::Raised);
    setLayout(mainlayout);
    setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);
}
void StudentPersonalWindowModiyfyData::setTextEditSize(QTextEdit* textedit){
    textedit->setFixedHeight(36);
    textedit->setStyleSheet("background-color:#ffffff;font-size:20px;font-family:Microsoft JhengHei");
}
void StudentPersonalWindowModiyfyData::setInitialValue(){
    studentnumberinput->setText(studentnumber);
    ticketnumberinput->setText(query.value(0).toString());
    locationinput->setText(query.value(2).toString());
    studentidentityinput->setText(query.value(3).toString());
    graduatelevel->setText(query.value(4).toString());
    nameinput->setText(query.value(5).toString());
    if(!query.value(6).isNull()){
        QByteArray byteArray;
        byteArray = query.value(6).toByteArray();
        pictureinput->img.loadFromData(byteArray);
        pictureinput->setPixmap(QPixmap::fromImage(pictureinput->img));
        pictureinput->pictureinsert = true;
    }
    if(!query.value(7).isNull()){
        if(query.value(7).toString() == "男"){
            malebutton->setChecked(true);
        }else if(query.value(7).toString() == "女"){
            femalebutton->setChecked(true);
        }
    }
    addressinput->setText(query.value(8).toString());
    emailinput->setText(query.value(9).toString());
    birthdayinput->setDate(query.value(10).toDate());
    telephonedayinput->setText(query.value(11).toString());
    telephonenightinput->setText(query.value(12).toString());
    mobileinput->setText(query.value(13).toString());
    graduateschoolinput->setText(query.value(14).toString());
    graduatedepartmentinput->setText(query.value(15).toString());
    companynameinput->setText(query.value(16).toString());
    companypositioninput->setText(query.value(17).toString());
    if(!query.value(18).isNull()){
        if(query.value(18).toInt()){
            credityes->setChecked(true);
        }else if(!query.value(18).toInt()){
            creditno->setChecked(true);
        }
    }
}
void StudentPersonalWindowModiyfyData::submitdata(){
    QSqlQuery submit;
    QString mentionstring = "";
    bool submitpicture = false;
    bool submitname = false;
    bool submitgender = false;
    bool submitstudentidentity = false;
    submit.prepare("update student set birthday = :birthday , name = :name , direction = :location , studentidentity = :studentidentity , picture = :picture , gender = :gender , address = :address , emailaddress = :email , telephoneday = :telephoneday , telephonenight = :telephonenight , mobile = :mobile , graduateschool = :graduateschool , graduatedepartment = :graduatedepartment , companyname = :companyname , currentposition = :currentposition , creditclass = :credit where studentnumber = :studentnumber");
    submit.bindValue(":studentnumber",studentnumber);
    if(nameinput->toPlainText().isEmpty()){
        mentionstring += "姓名\n";
    }else{
        submit.bindValue(":name",nameinput->toPlainText());
        submitname = true;
    }
    if(locationinput->toPlainText().isEmpty()){
        mentionstring += "所在地區\n";
    }else{
        submit.bindValue(":location",locationinput->toPlainText());
    }
    submit.bindValue(":birthday",birthdayinput->text());
    if(studentidentityinput->toPlainText().isEmpty()){
        mentionstring += "報考身分別\n";
    }else{
        submitstudentidentity = true;
        submit.bindValue(":studentidentity",studentidentityinput->toPlainText());
    }
    if(pictureinput->pictureinsert){
        QByteArray byteArray;
        QBuffer buffer(&byteArray);
        pictureinput->img.save(&buffer, "JPG"); // writes the image in PNG format inside the buffer
        submit.bindValue(":picture",byteArray);
        submitpicture = true;
    }else{
        mentionstring += "大頭照\n";
    }
    if(!malebutton->isChecked() && !femalebutton->isChecked()){
        mentionstring += "性別\n";
    }else if(malebutton->isChecked()){
        submit.bindValue(":gender","男");
        submitgender = true;
    }else if(femalebutton->isChecked()){
        submit.bindValue(":gender","女");
        submitgender = true;
    }
    if(addressinput->toPlainText().isEmpty()){
        mentionstring += "通訊地址\n";
    }else{
        submit.bindValue(":address",addressinput->toPlainText());
    }
    if(emailinput->toPlainText().isEmpty()){
        mentionstring += "電子郵件\n";
    }else{
        submit.bindValue(":email",emailinput->toPlainText());
    }
    if(telephonedayinput->toPlainText().isEmpty()){
        mentionstring += "電話(日)\n";
    }else{
        submit.bindValue(":telephoneday",telephonedayinput->toPlainText());
    }
    if(telephonenightinput->toPlainText().isEmpty()){
        mentionstring += "電話(夜)\n";
    }else{
        submit.bindValue(":telephonenight",telephonenightinput->toPlainText());
    }
    if(mobileinput->toPlainText().isEmpty()){
        mentionstring += "手機號碼\n";
    }else{
        submit.bindValue(":mobile",mobileinput->toPlainText());
    }
    if(graduateschoolinput->toPlainText().isEmpty()){
        mentionstring += "畢業學校\n";
    }else{
        submit.bindValue(":graduateschool",graduateschoolinput->toPlainText());
    }
    if(graduatedepartmentinput->toPlainText().isEmpty()){
        mentionstring += "畢業科系\n";
    }else{
        submit.bindValue(":graduatedepartment",graduatedepartmentinput->toPlainText());
    }
    if(companynameinput->toPlainText().isEmpty()){
        mentionstring += "公司名稱\n";
    }else{
        submit.bindValue(":companyname",companynameinput->toPlainText());
    }
    if(companypositioninput->toPlainText().isEmpty()){
        mentionstring += "目前職位\n";
    }else{
        submit.bindValue(":currentposition",companypositioninput->toPlainText());
    }
    if(!credityes->isChecked() && !creditno->isChecked()){
        mentionstring += "參加學分班\n";
    }else if(credityes->isChecked()){
        submit.bindValue(":credit",1);
    }else if(creditno->isChecked()){
        submit.bindValue(":credit",0);
    }
    if(mentionstring.isEmpty()){
        if(submit.exec()){
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
        mentionstring.chop(1);
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
            if(submit.exec()){
                QImage icon;
                icon.load("right.png");
                icon = icon.scaledToWidth(50);
                msg.setWindowTitle("完成");
                msg.setIconPixmap(QPixmap::fromImage(icon));
                msg.setText("資料已寫入");
                msg.exec();
            }else{
                QImage icon;
                icon.load("D:/error.png");
                icon = icon.scaledToWidth(50);
                msg.setWindowTitle("錯誤");
                msg.setIconPixmap(QPixmap::fromImage(icon));
                msg.setText("資料寫入失敗");
                msg.exec();
            }
        }
    }
    if(submitpicture)
        emit submitedpicture();
    if(submitname)
        emit submitedname();
    if(submitgender)
        emit submitedgender();
    if(submitstudentidentity)
        emit submitedstudentidentity();
}
