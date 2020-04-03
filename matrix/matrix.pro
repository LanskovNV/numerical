TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    matrix.c \
    solve_iter.c \
    siovesqr.c

HEADERS += \
    matrix.h \
    solve_iter.h \
    solvesqr.h

DISTFILES += \
    matrix-bad.txt \
    matrix-good.txt \
    test.txt \
    small.txt \
    small2.txt \
    small3.txt
