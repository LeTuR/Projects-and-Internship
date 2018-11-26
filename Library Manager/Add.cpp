#include "Add.h"
#include <QApplication>
#include <QPushButton>
#include <QFormLayout>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QButtonGroup>
#include <QRadioButton>
#include <QFileDialog>
#include <QComboBox>
#include <string>
#include <QMenu>
#include <QStackedWidget>
#include <QTabWidget>
#include <QTextEdit>
#include <QDateEdit>
#include <QTimeEdit>
#include <QFileInfo>
#include "Book.hpp"
#include "Magazine.hpp"
#include "VHS.hpp"
#include "DVD.hpp"
#include "CD.hpp"
#include "Digital_Ressource.hpp"
#include "Ressource.hpp"
#include <iostream>
#include <QMessageBox>
#include <Library.hpp>

using namespace std;

//Book Accesor
QLineEdit* Add::getTitleBook(){return titleBook;}
QLineEdit* Add::getAuthorBook(){return authorBook;}
QSpinBox* Add::getPagesBook(){return pagesBook;}
QDateEdit* Add::getPublicationBook(){return publicationBook;}
QLineEdit* Add::getCollectionBook(){return collectionBook;}
QTextEdit* Add::getSummaryBook(){return summaryBook;}
//Magazine Accesor
QLineEdit* Add::getTitleMagazine(){return titleMagazine;}
QLineEdit* Add::getAuthorMagazine(){return authorMagazine;}
QSpinBox* Add::getPagesMagazine(){return pagesMagazine;}
QDateEdit* Add::getPublicationMagazine(){return publicationMagazine;}
QLineEdit* Add::getCollectionMagazine(){return collectionMagazine;}
QTextEdit* Add::getSummaryMagazine(){return summaryMagazine;}
QLineEdit* Add::getEditorMagazine(){return editorMagazine;}
QSpinBox* Add::getArticlesMagazine(){return articlesMagazine;}
//VHS Accesor
QLineEdit* Add::getTitleVHS(){return titleVHS;}
QLineEdit* Add::getAuthorVHS(){return authorVHS;}
QTimeEdit* Add::getDurationVHS(){return durationVHS;}
QLineEdit* Add::getStudioVHS(){return studioVHS;}
//DVD Accesor
QLineEdit* Add::getTitleDVD(){return titleDVD;}
QLineEdit* Add::getAuthorDVD(){return authorDVD;}
QTimeEdit* Add::getDurationDVD(){return durationDVD;}
QLineEdit* Add::getStudioDVD(){return studioDVD;}
QSpinBox* Add::getChaptersDVD(){return chaptersDVD;}
//CD Accesor
QLineEdit* Add::getTitleCD(){return titleCD;}
QLineEdit* Add::getAuthorCD(){return authorCD;}
QTimeEdit* Add::getDurationCD(){return durationCD;}
QLineEdit* Add::getStudioCD(){return studioCD;}
QSpinBox* Add::getChaptersCD(){return chaptersCD;}
//Digital Ressource Accesor
QLineEdit* Add::getTitleDigital_Ressource(){return titleDigital_Ressource;}
QLineEdit* Add::getAuthorDigital_Ressource(){return authorDigital_Ressource;}
QLineEdit* Add::getPathDigital_Ressource(){return pathDigital_Ressource;}
QLineEdit* Add::getTypeDigital_Ressource(){return typeDigital_Ressource;}
QLineEdit* Add::getSizeDigital_Ressource(){return sizeDigital_Ressource;}


