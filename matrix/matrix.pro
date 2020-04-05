TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    src/main.c \
    src/matrix.c \
    src/solve_iter.c \
    src/siovesqr.c

HEADERS += \
    src/matrix.h \
    src/solve_iter.h \
    src/solvesqr.h

DISTFILES += \
    cfg/matrix-bad.txt \
    cfg/matrix-good.txt \
    cfg/test.txt \
    cfg/small.txt \
    cfg/small2.txt \
    cfg/small3.txt
