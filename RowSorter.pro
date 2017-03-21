TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    parser.cpp \
    rowsorter.cpp \
    rowitem.cpp

HEADERS += \
    parser.h \
    rowsorter.h \
    rowitem.h
