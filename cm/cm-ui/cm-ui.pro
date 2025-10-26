QT += quick qml

TEMPLATE = app

CONFIG += c++17

INCLUDEPATH += source \
        ../cm-lib/source

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        source/main.cpp

RESOURCES += views.qrc \
    assets.qrc \
    components.qrc

include(../qmake-target-platform.pri)
include(../qmake-destination-path.pri)

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH += $$PWD

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

LIBS += -L$$PWD/../binaries/$$DESTINATION_PATH -lcm-lib

DESTDIR = $$PWD/../binaries/$$DESTINATION_PATH
OBJECTS_DIR = $$PWD/../build/$$DESTINATION_PATH/obj
MOC_DIR = $$PWD/../build/$$DESTINATION_PATH/moc
RCC_DIR = $$PWD/../build/$$DESTINATION_PATH/qrc
UI_DIR = $$PWD/../build/$$DESTINATION_PATH/ui
