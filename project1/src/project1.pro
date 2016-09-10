TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp\
    functions.cpp \
    tridiag_solver.cpp

HEADERS += \
    functions.h \
    tridiag_solver.h
