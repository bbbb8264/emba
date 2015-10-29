#ifndef ADDANEWTHESIS
#define ADDANEWTHESIS

#endif // ADDANEWTHESIS

#include <QtWidgets>

class AddANewThesis : public QFrame{
public:
    AddANewThesis();
private:
    void init();
    void setlineeditsize(QLineEdit*);
    QFormLayout* mainlayout;
    QLineEdit* studentinput;
    QLineEdit* thesisnameinput;
    QLineEdit* yearinput;
    QVector<QLineEdit*> teacherinputvector;
    QPushButton* addteacherbutton;
    QPushButton* submitbutton;
};
