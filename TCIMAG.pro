#-------------------------------------------------
##
# @file TCIMAG.pro
# @author Juan ASCENCIO
# @version 1.0
# @date Juillet 2013
# @copyright INSA LYON
# Creation date 2013-07-04T17:30:28
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TCIMAG
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

INCLUDEPATH += /usr/local/include

LIBS += -L/usr/local/lib \
        -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_ml \
        -lopencv_video -lopencv_features2d -lopencv_objdetect -lopencv_contrib \
        -lopencv_legacy -lopencv_flann -lopencv_nonfree

