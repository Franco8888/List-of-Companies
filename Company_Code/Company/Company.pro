#-------------------------------------------------
#
# Project created by QtCreator 2014-07-17T10:07:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Company
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    company.cpp \
    companyforprofit.cpp \
    companynotforprofit.cpp \
    companylist.cpp \
    filewriter.cpp \
    filereader.cpp

HEADERS  += mainwindow.h \
    company.h \
    companyforprofit.h \
    companynotforprofit.h \
    companylist.h \
    filewriter.h \
    filereader.h

FORMS    += mainwindow.ui
