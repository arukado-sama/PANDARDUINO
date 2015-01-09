#-------------------------------------------------
#
# Project created by QtCreator 2014-01-27T10:30:02
#
#-------------------------------------------------

QT       += core gui
QT       += network

TARGET = ArduinoQt
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

OTHER_FILES +=

INCLUDEPATH += QextSerialPort

CONFIG(debug, debug|release):LIBS  += -lqextserialportd
else:LIBS  += -lqextserialport
