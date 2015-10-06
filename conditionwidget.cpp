#include "conditionwidget.h"
#include "deletebutton.h"
#include "conditionset.h"
ConditionWidget::ConditionWidget(conditionset* current)
{
    parent = current;
    init();

    target->setFrameShape(QFrame::StyledPanel);
    target->setFrameShadow(QFrame::Raised);
    target->setAlignment(Qt::AlignCenter);
    target->setMinimumHeight(25);
    target->setMaximumHeight(40);

    operate->setFrameShape(QFrame::StyledPanel);
    operate->setFrameShadow(QFrame::Raised);
    operate->setAlignment(Qt::AlignCenter);
    operate->setMinimumHeight(25);
    operate->setMaximumHeight(40);

    expression->setFrameShape(QFrame::StyledPanel);
    expression->setFrameShadow(QFrame::Raised);
    expression->setAlignment(Qt::AlignCenter);
    expression->setMinimumHeight(25);
    expression->setMaximumHeight(40);

    layout->addWidget(closebutton);
    layout->addWidget(target);
    layout->addWidget(operate);
    layout->addWidget(expression);

    setLayout(layout);
    setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Expanding);
    setMaximumHeight(50);
    setFrameShape(QFrame::StyledPanel);
}
void ConditionWidget::init()
{
    layout = new QHBoxLayout;
    target = new QLabel(parent->target);
    operate = new QLabel(parent->operate);
    expression = new QLabel(parent->expression);
    closebutton = new DeleteButton(parent);
}
bool ConditionWidget::event(QEvent* e)
{
    if (e->type() == QEvent::Enter)
    {
        closebutton->setFrameShadow(QFrame::Raised);
    }else if(e->type() == QEvent::Leave){
        closebutton->setFrameShadow(QFrame::Plain);
    }
    return QWidget::event(e);
}