void Add::saveRessource(){
    if (type->currentIndex()==0) {
        //Book *r = new Book(title, author, pages, publication, collection, summary);
        Book *r = new Book(this->getTitleBook()->text().toUtf8().constData(),
                           this->getAuthorBook()->text().toUtf8().constData(),
                           this->getPagesBook()->value(),
                           this->getPublicationBook()->date().toString("dd/MM/yyyy").toUtf8().constData(),
                           this->getCollectionBook()->text().toUtf8().constData(),
                           this->getSummaryBook()->toPlainText().toUtf8().constData());
        l->addRessource(r);
        QMessageBox::information ( this, "Affichage ajout",QString::fromStdString("Book succefully added!"));
        this->close();
    }
    else if (type->currentIndex()==1){
        Magazine *r = new Magazine(this->getTitleMagazine()->text().toUtf8().constData(),
                                   this->getAuthorMagazine()->text().toUtf8().constData(),
                                   this->getPagesMagazine()->value(),
                                   this->getPublicationMagazine()->date().toString("dd/MM/yyyy").toUtf8().constData(),
                                   this->getCollectionMagazine()->text().toUtf8().constData(),
                                   this->getSummaryMagazine()->toPlainText().toUtf8().constData(),
                                   this->getEditorMagazine()->text().toUtf8().constData(),
                                   this->getArticlesMagazine()->value());
        l->addRessource(r);
        QMessageBox::information ( this, "Affichage ajout",QString::fromStdString("Magazine succefully added!"));
        this->close();
    }
    else if  (type->currentIndex()==2){
        VHS *r = new class VHS(this->getTitleVHS()->text().toUtf8().constData(),
                               this->getAuthorVHS()->text().toUtf8().constData(),
                               this->getDurationVHS()->time().toString("hh:mm:ss").toUtf8().constData(),
                               this->getStudioVHS()->text().toUtf8().constData());
        l->addRessource(r);
        QMessageBox::information ( this, "Affichage ajout",QString::fromStdString("VHS succefully added!"));
        this->close();
    }
    else if (type->currentIndex()==3){
        DVD *r = new class DVD(this->getTitleDVD()->text().toUtf8().constData(),
                               this->getAuthorDVD()->text().toUtf8().constData(),
                               this->getDurationDVD()->time().toString("hh:mm:ss").toUtf8().constData(),
                               this->getStudioDVD()->text().toUtf8().constData(),
                               this->getChaptersDVD()->value());
        l->addRessource(r);
        QMessageBox::information ( this, "Affichage ajout",QString::fromStdString("DVD succefully added!"));
        this->close();
    }
    else if (type->currentIndex()==4){
        CD *r = new class CD(this->getTitleCD()->text().toUtf8().constData(),
                               this->getAuthorCD()->text().toUtf8().constData(),
                               this->getDurationCD()->time().toString("hh:mm:ss").toUtf8().constData(),
                               this->getStudioCD()->text().toUtf8().constData(),
                               this->getChaptersCD()->value());
        l->addRessource(r);
        QMessageBox::information ( this, "Affichage ajout",QString::fromStdString("CD succefully added!"));
        this->close();
    }
    else if (type->currentIndex()==5){
        Digital_Ressource *r = new class Digital_Ressource(this->getTitleDigital_Ressource()->text().toUtf8().constData(),
                                                           this->getAuthorDigital_Ressource()->text().toUtf8().constData(),
                                                           this->getTypeDigital_Ressource()->text().toUtf8().constData(),
                                                           stoi(this->getSizeDigital_Ressource()->text().toUtf8().constData()),
                                                           this->getPathDigital_Ressource()->text().toUtf8().constData());
        l->addRessource(r);
        QMessageBox::information ( this, "Affichage ajout",QString::fromStdString("Digital Ressource succefully added!"));
        this->close();
    }
}

