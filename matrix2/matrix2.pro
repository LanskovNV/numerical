TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    src/main.c \
    src/matrix.c \
    src/leverie.c \
    src/jacobi.c \
    src/qr.c \
    src/solve_iter.c

HEADERS += \
    src/matrix.h \
    src/leverie.h \
    src/jacobi.h \
    src/qr.h \
    src/solve_iter.h

DISTFILES += \
    cfg/matr.txt \
    cfg/matrix-bad.txt \
    cfg/matrix-good.txt \
    cfg/leverie.txt \
    cfg/goodCNT.txt \
    cfg/badCNT.txt \
    cfg/goodASYM.txt \
    cfg/badASYM.txt
