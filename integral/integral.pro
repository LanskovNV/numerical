TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    src/main.c \
    src/left_square.c \
    src/source.c \
    src/square_gauss.c

HEADERS += \
    src/left_square.h \
    src/source.h \
    src/square_gauss.h
