#-------------------------------------------------
#
# Project created by QtCreator 2018-02-19T11:45:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = box
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

unix {
    QT += dbus
    CONFIG += link_pkgconfig
    PKGCONFIG += dtkcore
}

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        box.cpp \
    boxboard.cpp \
    boxsmall.cpp \
    boxtest.cpp

HEADERS += \
        box.h \
    boxboard.h \
    public.h \
    boxsmall.h

win32* {
    CONFIG += no_lflags_merge
    DEFINES += STATIC_LIB

    #DEPENDS dtkcore
    INCLUDEPATH += $$INCLUDE_INSTALL_DIR\libdtk-$$VERSION\DCore
    LIBS += -L$$LIB_INSTALL_DIR -ldtkcore
}

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../file/deepin/dtkwidget-master/src/release -ldtkwidget
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../file/deepin/dtkwidget-master/src/debug -ldtkwidgetd
else:unix: LIBS += -L$$OUT_PWD/../../file/deepin/dtkwidget-master/src/ -ldtkwidget

INCLUDEPATH += $$PWD/../../file/deepin/dtkwidget-master/src
INCLUDEPATH += $$PWD/../../file/deepin/dtkwidget-master/src/widgets
INCLUDEPATH += $$PWD/../../file/deepin/dtkwidget-master/src/util
DEPENDPATH += $$PWD/../../file/deepin/dtkwidget-master/src

CONFIG(debug, debug|release) {
    unix:QMAKE_RPATHDIR += $$OUT_PWD/../../file/deepin/dtkwidget-master/src
}
