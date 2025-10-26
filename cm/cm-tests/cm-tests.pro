QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH += source \
    ../cm-lib/source

SOURCES +=  \
    main.cpp \
    source/controllers/master-controller-tests.cpp \
    source/data/int_decorator_tests.cpp \
    test_suite.cpp

include(../qmake-target-platform.pri)
include(../qmake-destination-path.pri)

DESTDIR = $$PWD/../binaries/$$DESTINATION_PATH
OBJECTS_DIR = $$PWD/build/$$DESTINATION_PATH/obj
MOC_DIR = $$PWD/build/$$DESTINATION_PATH/moc
RCC_DIR = $$PWD/build/$$DESTINATION_PATH/qrc
UI_DIR = $$PWD/build/$$DESTINATION_PATH/ui

LIBS += -L$$PWD/../binaries/$$DESTINATION_PATH -lcm-lib

HEADERS += \
    source/controllers/master-controller-tests.hpp \
    source/data/int_decorator_tests.hpp \
    test_suite.hpp
