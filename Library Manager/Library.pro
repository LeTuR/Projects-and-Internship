#-------------------------------------------------
#
# Project created by QtCreator 2018-05-09T09:59:49
#
#-------------------------------------------------

QT       -= gui

TARGET = Library
TEMPLATE = lib

DEFINES += LIBRARY_LIBRARY

SOURCES += \
    Book.cpp \
    CD.cpp \
    Commands.cpp \
    Digital_Ressource.cpp \
    DVD.cpp \
    Library.cpp \
    Magazine.cpp \
    main.cpp \
    Ressource.cpp \
    VHS.cpp

HEADERS +=\
    Book.hpp \
    CD.hpp \
    Commands.hpp \
    Digital_Ressource.hpp \
    DVD.hpp \
    Library.hpp \
    Magazine.hpp \
    Ressource.hpp \
    VHS.hpp

unix {
    target.path = /usr/lib
    INSTALLS += target
}
