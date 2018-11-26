#include "MainWindow.h"
#include "LoginWindow.h"
#include "Add.h"
#include "widget.h"
#include <QApplication>
#include <QLineEdit>
#include <QString>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginWindow window;
    window.show();
    return a.exec();
}

