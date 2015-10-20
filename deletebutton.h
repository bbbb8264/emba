#ifndef DELETEBUTTON
#define DELETEBUTTON
#include <QtWidgets>
struct conditionset;
class DeleteButton : public QLabel
{
    Q_OBJECT
signals:
    void click(conditionset*&);
public:
    DeleteButton(conditionset*);
private:
    conditionset* parent;
    void mousePressEvent(QMouseEvent * ev) override;
    void mouseReleaseEvent(QMouseEvent * ev) override;
};

#endif // DELETEBUTTON
