#-------------------------------------------------
#
# Project created by Ayle 2015-05-24T11:57:29
#
#-------------------------------------------------

QT       += core gui\
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SpongeBubble
TEMPLATE = app


SOURCES += main.cpp \
    Game.cpp \
    Score.cpp \
    Health.cpp \
    Player..cpp \
    Button.cpp \
    Bubble.cpp \
    Patrick.cpp

HEADERS  +=  \
    Game.h \
    Score.h \
    Health.h \
    Player.h \
    Button.h \
    Bubble.h \
    Patrick.h

FORMS    +=

RESOURCES += \
    res.qrc

RC_ICONS = sponge.ico
