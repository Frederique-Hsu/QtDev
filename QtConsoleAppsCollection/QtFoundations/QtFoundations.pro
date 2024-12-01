QT = core
QT += network

CONFIG += c++17 cmdline

LIBS += -lgtest -lpthread

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
        multithreading/MyObject.cpp \
        multithreading/MyThread.cpp \
        multithreading/test_qt_multithreading.c++ \
        network_accessing/network_accessing.cpp \
        test_qt_containers.c++ \
        test_qt_filesystem.c++

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    multithreading/MyObject.hpp \
    multithreading/MyThread.hpp \
    network_accessing/network_accessing.hpp

RESOURCES += \
    resource.qrc
