#-------------------------------------------------
#
# Project created by QtCreator 2016-01-22T16:49:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Edytor
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    kmptextiterator.cpp \
    positionlist.cpp \
    tokenizer.cpp \
    invertedtextiterator.cpp

HEADERS  += mainwindow.h \
    kmptextiterator.h \
    textiterator.h \
    bst.h \
    positionlist.h \
    tokenizer.h \
    classinvertedtextiterator.h

FORMS    += mainwindow.ui

RESOURCES += \
    zasoby.qrc
