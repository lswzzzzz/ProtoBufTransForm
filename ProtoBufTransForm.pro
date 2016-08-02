#-------------------------------------------------
#
# Project created by QtCreator 2015-09-04T16:12:35
#
#-------------------------------------------------

QT       += core gui
CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProtoBufTransForm
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    global.cpp \
    sourcelistwidget.cpp \
    protobufdetailwidget.cpp

HEADERS  += mainwindow.h \
    global.h \
    sourcelistwidget.h \
    protobufdetailwidget.h

FORMS    += mainwindow.ui
