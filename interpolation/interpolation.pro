TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    src/source.c \
    src/main.c \
    src/hermith.c \
    src/spline3.c

DISTFILES += \
    math/output.txt \

HEADERS += \
    src/source.h \
    src/hermith.h \
    src/spline3.h
