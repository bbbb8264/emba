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
    malebutton = new QRadioButton("�k");
    femalebutton = new QRadioButton("�k");
    addressinput = new QTextEdit;
    emailinput = new QTextEdit;
    birthdayinput = new QDateEdit;
    contactgroup = new QGroupBox("�p���覡");
    contactlayout = new QFormLayout;
    telephonedayinput = new QTextEdit;
    telephonenightinput = new QTextEdit;
    mobileinput = new QTextEdit;
    graduateschoolinput = new QTextEdit;
    graduatedepartmentinput = new QTextEdit;
    companygroup = new QGroupBox("�A�ȳ��");
    companylayout = new QFormLayout;
    companynameinput = new QTextEdit;
    companypositioninput = new QTextEdit;
    creditgroup = new QGroupBox;
    creditlayout = new QHBoxLayout;
    credityes = new QRadioButton("�O");
    creditno = new QRadioButton("�_");
    submitbutton = new QPushButton("�e�X");
    backbutton = new QPushButton("��^");
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
    font.setFamily("�L�n������");
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
    formlayout1->addRow("�q�T�a�}�G",addressinput);
    formlayout1->addRow("�q�l�l��G",emailinput);
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

    contactlayout->addRow("�q��(��)�G",telephonedayinput);
    contactlayout->addRow("�q��(�])�G",telephonenightinput);
    contactlayout->addRow("����G",mobileinput);
    contactgroup->setLayout(contactlayout);

    companylayout->addRow("���q�W�١G",companynameinput);
    companylayout->addRow("¾��G",companypositioninput);
    companygroup->setLayout(companylayout);

    formlayout2->addRow("�Ǧ��Ҹ��X�G",ticketnumberinput);
    formlayout2->addRow("�Ǹ��G",studentnumberinput);
    formlayout2->addRow("���~�żơG",graduatelevel);
    formlayout2->addRow("�m�W",nameinput);
    formlayout2->addRow("�ʧO�G",gendergroup);
    formlayout2->addRow("�ͤ�G",birthdayinput);
    formlayout2->addRow("���~�ǮաG",graduateschoolinput);
    formlayout2->addRow("���~��t�G",graduatedepartmentinput);
    formlayout2->addRow("�Ҧb�a�ϡG",locationinput);
    formwidget2->setLayout(formlayout2);
    formwidget2->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);

    creditlayout->addWidget(credityes);
    creditlayout->addWidget(creditno);
    creditgroup->setLayout(creditlayout);

    locationinput->setMinimumWidth(120);

    formlayout3->addRow("���Ҩ����O�G",studentidentityinput);
    formlayout3->addRow("�ѥ[�Ǥ��Z�G",creditgroup);
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
        if(query.value(7).toString() == "�k"){
            malebutton->setChecked(true);
        }else if(query.value(7).toString() == "�k"){
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
        mentionstring += "�m�W\n";
    }else{
        submit.bindValue(":name",nameinput->toPlainText());
        submitname = true;
    }
    if(locationinput->toPlainText().isEmpty()){
        mentionstring += "�Ҧb�a��\n";
    }else{
        submit.bindValue(":location",locationinput->toPlainText());
    }
    submit.bindValue(":birthday",birthdayinput->text());
    if(studentidentityinput->toPlainText().isEmpty()){
        mentionstring += "���Ҩ����O\n";
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
        mentionstring += "�j�Y��\n";
    }
    if(!malebutton->isChecked() && !femalebutton->isChecked()){
        mentionstring += "�ʧO\n";
    }else if(malebutton->isChecked()){
        submit.bindValue(":gender","�k");
        submitgender = true;
    }else if(femalebutton->isChecked()){
        submit.bindValue(":gender","�k");
        submitgender = true;
    }
    if(addressinput->toPlainText().isEmpty()){
        mentionstring += "�q�T�a�}\n";
    }else{
        submit.bindValue(":address",addressinput->toPlainText());
    }
    if(emailinput->toPlainText().isEmpty()){
        mentionstring += "�q�l�l��\n";
    }else{
        submit.bindValue(":email",emailinput->toPlainText());
    }
    if(telephonedayinput->toPlainText().isEmpty()){
        mentionstring += "�q��(��)\n";
    }else{
        submit.bindValue(":telephoneday",telephonedayinput->toPlainText());
    }
    if(telephonenightinput->toPlainText().isEmpty()){
        mentionstring += "�q��(�])\n";
    }else{
        submit.bindValue(":telephonenight",telephonenightinput->toPlainText());
    }
    if(mobileinput->toPlainText().isEmpty()){
        mentionstring += "������X\n";
    }else{
        submit.bindValue(":mobile",mobileinput->toPlainText());
    }
    if(graduateschoolinput->toPlainText().isEmpty()){
        mentionstring += "���~�Ǯ�\n";
    }else{
        submit.bindValue(":graduateschool",graduateschoolinput->toPlainText());
    }
    if(graduatedepartmentinput->toPlainText().isEmpty()){
        mentionstring += "���~��t\n";
    }else{
        submit.bindValue(":graduatedepartment",graduatedepartmentinput->toPlainText());
    }
    if(companynameinput->toPlainText().isEmpty()){
        mentionstring += "���q�W��\n";
    }else{
        submit.bindValue(":companyname",companynameinput->toPlainText());
    }
    if(companypositioninput->toPlainText().isEmpty()){
        mentionstring += "�ثe¾��\n";
    }else{
        submit.bindValue(":currentposition",companypositioninput->toPlainText());
    }
    if(!credityes->isChecked() && !creditno->isChecked()){
        mentionstring += "�ѥ[�Ǥ��Z\n";
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
        mentionstring.chop(1);
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
            if(submit.exec()){
                QImage icon;
                icon.load("right.png");
                icon = icon.scaledToWidth(50);
                msg.setWindowTitle("����");
                msg.setIconPixmap(QPixmap::fromImage(icon));
                msg.setText("��Ƥw�g�J");
                msg.exec();
            }else{
                QImage icon;
                icon.load("D:/error.png");
                icon = icon.scaledToWidth(50);
                msg.setWindowTitle("���~");
                msg.setIconPixmap(QPixmap::fromImage(icon));
                msg.setText("��Ƽg�J����");
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
