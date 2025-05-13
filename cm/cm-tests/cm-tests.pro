QT += testlib
QT -= gui

TARGET = client-tests
TEMPLATE = app

CONFIG += c++17
CONFIG += qt console # warn_on depend_includepath testcase
CONFIG -= app_bundle

INCLUDEPATH += source

SOURCES +=  source/models/tst_clienttests.cpp

include(../qmake-target-platform.pri)
include(../qmake-destination-path.pri)

DESTDIR = $$PWD/../binaries/$$DESTINATION_PATH
OBJECTS_DIR = $$PWD/build/$$DESTINATION_PATH/.obj
MOC_DIR = $$PWD/build/$$DESTINATION_PATH/.moc
RCC_DIR = $$PWD/build/$$DESTINATION_PATH/.qrc
UI_DIR = $$PWD/build/$$DESTINATION_PATH/.ui

LIBS += -L$$PWD/../binaries/$$DESTINATION_PATH -lcm-lib