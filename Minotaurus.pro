#-------------------------------------------------
#
# Project created by QtCreator 2017-02-26T12:48:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Minotaurus
TEMPLATE = app


SOURCES += main.cpp\
    Cell.cpp \
    MainWindow.cpp \
    Maze.cpp \
    GrowingTree.cpp \
    MostRecentSelectionStrategy.cpp \
    AbstractGeneratingStrategy.cpp

HEADERS  += \
    Cell.h \
    MainWindow.h \
    Maze.h \
    GrowingTree.h \
    Coord.h \
    MostRecentSelectionStrategy.h \
    AbstractGeneratingStrategy.h \
    AbstractNextCellSelectionStrategy.h

FORMS    += mainwindow.ui
