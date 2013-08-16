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

win32 {

    INCLUDEPATH += C:\\OpenCV-2.4.5\\opencv\\build\\include

    LIBS += -LC:\\OpenCV-2.4.5\\opencv\\build\\x86\\vc10\\lib \
            -lopencv_core245d -lopencv_imgproc245d -lopencv_highgui245d -lopencv_ml245d \
            -lopencv_video245d -lopencv_features2d245d -lopencv_objdetect245d \
            -lopencv_contrib245d -lopencv_legacy245d -lopencv_flann245d -lopencv_nonfree245d

}
unix {

    INCLUDEPATH += /usr/local/include

    LIBS += -L/usr/local/lib \
            -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_ml \
            -lopencv_video -lopencv_features2d -lopencv_objdetect -lopencv_contrib \
            -lopencv_legacy -lopencv_flann -lopencv_nonfree


}

SOURCES += main.cpp\
        mainwindow.cpp \
    intintdialog.cpp \
    doubledoubledialog.cpp \
    doubleintdialog.cpp

HEADERS  += mainwindow.h \
    intintdialog.h \
    doubledoubledialog.h \
    doubleintdialog.h

FORMS    += mainwindow.ui
