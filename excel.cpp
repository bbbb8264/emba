#include "excel2.h"
excel2::excel2()
{
    QXlsx::Document xlsx("D:/Test.xlsx");
//    qDebug() << xlsx.cellAt(0,0)->cellType();
    qDebug() << "123";
    qDebug() << "set";
    qDebug() << xlsx.cellAt(1,1)->cellType();
}
