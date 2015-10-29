#ifndef ADDACOURSE
#define ADDACOURSE

#endif // ADDACOURSE

#include <QtWidgets>

class AddANewCourse : public QFrame{
    Q_OBJECT
public slots:
    void submit();
public:
    AddANewCourse();
private:
    void init();
    QCompleter *completer;
    QHBoxLayout* mainlayout;
    QFormLayout* formlayout1;
    QFrame* formwidget1;
    QLineEdit* coursenumberinput;
    QComboBox* coursetypeinput;
    QLineEdit* coursenameinput;
    QLineEdit* yearinput;
    QLineEdit* creditinput;
    QComboBox* semesterinput;
    QLineEdit* teacherinput;
    QPushButton* submitbutton;
};
