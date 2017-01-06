#-------------------------------------------------
#
# Project created by QtCreator 2016-10-30T11:43:09
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia
QT       += core gui widgets


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = rpoprojekt
TEMPLATE = app


SOURCES += main.cpp\
        glavnookno.cpp \
    zacetnookno.cpp \
    cpp/izpis_neodloceno.cpp \
    cpp/izpis_zmagovalca.cpp \
    cpp/vnosimena1.cpp \
    cpp/vnosimena2.cpp \
    cpp/igralec.cpp \
    cpp/igra.cpp \
    cpp/clickhandler.cpp \
    cpp/igra2.cpp \
    cpp/igra3.cpp

HEADERS  += glavnookno.h \
    zacetnookno.h \
    cpp/izpis_neodloceno.h \
    cpp/izpis_zmagovalca.h \
    cpp/vnosimena1.h \
    cpp/vnosimena2.h \
    cpp/igralec.h \
    cpp/igra.h \
    cpp/clickhandler.h \
    cpp/igra2.h \
    cpp/igra3.h

FORMS    += glavnookno.ui \
    zacetnookno.ui \
    ui/izpis_neodloceno.ui \
    ui/izpis_zmagovalca.ui \
    ui/vnosimena1.ui \
    ui/vnosimena2.ui

RESOURCES += \
    resource.qrc
