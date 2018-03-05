TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system

SOURCES += main.cpp \
    game.cpp \
    WarriorSquirrel.cpp \
    Entity.cpp \
    Worm.cpp \
    workersquirrel.cpp \
    nut.cpp \
    TreePart.cpp \
    texcontainer.cpp

HEADERS += \
    game.h \
    WarriorSquirrel.h \
    Entity.h \
    Worm.h \
    workersquirrel.h \
    nut.h \
    TreePart.h \
    texcontainer.h
