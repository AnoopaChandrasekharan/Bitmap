HEADERS += my_widget.h \
    paint.h
SOURCES += my_widget.cpp main.cpp
CONFIG += qt warn_on
CONFIG += debug
QT = core gui
IMAGES += icon/pen_icon.bmp
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

RESOURCES += \
    resource.qrc

