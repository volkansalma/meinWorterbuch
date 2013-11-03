#-------------------------------------------------
#
# Project created by QtCreator 2013-10-31T22:00:19
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = meinWorterbuch
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp\
    dialogaddword.cpp \
    dialogwordquestion.cpp \
    WordRecord.cpp

HEADERS  += mainwindow.h \
    dialogaddword.h \
    dialogwordquestion.h \
    WordRecord.h

FORMS    += mainwindow.ui \
    dialogaddword.ui \
    dialogwordquestion.ui
