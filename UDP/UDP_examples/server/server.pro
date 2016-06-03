#-------------------------------------------------
#
# Project created by QtCreator 2016-05-27T16:57:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QT += network

TARGET = server
TEMPLATE = app


SOURCES += main.cpp \
    udpserver.cpp

HEADERS  += \
    udpserver.h
