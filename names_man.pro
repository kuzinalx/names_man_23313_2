#-------------------------------------------------
#
# Project created by QtCreator 2015-03-18T00:00:03
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = names_man
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    name_info.cpp \
    read_name_info.cpp \
    verify_names.cpp

HEADERS += \
    names_man_exception.h \
    name_info.h \
    name_info_reader.h
