QT = core

CONFIG += c++17 cmdline

# No debug output
CONFIG(release, debug | release): DEFINES += QT_NO_DEBUG_OUTPUT

DEFINES += QT_DEPRECATED_WARNINGS

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# Link againt external library
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../MathFunctions/build/debug/release/ -lMathFunctions
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../MathFunctions/build/debug/debug/ -lMathFunctions
else:unix: LIBS += -L$$PWD/../MathFunctions/build/debug/ -lMathFunctions

INCLUDEPATH += $$PWD/../MathFunctions
DEPENDPATH += $$PWD/../MathFunctions

win32:CONFIG(release, debug | release): PRE_TARGETDEPS += $$PWD/../MathFunctions/build/debug/release/MathFunctions.lib
else:unix: PRE_TARGETDEPS += $$PWD/../MathFunctions/build/debug/libMathFunctions.a
