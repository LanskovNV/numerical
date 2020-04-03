TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    ../diff_git/main.cpp \
    ../diff_git/function.cpp \
    ../diff_git/euler_koshi.cpp \
    ../diff_git/adams.cpp \
    ../diff_git/shooting.cpp

HEADERS += \
    ../diff_git/function.h \
    ../diff_git/euler_koshi.h \
    ../diff_git/adams.h \
    ../diff_git/shooting.h

DISTFILES += \
    ../diff_git/y_solution.txt
