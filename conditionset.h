#ifndef CONDITIONSET
#define CONDITIONSET
#include <QtWidgets>
class ConditionWidget;
struct conditionset
{
    conditionset* pre;
    conditionset* next;
    QString filter;
    QString target;
    QString operate;
    QString expression;
    ConditionWidget* condition;
};

#endif // CONDITIONSET
