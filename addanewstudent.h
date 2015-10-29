#ifndef ADDANEWSTUDENT
#define ADDANEWSTUDENT

#endif // ADDANEWSTUDENTD

#include "changepicture.h"
#include <QtWidgets>
class AddANewStudent : public QFrame
{
    Q_OBJECT
public slots:
    void submited();
    void deleteremind();
public:
    AddANewStudent();
private:
    void init();
    void setting();
    void loadpicture();
    void setformfont();
    int pictureMaxHeightPx;
    int pictureMaxWidthPx;
    bool pictureSizeLimit;
    QMessageBox msg;
    QHBoxLayout* mainlayout;
    QFormLayout* formlayout;
    QWidget* formwidget;
    ChangePicture* picturewidget;
    QLabel* remind;
    QWidget* mainpicturewidget;
    QVBoxLayout* mainpicturelayout;
    QLineEdit* studentnumberedit;
    QLineEdit* nameedit;
    QHBoxLayout* genderlayout;
    QGroupBox* gendergroup;
    QDateEdit* dateinput;
    QRadioButton* male;
    QRadioButton* female;
    QGroupBox* contactgroup;
    QFormLayout* contactformlayout;
    QLineEdit* mobile;
    QLineEdit* telephoneday;
    QLineEdit* telephonenight;
    QLineEdit* direction;
    QLineEdit* ticketnumber;
    QLineEdit* studentidentity;
    QLineEdit* graduatelevel;
    QLineEdit* address;
    QLineEdit* emailaddress;
    QLineEdit* graduateschool;
    QLineEdit* graduatedepartment;
    QRadioButton* creditclassbuttonyes;
    QRadioButton* creditclassbuttonno;
    QGroupBox* creditclassgroup;
    QHBoxLayout* creditclasslayout;
    QGroupBox* companygroup;
    QFormLayout* companyformlayout;
    QLineEdit* companyname;
    QLineEdit* companyposition;
    QFormLayout* formlayout2;
    QWidget* formwidget2;
    QWidget* submitwidget;
    QHBoxLayout* submitlayout;
    QPushButton* submitbutton;
    QString warningmessage;
    QString fatalmessage;
};
