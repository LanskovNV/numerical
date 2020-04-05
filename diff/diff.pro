TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    src/main.cpp \
    src/function.cpp \
    src/euler_koshi.cpp \
    src/adams.cpp \
    src/shooting.cpp

HEADERS += \
    src/function.h \
    src/euler_koshi.h \
    src/adams.h \
    src/shooting.h

DISTFILES += \
    out/y_solution.txt
