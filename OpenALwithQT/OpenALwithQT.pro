#-------------------------------------------------
#
# Project created by QtCreator 2017-05-13T17:40:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

# default path.
INCLUDEPATH += /usr/include
LIBS += -L/usr/lib64

# add OpenAL Libraries
LIBS += -lalut \
        -lopenal \

TARGET = OpenALwithQT
TEMPLATE = app


SOURCES += main.cpp \
    OpenALWithQT.cpp \
    OpenAL.cpp

HEADERS  += \
    OpenALWithQT.h \
    OpenAL.h

FORMS    += \
    OpenALWithQT.ui
