#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QPlainTextDocumentLayout>
#include <QPlainTextEdit>
#include <QTextDocument>
#include <QLabel>
#include <Add.h>
#include <string>
#include <QMessageBox>
#include "Library.hpp"
#include "MainWindow.h"
#include "MainWindowAdmin.h"
#include "MainWindowUser.h"
#include "LoginWindow.h"

using namespace std;

void LoginWindow::enterConnect(){
    if (strcmp(username->text().toUtf8().constData(),"Admin")==0 && strcmp(password->text().toUtf8().constData(),"secret")==0){
        MainWindowAdmin *admin = new MainWindowAdmin();
        admin->show();
        this->close();
    }
    else if (strcmp(username->text().toUtf8().constData(),"")!=0){
        MainWindowUser *user = new MainWindowUser();
        user->show();
        this->close();
    }
    else
        QMessageBox::information ( this, "Login",QString::fromStdString("Please Enter Something Correct!"));
}

LoginWindow::LoginWindow(): QWidget()
{
    setFixedSize(250,600);

    QPalette pal = palette();
    pal.setColor(QPalette::Background, QColor(153,153,204));
    this->setAutoFillBackground(true);
    this->setPalette(pal);

    setWindowTitle("LOGIN");
    display->addWidget(texte);
    QFont serifFont("Times", 12, QFont::Normal);
    texte->setFont(serifFont);
    texte->setAlignment(Qt::AlignCenter);
    display->addWidget(username);
    username->setPlaceholderText("Username");
    username->setAlignment(Qt::AlignCenter);
    display->addWidget(password);
    password->setPlaceholderText("Password");
    password->setAlignment(Qt::AlignCenter);
    password->setEchoMode(QLineEdit::Password);
    display->addWidget(enter);
    setLayout(display);

    QObject::connect(enter, SIGNAL(clicked()), this, SLOT(enterConnect()));

}
