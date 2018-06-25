#-------------------------------------------------
#
# Project created by QtCreator 2014-05-19T06:22:24
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = Facade
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    EuclideanVector.cpp

HEADERS += \
    EuclideanVector.h \
    VectorArithmeticException.h \
    VectorAssignmentException.h \
    VectorIndexOutOfBoundsException.h \
    VectorRuntimeException.h
