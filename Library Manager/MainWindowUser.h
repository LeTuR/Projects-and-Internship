#ifndef MAINWINDOWUSER_H
#define MAINWINDOWUSER_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QPlainTextDocumentLayout>
#include <QPlainTextEdit>
#include <QTextDocument>
#include <QLabel>
#include <Add.h>
#include "Library.hpp"


class MainWindowUser: public QWidget
{
    Q_OBJECT

public:
    MainWindowUser();
    ~MainWindowUser();
private:
    QLabel *searchIDpart = new QLabel("Enter below an ID and \n"
                                      "press Show, Rent or Give Back");
    QPushButton *pushSearch = new QPushButton("Search");
    QLineEdit *showID = new QLineEdit();
    QPushButton *pushShow = new QPushButton("Show");
    QPushButton *rent = new QPushButton("Rent");
    QPushButton *giveBack = new QPushButton("Give Back");
    QLineEdit *searchedWord = new QLineEdit();
    QPushButton *qReset= new QPushButton("Reset");
    QPushButton *list= new QPushButton("List");
    QPushButton *add= new QPushButton("Add");
    QPushButton *load= new QPushButton("Load");
    QPushButton *reload= new QPushButton("Reload");
    QPushButton *save= new QPushButton("Save");
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
    void qReloadConnect();
    void qSaveConnect();
    void qResetConnect();
    void qRentConnect();
    void qGiveBackConnect();


};

#endif // MAINWINDOWUSER_H
