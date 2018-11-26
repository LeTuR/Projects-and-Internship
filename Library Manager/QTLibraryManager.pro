#-------------------------------------------------
#
# Project created by QtCreator 2018-05-20T11:35:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QTLibraryManager
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        widget.cpp\
        Book.cpp \
        CD.cpp \
        Commands.cpp \
        Digital_Ressource.cpp \
        DVD.cpp \
        Library.cpp \
        Magazine.cpp \
        Ressource.cpp \
        VHS.cpp \
        MainWindow.cpp \
        Add.cpp \
    LoginWindow.cpp \
    MainWindowAdmin.cpp \
    MainWindowUser.cpp

HEADERS += \
        widget.h \
        Book.hpp \
        CD.hpp \
        Commands.hpp \
        Digital_Ressource.hpp \
        DVD.hpp \
        Library.hpp \
        Magazine.hpp \
        Ressource.hpp \
        VHS.hpp \
        MainWindow.h \
        librarymanager.h \
        Add.h \
    LoginWindow.h \
    MainWindowAdmin.h \
    MainWindowUser.h

FORMS += \
        widget.ui
