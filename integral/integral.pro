TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    square_forms/src/main.c \
    square_forms/src/left_square.c \
    square_forms/src/source.c \
    square_forms/src/square_gauss.c

HEADERS += \
    square_forms/src/left_square.h \
    square_forms/src/source.h \
    square_forms/src/square_gauss.h
