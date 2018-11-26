#include "MainWindowAdmin.h"
#include <QApplication>
#include <QPushButton>
#include <QHBoxLayout>
#include <QGridLayout>
#include <Add.h>
#include<string>
#include <Commands.hpp>

using namespace std;

void MainWindowAdmin::openAdd(){
    qLoad(l, "MainData.txt");
    Add *newAdd = new Add(l);
    newAdd->show();
    texte->document()->setPlainText(QString::fromStdString(qList(l)));
    qSave(l, "MainData.txt");
}

void MainWindowAdmin::qShowConnect(){
    qLoad(l, "MainData.txt");
    try{
    int id = stoi(showID->text().toUtf8().constData());
    texte->document()->setPlainText(QString::fromStdString(qShow(l, id)));
    }
    catch(const std::invalid_argument){
        texte->document()->setPlainText("Invalid ID please try again.");
    }
}

void MainWindowAdmin::qDeleteConnect(){
    qLoad(l, "MainData.txt");
    try{
    int id = stoi(showID->text().toUtf8().constData());
    texte->document()->setPlainText(QString::fromStdString(qDelete(l, id)));
    qSave(l, "MainData.txt");
    texte->document()->setPlainText(QString::fromStdString(qList(l)));
    }
    catch(const std::invalid_argument){
        texte->document()->setPlainText("Invalid ID please try again.");
    }
}

void MainWindowAdmin::qSearchConnect(){
    qSearch(l, searchedWord->text().toUtf8().constData());
    texte->document()->setPlainText(QString::fromStdString(qList(l)));
}

void MainWindowAdmin::qResetConnect(){
    resetLib(l);
    texte->document()->setPlainText(QString::fromStdString(qList(l)));
}

void MainWindowAdmin::qListConnect(){
    texte->document()->setPlainText(QString::fromStdString(qList(l)));
}

void MainWindowAdmin::qLoadConnect(){
    QString qPath= QFileDialog::getOpenFileName(this, "Open file", QString());
    string path = qPath.toUtf8().constData();
    if (qLoad(l, path)==0) texte->document()->setPlainText(QString::fromStdString("Library Succefully Loaded!"));
    else texte->document()->setPlainText(QString::fromStdString("Error: file couldn't be loaded"));
}

void MainWindowAdmin::qSaveConnect(){
    QString qPath = QFileDialog::getSaveFileName(this, "Save Library", QString(), "(*.txt)");
    string path = qPath.toUtf8().constData();
    if (qSave(l, path)==0) texte->document()->setPlainText(QString::fromStdString("Library Succefully Saved!"));
    else texte->document()->setPlainText(QString::fromStdString("Error: file couldn't be saved"));
}

void MainWindowAdmin::qUploadConnect(){
    if (qSave(l, "MainData.txt")==0) texte->document()->setPlainText(QString::fromStdString("Library Succefully Uploaded!"));
    else texte->document()->setPlainText(QString::fromStdString("Error: Library couldn't be uploaded"));
}

MainWindowAdmin::MainWindowAdmin()
{
    setFixedSize(700,700);

    QPalette pal = palette();
    pal.setColor(QPalette::Background, QColor(153,204,153));
    this->setAutoFillBackground(true);
    this->setPalette(pal);

    this->setWindowTitle("Admin Mode");
    layout->addWidget(searchIDpart, 1, 9);
    layout->addWidget(pushShow, 2, 9);
    layout->addWidget(deleteRessource, 3, 9);
    layout->addWidget(showID, 4, 9);
    showID->setPlaceholderText("Enter ID here");
    showID->setAlignment(Qt::AlignCenter);
    layout->addWidget(qReset, 8,6);
    layout->addWidget(pushSearch, 8,7);
    layout->addWidget(searchedWord, 8,8);
    searchedWord->setPlaceholderText("Find this word");
    searchedWord->setAlignment(Qt::AlignCenter);
    layout->addWidget(list, 4, 0);
    layout->addWidget(add, 1, 0);
    layout->addWidget(load, 2, 0);
    layout->addWidget(save, 3, 0);
    layout->addWidget(upload, 7, 9);
    layout->addWidget(texte, 1,2,6,7);
    QFont serifFont("Times", 12, QFont::Bold);
    texte->setFont(serifFont);
    texte->setReadOnly(true);
    setLayout(layout);
    qLoad(l, "MainData.txt");


    QObject::connect(add, SIGNAL(clicked()), this, SLOT(openAdd()));
    QObject::connect(pushShow, SIGNAL(clicked()), this, SLOT(qShowConnect()));
    QObject::connect(deleteRessource, SIGNAL(clicked()), this, SLOT(qDeleteConnect()));
    QObject::connect(pushSearch, SIGNAL(clicked()), this, SLOT(qSearchConnect()));
    QObject::connect(list, SIGNAL(clicked()), this, SLOT(qListConnect()));
    QObject::connect(load, SIGNAL(clicked()), this, SLOT(qLoadConnect()));
    QObject::connect(save, SIGNAL(clicked()), this, SLOT(qSaveConnect()));
    QObject::connect(upload, SIGNAL(clicked()), this, SLOT(qUploadConnect()));
    QObject::connect(qReset, SIGNAL(clicked()), this, SLOT(qResetConnect()));

}

MainWindowAdmin::~MainWindowAdmin(){
}
