TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    ../interpolation/src/source.c \
    ../interpolation/src/main.c \
    ../interpolation/src/hermith.c \
    ../interpolation/src/spline3.c

DISTFILES += \
    ../interpolation/src/output.txt \
    ../interpolation/math/output.txt

HEADERS += \
    ../interpolation/src/source.h \
    ../interpolation/src/hermith.h \
    ../interpolation/src/spline3.h
