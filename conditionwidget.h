#ifndef CONDITIONWIDGET
#define CONDITIONWIDGET
#include <QtWidgets>
struct conditionset;
class DeleteButton;
class ConditionWidget : public QFrame
{
public:
    ConditionWidget(conditionset* current);
    DeleteButton* closebutton;
private:
    bool event(QEvent* e) override;
    void init();
    conditionset* parent;
    QLabel* target;
    QLabel* operate;
    QLabel* expression;
    QHBoxLayout* layout;
};
#endif // CONDITIONWIDGET
