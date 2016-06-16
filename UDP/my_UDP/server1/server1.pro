#-------------------------------------------------
#
# Project created by QtCreator 2016-05-27T19:49:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QT +=network

TARGET = server1
TEMPLATE = app

SOURCES += main.cpp \
    udpserver.cpp \
    showdata.cpp

HEADERS  += \
    udpserver.h\
    showdata.h

FORMS    +=
