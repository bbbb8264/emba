#include "showastudent.h"
ShowAStudent::ShowAStudent(QString number){
    studentnumber = number;
    setquery();
    init();
    setpicture();

    picturelabel->setFrameShadow(QFrame::Raised);
    picturelabel->setFrameShape(QFrame::Box);
    picturelabel->setLineWidth(3);
    picturelabel->setMidLineWidth(3);
    picturelabel->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);

    studentnumberlabel->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);

    namelabel->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);

    studentbasicdatalayout->addWidget(studentnumberlabel);
    studentbasicdatalayout->addWidget(namelabel);
    studentbasicdatalayout->setAlignment(Qt::AlignTop);

    QPalette pal = studentbasicdatawidget->palette();
    pal.setColor(QPalette::Background, Qt::white);
    studentbasicdatawidget->setAutoFillBackground(true);
    studentbasicdatawidget->setPalette(pal);
    QFont font;
    font.setPixelSize(20);
    font.setFamily("微軟正黑體");
    studentbasicdatawidget->setFont(font);
    studentbasicdatawidget->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);
    studentbasicdatawidget->setFixedWidth(306);
    studentbasicdatawidget->setLayout(studentbasicdatalayout);

    basicinformationlayout->setAlignment(Qt::AlignTop);
    basicinformationlayout->addWidget(picturelabel);
    basicinformationlayout->addWidget(studentbasicdatawidget);
    basicinformationwidget->setLayout(basicinformationlayout);

    mainlayout->addWidget(basicinformationwidget);
    setLayout(mainlayout);
}
void ShowAStudent::init(){
    mainlayout = new QHBoxLayout;
    basicinformationwidget = new QWidget;
    basicinformationlayout = new QVBoxLayout;
    studentbasicdatawidget = new QWidget;
    studentbasicdatalayout = new QVBoxLayout;
    informationwidget = new QWidget;
    informationlayout = new QVBoxLayout;
    picturelabel = new QLabel;
    studentnumberlabel = new QLabel("學號 : "+studentnumber);
    namelabel = new QLabel("姓名 : "+query.value(1).toString());
    gradelabel = new QLabel;
    departmentlabel = new QLabel;
}
void ShowAStudent::setpicture(){
    QByteArray byteArray;
    byteArray = query.value(2).toByteArray();
    img.loadFromData(byteArray);
    picturelabel->setPixmap(QPixmap::fromImage(img));
}
void ShowAStudent::setquery(){
    query.prepare( "select * from student where studentnumber = :studentnumber" );
    query.bindValue(":studentnumber",studentnumber);
    query.exec();
    query.next();
}
