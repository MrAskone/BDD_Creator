QT       += core gui widgets qml quick

TEMPLATE = app
CONFIG += c++11
CONFIG -= app_bundle
# CONFIG -= qt

SOURCES += cpp/main.cpp \
    cpp/wmanager.cpp \
    cpp/dataparser.cpp

HEADERS += \
    cpp/wmanager.h \
    cpp/dataparser.h

DISTFILES += \
    qml/MyButton.qml \
    qml/interface.qml
