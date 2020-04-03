TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    matrix.c \
    leverie.c \
    jacobi.c \
    qr.c \
    solve_iter.c

HEADERS += \
    matrix.h \
    leverie.h \
    jacobi.h \
    qr.h \
    solve_iter.h

DISTFILES += \
    matr.txt \
    matrix-bad.txt \
    matrix-good.txt \
    leverie.txt \
    goodCNT.txt \
    badCNT.txt \
    goodASYM.txt \
    badASYM.txt
