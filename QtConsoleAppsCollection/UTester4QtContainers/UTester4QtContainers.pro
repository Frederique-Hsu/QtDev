include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG += qt core

LIBS += -lgtest -lpthread

SOURCES += \
        main.cpp \
        utest_qt_global.cpp
