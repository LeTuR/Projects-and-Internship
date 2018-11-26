#ifndef MAINWINDOWADMIN_H
#define MAINWINDOWADMIN_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QPlainTextDocumentLayout>
#include <QPlainTextEdit>
#include <QTextDocument>
#include <QLabel>
#include <Add.h>
#include "Library.hpp"


class MainWindowAdmin: public QWidget
{
    Q_OBJECT

public:
    MainWindowAdmin();
    ~MainWindowAdmin();
private:
    QLabel *searchIDpart = new QLabel("Enter below an ID and \n"
                                      "press Show or Delete");
    QPushButton *pushSearch = new QPushButton("Search");
    QLineEdit *showID = new QLineEdit();
    QPushButton *pushShow = new QPushButton("Show");
    QPushButton *deleteRessource= new QPushButton("Delete");
    QLineEdit *searchedWord = new QLineEdit();
    QPushButton *qReset= new QPushButton("Reset");
    QPushButton *list= new QPushButton("List");
    QPushButton *add= new QPushButton("Add");
    QPushButton *load= new QPushButton("Load");
    QPushButton *save= new QPushButton("Save");
    QPushButton *upload= new QPushButton("Upload");
    QPlainTextEdit *texte= new QPlainTextEdit();
    QGridLayout *layout = new QGridLayout;

    Library *l = new Library();

public slots:
    void openAdd();
    void qShowConnect();
    void qDeleteConnect();
    void qSearchConnect();
    void qListConnect();
    void qLoadConnect();
    void qSaveConnect();
    void qUploadConnect();
    void qResetConnect();

};

#endif // MAINWINDOWADMIN_H
