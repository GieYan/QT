#-------------------------------------------------
#
# Project created by QtCreator 2016-05-27T18:54:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QT +=network

TARGET = client1
TEMPLATE = app


SOURCES += main.cpp \
    udpclient.cpp

HEADERS  += \
    udpclient.h
