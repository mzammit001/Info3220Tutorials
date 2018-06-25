#-------------------------------------------------
#
# Project created by QtCreator 2015-02-11T16:44:59
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = ComputerBuilder
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    GraphicsCard.cpp \
    CPU.cpp \
    Motherboard.cpp \
    Case.cpp \
    Computer.cpp \
    GraphicsCardSet.cpp

HEADERS += \
    Computer.h \
    GraphicsCard.h \
    Part.h \
    CPU.h \
    Motherboard.h \
    Case.h \
    GraphicsCardSet.h
