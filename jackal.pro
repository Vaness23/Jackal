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
    ship.cpp \
    pirate.cpp \
    tiles/empty.cpp \
    player.cpp \
    tiles/arrow.cpp \
    tiles/horse.cpp \
    tiles/spinner.cpp \
    tiles/ice.cpp \
    tiles/trap.cpp \
    tiles/crocodile.cpp \
    tiles/cannibal.cpp \
    tiles/fortress.cpp \
    tiles/aborigine.cpp \
    tiles/money.cpp \
    tiles/plane.cpp \
    tiles/balloon.cpp \
    tiles/gun.cpp \
    tiles/water.cpp \
    tiles/rum.cpp \
    ../Jackal/gameobject.cpp \
    ../Jackal/gamescene.cpp \
    ../Jackal/coin.cpp

HEADERS  += mainwindow.h \
    field.h \
    tile.h \
    game.h \
    ship.h \
    pirate.h \
    tiles/empty.h \
    player.h \
    tiles/arrow.h \
    tiles/horse.h \
    tiles/spinner.h \
    tiles/ice.h \
    tiles/trap.h \
    tiles/crocodile.h \
    tiles/cannibal.h \
    tiles/fortress.h \
    tiles/aborigine.h \
    tiles/money.h \
    tiles/plane.h \
    tiles/balloon.h \
    tiles/gun.h \
    tiles/water.h \
    tiles/rum.h \
    ../Jackal/gameobject.h \
    ../Jackal/gamescene.h \
    ../Jackal/coin.h

FORMS    += mainwindow.ui \
    game.ui

RESOURCES += \
    img/resource.qrc
