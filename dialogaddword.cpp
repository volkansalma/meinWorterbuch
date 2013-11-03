#include "dialogaddword.h"
#include "ui_dialogaddword.h"

DialogAddWord::DialogAddWord(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAddWord)
{
    ui->setupUi(this);
}

DialogAddWord::~DialogAddWord()
{
    delete ui;
}

void DialogAddWord::on_pushButtonAddWord_clicked()
{
    QSqlDatabase db;
    db =  QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("meinWorterbuch.db");

    if(db.open())
    {
        QString queryString;
        queryString += "INSERT INTO wordInfo (word, artikel, suffix, meaning) VALUES ('";
        queryString += ui->lineEditWord->text();
        queryString += "', ";
        queryString += QString::number(ui->comboBoxArtikel->currentIndex());
        queryString += ", ";
        queryString += QString::number(ui->comboBoxSuffix->currentIndex() );
        queryString += ", '";
        queryString += ui->lineEditMeaning->text();
        queryString += "')";

        QSqlQuery query;
        query.exec(queryString);
        query.lastError();

        db.close();
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Word could not be added to DB file.");
        msgBox.exec();
    }
}
