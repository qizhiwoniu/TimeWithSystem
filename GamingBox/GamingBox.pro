VERSION = 1.0.0
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    configure.cpp \
    main.cpp \
    mainwindow.cpp \
    settings.cpp

HEADERS += \
    configure.h \
    mainwindow.h \
    settings.h

FORMS += \
    configure.ui \
    mainwindow.ui \
    settings.ui

TRANSLATIONS +=
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    app1.ico \
    app1.rc


RESOURCES += \
    app1.qrc
RC_ICONS =
RC_FILE =
