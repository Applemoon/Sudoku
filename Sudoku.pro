QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Sudoku
TEMPLATE = app


SOURCES += main.cpp\
        firstwindow.cpp \
        tfield.cpp \
        tgamebase.cpp \
        tcell.cpp \
        infowindow.cpp

HEADERS  += firstwindow.h \
            tfield.h \
            tgamebase.h \
            tcell.h \
            infowindow.h

FORMS    += firstwindow.ui \
            tfield.ui \
            infowindow.ui

OBJECTS_DIR = .obj

greaterThan(QT_MAJOR_VERSION, 4) {
  QT += widgets
  DEFINES += HAVE_QT5
}
