TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp\
    functions.cpp \
    lib.cpp \
    solver.cpp

HEADERS += \
    functions.h \
    solver.h \
    lib.h
