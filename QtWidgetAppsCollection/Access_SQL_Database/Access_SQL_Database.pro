QT += core gui widgets
QT += sql

CONFIG += c++2a

SOURCES += \
    access_sql_db.cpp \
    custom_widget.cpp \
    main.cpp

HEADERS += \
    access_sql_db.hpp \
    custom_widget.hpp

DISTFILES += \
    cities.sql
