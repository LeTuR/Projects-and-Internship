#ifndef ADD_H
#define ADD_H
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
#include <QCalendarWidget>
#include <QSpinBox>
#include <QTextEdit>
#include <QDateEdit>
#include <QTimeEdit>
#include <QFileInfo>
#include <Library.hpp>



class Add : public QWidget
{

    Q_OBJECT

public:
    Add();
    Add(Library*_l);
//Book Accesor
    QLineEdit* getTitleBook();
    QLineEdit* getAuthorBook();
    QSpinBox* getPagesBook();
    QDateEdit* getPublicationBook();
    QLineEdit* getCollectionBook();
    QTextEdit* getSummaryBook();
//Magazine Accesor
    QLineEdit* getTitleMagazine();
    QLineEdit* getAuthorMagazine();
    QSpinBox* getPagesMagazine();
    QDateEdit* getPublicationMagazine();
    QLineEdit* getCollectionMagazine();
    QTextEdit* getSummaryMagazine();
    QLineEdit* getEditorMagazine();
    QSpinBox* getArticlesMagazine();
//VHS Accesor
    QLineEdit* getTitleVHS();
    QLineEdit* getAuthorVHS();
    QTimeEdit* getDurationVHS();
    QLineEdit* getStudioVHS();
//DVD Accesor
    QLineEdit* getTitleDVD();
    QLineEdit* getAuthorDVD();
    QTimeEdit* getDurationDVD();
    QLineEdit* getStudioDVD();
    QSpinBox* getChaptersDVD();
//CD Accesor
    QLineEdit* getTitleCD();
    QLineEdit* getAuthorCD();
    QTimeEdit* getDurationCD();
    QLineEdit* getStudioCD();
    QSpinBox* getChaptersCD();
//Digital Ressource Accesor
    QLineEdit* getTitleDigital_Ressource();
    QLineEdit* getAuthorDigital_Ressource();
    QLineEdit* getPathDigital_Ressource();
    QLineEdit* getTypeDigital_Ressource();
    QLineEdit* getSizeDigital_Ressource();

private:
    Library* l;

    QStackedWidget *stackedWidget = new QStackedWidget;
    QComboBox *type = new QComboBox;
    QPushButton *OK = new QPushButton("Add Ressource");


//Ressource
    QWidget *widgetRessource = new QWidget();
    QFormLayout *ressource = new QFormLayout;
    QLineEdit *title = new QLineEdit;
    QLineEdit *author = new QLineEdit;
//Book
    QWidget *widgetBook = new QWidget();
    QFormLayout *book = new QFormLayout;
    QLineEdit *titleBook = new QLineEdit;
    QLineEdit *authorBook = new QLineEdit;
    QSpinBox *pagesBook = new QSpinBox;
    QDateEdit *publicationBook = new QDateEdit;
    QLineEdit *collectionBook = new QLineEdit;
    QTextEdit *summaryBook = new QTextEdit;
//Magazine
    QFormLayout *magazine = new QFormLayout;
    QWidget *widgetMagazine = new QWidget();
    QLineEdit *titleMagazine = new QLineEdit;
    QLineEdit *authorMagazine = new QLineEdit;
    QSpinBox *pagesMagazine = new QSpinBox;
    QDateEdit *publicationMagazine = new QDateEdit;
    QLineEdit *collectionMagazine = new QLineEdit;
    QTextEdit *summaryMagazine = new QTextEdit;
    QLineEdit *editorMagazine = new QLineEdit;
    QSpinBox *articlesMagazine = new QSpinBox;
//VHS
    QWidget *widgetVHS = new QWidget();
    QFormLayout *_VHS = new QFormLayout;
    QLineEdit *titleVHS = new QLineEdit;
    QLineEdit *authorVHS = new QLineEdit;
    QTimeEdit *durationVHS = new QTimeEdit;
    QLineEdit *studioVHS = new QLineEdit;
//DVD
    QWidget *widgetDVD = new QWidget();
    QFormLayout *_DVD = new QFormLayout;
    QLineEdit *titleDVD = new QLineEdit;
    QLineEdit *authorDVD = new QLineEdit;
    QTimeEdit *durationDVD = new QTimeEdit;
    QLineEdit *studioDVD = new QLineEdit;
    QSpinBox *chaptersDVD = new QSpinBox;
//CD
    QFormLayout *_CD = new QFormLayout;
    QWidget *widgetCD = new QWidget();
    QLineEdit *titleCD = new QLineEdit;
    QLineEdit *authorCD = new QLineEdit;
    QTimeEdit *durationCD = new QTimeEdit;
    QLineEdit *studioCD = new QLineEdit;
    QSpinBox *chaptersCD = new QSpinBox;
//Digital_Ressource
    QFormLayout *digital_Ressource = new QFormLayout;
    QWidget *widgetDigital_Ressource = new QWidget();
    QLineEdit *titleDigital_Ressource = new QLineEdit;
    QLineEdit *authorDigital_Ressource = new QLineEdit;
    QLineEdit *pathDigital_Ressource = new QLineEdit;
    QPushButton *chooseDigital_Ressource = new QPushButton("Choose Path");
    QLineEdit *typeDigital_Ressource =  new QLineEdit;
    QLineEdit *sizeDigital_Ressource = new QLineEdit;

public slots:
    void openPath();
    void saveRessource();
};

#endif // ADD_H
