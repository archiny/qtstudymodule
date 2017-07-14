#-------------------------------------------------
#
# Project created by QtCreator 2017-07-12T09:47:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = hello
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    nitem.cpp \
    rectitem.cpp \
    commfun.cpp \
    stylewidget.cpp

HEADERS  += widget.h \
    nitem.h \
    rectitem.h \
    commfun.h \
    stylewidget.h

FORMS    +=

OTHER_FILES += \
    style.qss

RESOURCES += \
    style.qrc
