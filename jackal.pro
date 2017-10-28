#-------------------------------------------------
#
# Project created by QtCreator 2017-10-24T17:41:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = jackal
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    field.cpp \
    tile.cpp \
    game.cpp \
    ../Jackal/empty.cpp \
    player.cpp \
    arrow.cpp \
    horse.cpp \
    spinner.cpp \
    ice.cpp \
    trap.cpp \
    crocodile.cpp \
    cannibal.cpp \
    fortress.cpp \
    aborigine.cpp \
    money.cpp

HEADERS  += mainwindow.h \
    field.h \
    tile.h \
    game.h \
    ../Jackal/empty.h \
    player.h \
    arrow.h \
    horse.h \
    spinner.h \
    ice.h \
    trap.h \
    crocodile.h \
    cannibal.h \
    fortress.h \
    aborigine.h \
    money.h

FORMS    += mainwindow.ui \
    game.ui