void Add::openPath(){

   QString text= QFileDialog::getOpenFileName(this, "Open file", QString());
   pathDigital_Ressource->setText(text);
   QFileInfo *File = new QFileInfo(text);
   sizeDigital_Ressource->setText(QString::number(File->size()));
   typeDigital_Ressource->setText(File->suffix());
}
Add::Add(){}
Add::Add(Library* _l) : QWidget()
{
    l = _l;

    this->setWindowTitle("Add Ressource");
    this->setFixedSize(300,500);
    QPalette pal = palette();
    pal.setColor(QPalette::Background, QColor(204,204,153));
    this->setAutoFillBackground(true);
    this->setPalette(pal);


   type->addItem("Book");
   type->addItem("Magazine");
   type->addItem("VHS");
   type->addItem("DVD");
   type->addItem("CD");
   type->addItem("Digital Ressource");

   /*-------------------Form Ressource-------------*/
   ressource->addRow(tr("&Title:"), title);
   ressource->addRow(tr("&Author:"), author);
   widgetRessource->setLayout(ressource);


   /*-------------------Form Book-------------*/
   book->addRow(tr("&Title:"), titleBook);
   book->addRow(tr("&Author:"), authorBook);
   book->addRow(tr("&Pages:"), pagesBook);
   pagesBook->setRange(0,1000000000);
   book->addRow(tr("Publication:"), publicationBook);
   book->addRow(tr("Collection:"), collectionBook);
   book->addRow(tr("Summary:"), summaryBook);
   widgetBook->setLayout(book);

   /*-------------------Form Magazine-------------*/
   magazine->addRow(tr("&Title:"), titleMagazine);
   magazine->addRow(tr("&Author:"), authorMagazine);
   magazine->addRow(tr("&Pages:"), pagesMagazine);
   pagesMagazine->setRange(0,1000000000);
   magazine->addRow(tr("Publication:"), publicationMagazine);
   magazine->addRow(tr("Collection:"), collectionMagazine);
   magazine->addRow(tr("Summary:"), summaryMagazine);
   magazine->addRow(tr("Editor:"), editorMagazine);
   magazine->addRow(tr("Artcles:"), articlesMagazine);
   articlesMagazine->setRange(0,1000000000);
   widgetMagazine->setLayout(magazine);

   /*-------------------Form VHS-------------*/
   _VHS->addRow(tr("&Title:"), titleVHS);
   _VHS->addRow(tr("&Author:"), authorVHS);
   _VHS->addRow(tr("&Duration:"), durationVHS);
   durationVHS->setDisplayFormat("hh:mm:ss");
   _VHS->addRow(tr("Studio:"), studioVHS);
   widgetVHS->setLayout(_VHS);

   /*-------------------Form DVD-------------*/
   _DVD->addRow(tr("&Title:"), titleDVD);
   _DVD->addRow(tr("&Author:"), authorDVD);
   _DVD->addRow(tr("&Duration:"), durationDVD);
    durationDVD->setDisplayFormat("hh:mm:ss");
   _DVD->addRow(tr("Studio:"), studioDVD);
   _DVD->addRow(tr("Chapters:"), chaptersDVD);
   chaptersDVD->setRange(0,1000000000);
   widgetDVD->setLayout(_DVD);

   /*-------------------Form CD-------------*/
   _CD->addRow(tr("&Title:"), titleCD);
   _CD->addRow(tr("&Author:"), authorCD);
   _CD->addRow(tr("&Duration:"), durationCD);
   durationCD->setDisplayFormat("hh:mm:ss");
   _CD->addRow(tr("Studio:"), studioCD);
   _CD->addRow(tr("Chapters:"), chaptersCD);
   chaptersCD->setRange(0,1000000000);
   widgetCD->setLayout(_CD);

   /*-------------------Form Digital Ressource-------------*/
   digital_Ressource->addRow(tr("&Title:"), titleDigital_Ressource);
   digital_Ressource->addRow(tr("&Author:"), authorDigital_Ressource);
   digital_Ressource->addRow(tr("&Path:"), pathDigital_Ressource);
   digital_Ressource->addRow(tr(""), chooseDigital_Ressource);
   digital_Ressource->addRow(tr("Extension:"), typeDigital_Ressource);
   typeDigital_Ressource->setReadOnly(true);
   digital_Ressource->addRow(tr("Size (Octets):"), sizeDigital_Ressource);
   sizeDigital_Ressource->setText("0");
   sizeDigital_Ressource->setReadOnly(true);
   widgetDigital_Ressource->setLayout(digital_Ressource);

   stackedWidget->addWidget(widgetBook);
   stackedWidget->addWidget(widgetMagazine);
   stackedWidget->addWidget(widgetVHS);
   stackedWidget->addWidget(widgetDVD);
   stackedWidget->addWidget(widgetCD);
   stackedWidget->addWidget(widgetDigital_Ressource);

    QObject::connect(type, SIGNAL(activated(int)), stackedWidget, SLOT(setCurrentIndex(int)));
    QObject::connect(chooseDigital_Ressource, SIGNAL(clicked()), this, SLOT(openPath()));
    QObject::connect(OK, SIGNAL(clicked()), this, SLOT(saveRessource()));

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(type);
    layout->addWidget(stackedWidget);
    layout->addWidget(OK);
    setLayout(layout);
}

