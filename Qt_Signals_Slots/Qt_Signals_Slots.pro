QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    CCounter.cpp \
    LcdNumber.cpp \
    QCounter.cpp \
    Test_QCounter.cpp \
    main.cpp \
    user_moc.cpp \
    user_signal_slot_mechanism.cpp

HEADERS += \
    CCounter.hpp \
    LcdNumber.hpp \
    QCounter.hpp \
    Test_QCounter.hpp \
    user_moc.hpp \
    user_signal_slot_mechanism.hpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
