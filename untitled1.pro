#-------------------------------------------------
#
# Project created by QtCreator 2015-06-14T14:05:47
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QT       += xlsx
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = untitled1
TEMPLATE = app
INCLUDEPATH = D:/libxl-3.6.2.0/include_cpp
LIBS += D:/libxl-3.6.2.0/lib/libxl.lib
QMAKE_POST_LINK +=$$quote(cmd /c copy /y D:\libxl-3.6.2.0\bin\libxl.dll .)
SOURCES += main.cpp \
    mainwindow.cpp \
    menu.cpp \
    studentmenu.cpp \
    addanewstudent.cpp \
    changepicture.cpp \
    excel.cpp \
    searchstudent.cpp \
    conditionwidget.cpp \
    deletebutton.cpp \
    showastudent.cpp \
    checkbox_delegate.cpp \
    addstudenttocourse.cpp \
    mysqlrelationaltablemodel.cpp \
    choosestudenttocoursecoursemodel.cpp \
    checkboxidentitymodel.cpp
        mainwindow.cpp
HEADERS  += mainwindow.h \
    menu.h \
    studentmenu.h \
    teachermenu.h \
    addanewstudent.h \
    changepicture.h \
    excel2.h \
    searchstudent.h \
    conditionwidget.h \
    deletebutton.h \
    conditionset.h \
    showastudent.h \
    addstudenttocourse.h \
    checkbox_delegate.h \
    mysqlrelationaltablemodel.h \
    choosestudenttocoursecoursemodel.h \
    checkboxidentitymodel.h
