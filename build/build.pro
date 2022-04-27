QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

QMAKE_EXTRA_TARGETS += shortcut rm_shortcut

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SRC_DIR=../src/calculator

SOURCES += \
    $$SRC_DIR/gui/gui_main.cpp \
    $$SRC_DIR/gui/mainwindow.cpp \
    $$SRC_DIR/math/wmath.cpp \
    $$SRC_DIR/gui-linking/gui-linker.cpp

HEADERS += \
    $$SRC_DIR/gui/mainwindow.h \
    $$SRC_DIR/math/wmath.h \
    $$SRC_DIR/gui-linking/gui-linker.h

FORMS += \
    $$SRC_DIR/gui/mainwindow.ui

TARGET = wcalculator

shortcut.commands = mkdir -p /usr/share/applications ; mkdir -p /usr/share/pixmaps ; cp ../install/wcalculator.desktop /usr/share/applications ; cp ../install/wcalculator.xpm /usr/share/pixmaps
rm_shortcut.commands = rm -f /usr/share/applications/wcalculator.desktop ; rm -f /usr/share/pixmaps/wcalculator.xpm

#install
target.path = $$(PREFIX)/bin
target.depends
INSTALLS += target

