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
    source/data/data_decorator.cpp \
    source/data/date_time_decorator.cpp \
    source/data/entity.cpp \
    source/data/entity_collection.cpp \
    source/data/enumerator_decorator.cpp \
    source/data/int_decorator.cpp \
    source/data/string_decorator.cpp \
    source/framework/command.cpp \
    source/models/address.cpp \
    source/models/appointment.cpp \
    source/models/client.cpp \
    source/models/contact.cpp



HEADERS += \
    source/cm-lib_global.hpp \
    source/controllers/command_controller.hpp \
    source/controllers/master_controller.hpp \
    source/controllers/navigation_controller.hpp \
    source/data/data_decorator.hpp \
    source/data/date_time_decorator.hpp \
    source/data/entity.hpp \
    source/data/entity_collection.hpp \
    source/data/enumerator_decorator.hpp \
    source/data/int_decorator.hpp \
    source/data/string_decorator.hpp \
    source/framework/command.hpp \
    source/models/address.hpp \
    source/models/appointment.hpp \
    source/models/client.hpp \
    source/models/contact.hpp



# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

include(../qmake-target-platform.pri)
include(../qmake-destination-path.pri)

DESTDIR = $$PWD/../binaries/$$DESTINATION_PATH
OBJECTS_DIR = $$PWD/build/$$DESTINATION_PATH/obj
MOC_DIR = $$PWD/build/$$DESTINATION_PATH/moc
RCC_DIR = $$PWD/build/$$DESTINATION_PATH/qrc
UI_DIR = $$PWD/build/$$DESTINATION_PATH/ui

message(cm-lib output dir: $${DESTDIR})
