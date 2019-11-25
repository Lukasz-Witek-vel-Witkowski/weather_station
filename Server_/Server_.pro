#-------------------------------------------------
#
# Project created by QtCreator 2019-01-10T05:11:15
#
#-------------------------------------------------

QT       += core gui sql xml serialport network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Server_
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        windowmain.cpp \
    clientBase.cpp \
    clientfactory.cpp \
    clientserialport.cpp \
    clientsql.cpp \
    thread.cpp \
    ../outFile/option.cpp \
    server.cpp \
    clientleesener.cpp \
    message.cpp \
    datetime.cpp \
    measurement.cpp

HEADERS += \
        windowmain.h \
    clientBase.h \
    clientfactory.h \
    clientserialport.h \
    clientsql.h \
    thread.h \
    ../outFile/option.h \
    server.h \
    clientleesener.h \
    message.h \
    datetime.h \
    measurement.h

FORMS += \
        windowmain.ui \
    ../outFile/option.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
