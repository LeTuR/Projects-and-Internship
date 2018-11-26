#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QPlainTextDocumentLayout>
#include <QPlainTextEdit>
#include <QTextDocument>
#include <QLabel>
#include <QVBoxLayout>
#include <Add.h>
#include "Library.hpp"


class LoginWindow: public QWidget
{
    Q_OBJECT

public:
    LoginWindow();
private:
    QLabel *texte = new QLabel("Hello, Welcome to library Manager!\n"
                               "If you want to login as an Admin \n"
                               "please enter Admin as username and \n"
                               "the required password (secret).\n"
                               "If you want to login as a user \n"
                               "please just enter your username");
    QLineEdit *username = new QLineEdit();
    QLineEdit *password = new QLineEdit();
    QPushButton *enter = new QPushButton("Enter");
    QVBoxLayout *display = new QVBoxLayout();

public slots:
    void enterConnect();
};

#endif // LOGINWINDOW_H
