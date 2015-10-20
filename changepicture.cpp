#include "changepicture.h"
#pragma execution_character_set("utf-8")
ChangePicture::ChangePicture()
{
    img.load("nullperson.jpg");
    img = img.scaledToWidth(250);
    setPixmap(QPixmap::fromImage(img));
    setFrameStyle(QFrame::Panel | QFrame::Raised);
    setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);
}

bool ChangePicture::event(QEvent* e)
{
    if(!pictureinsert)
    {
        if (e->type() == QEvent::Enter)
        {
            img.load("nullpersonup.jpg");
            img = img.scaledToWidth(250);
            setPixmap(QPixmap::fromImage(img));
        }else if(e->type() == QEvent::Leave){
            img.load("nullperson.jpg");
            img = img.scaledToWidth(250);
            setPixmap(QPixmap::fromImage(img));
        }
    }
    return QWidget::event(e);
}
void ChangePicture::mousePressEvent(QMouseEvent * ev)
{
    setFrameStyle(QFrame::Panel | QFrame::Sunken);
}
void ChangePicture::mouseReleaseEvent(QMouseEvent * ev)
{
    setFrameStyle(QFrame::Panel | QFrame::Raised);
    QString path = getpicturepath();
    if(newpictureinsert){
        img.load(path);
        img = img.scaledToWidth(250);
        setPixmap(QPixmap::fromImage(img));
    }
}
QString ChangePicture::getpicturepath(){
    QFileDialog* filedialog = new QFileDialog;
    filedialog->setNameFilter("Image files (*.png *.xpm *.jpg)");
    QString path;
    if(filedialog->exec() == QDialog::Accepted) {
        newpictureinsert = true;
        pictureinsert = true;
        path = filedialog->selectedFiles()[0];
        emit inserted();
     } else {
        newpictureinsert = false;
        QMessageBox msg(QMessageBox::Warning,"����","�A�S����ܥ���Ϥ�");
        msg.layout()->setMargin(15);
        msg.layout()->setSpacing(10);
        QFont font;
        font.setPixelSize(15);
        font.setFamily("�L�n������");
        msg.setFont(font);
        msg.exec();
     }

    return path;
}
