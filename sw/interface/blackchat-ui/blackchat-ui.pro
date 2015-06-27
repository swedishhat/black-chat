#-------------------------------------------------
#
# Project created by QtCreator 2014-12-02T05:23:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = blackchat-ui
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

#LIBS += -Wl,-static -lserial -Wl,-Bdynamic

unix|win32: LIBS += -static -lserial
LIBS += -L/usr/lib
LIBS += -L/usr/local/lib
