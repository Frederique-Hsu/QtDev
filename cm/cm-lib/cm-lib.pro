QT -= gui
TARGET = cm-lib
TEMPLATE = lib
DEFINES += CM_LIB_LIBRARY

CONFIG += c++17
INCLUDEPATH += source

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    source/controllers/command_controller.cpp \
    source/controllers/master_controller.cpp \
    source/controllers/navigation_controller.cpp \
    source/framework/command.cpp \
    source/models/client.cpp

HEADERS += \
    source/cm-lib_global.hpp \
    source/controllers/command_controller.hpp \
    source/controllers/master_controller.hpp \
    source/controllers/navigation_controller.hpp \
    source/framework/command.hpp \
    source/models/client.hpp

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

include(../qmake-target-platform.pri)
include(../qmake-destination-path.pri)

DESTDIR = $$PWD/../binaries/$$DESTINATION_PATH
OBJECTS_DIR = $$PWD/build/$$DESTINATION_PATH/.obj
MOC_DIR = $$PWD/build/$$DESTINATION_PATH/.moc
RCC_DIR = $$PWD/build/$$DESTINATION_PATH/.qrc
UI_DIR = $$PWD/build/$$DESTINATION_PATH/.ui

message(cm-lib output dir: $${DESTDIR})