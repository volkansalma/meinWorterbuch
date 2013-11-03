#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_dialogaddword.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    isFirstSettingsLodingCompleted = 0;
    ui->setupUi(this);

    db =  QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("meinWorterbuch.db");

    loadSettingsFromDB();

    timeIntervalMinute = (hour * 60) + minute;

    connect(&timer, SIGNAL(timeout()), this, SLOT(timerEventOneMinute()));
    timer.setInterval(60 * 1000);

    startTimer();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonAddWord_clicked()
{
    uiAddWordDialog.show();
}

void MainWindow::selectRandomRecordFromDB(WordRecord &result)
{
    result.isSuccefullySelected = 0;

    if(db.open())
    {
        QSqlQuery query = QSqlQuery("SELECT * FROM wordInfo ORDER BY RANDOM() LIMIT 1", db);

        if(query.next())
        {
            result.artikel =    query.value("artikel").toInt();
            result.suffix =     query.value("suffix").toInt();
            result.meaning =    query.value("meaning").toString();
            result.word =       query.value("word").toString();

            result.isSuccefullySelected = 1;
        }
        else
        {

            QMessageBox msgBox;
            msgBox.setText("New word could not selected from DB file.");
            msgBox.exec();
        }

        db.close();
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Database file could not opened.");
        msgBox.exec();
    }
}

void MainWindow::timerEventOneMinute()
{
    if(isActive)
    {
        pastMinuteAfterLastQuestion ++;

        if(pastMinuteAfterLastQuestion == timeIntervalMinute)
        {
            pastMinuteAfterLastQuestion = 0;

            WordRecord result;
            selectRandomRecordFromDB(result);

            if(result.isSuccefullySelected)
            {
                uiDialogWordQuestion.setWordInfo(result, isCross);
                uiDialogWordQuestion.show();
            }
        }
    }
}

void MainWindow::loadSettingsFromDB()
{
    if(db.open())
    {
        QSqlQuery query = QSqlQuery("SELECT * FROM settings;", db);

        if(query.next())
        {
            isActive = query.value("isActive").toBool();
            isCross = query.value("isCross").toBool();
            hour = query.value("hour").toInt();
            minute = query.value("minute").toInt();

            updateSettingsUi();
            isFirstSettingsLodingCompleted = 1;
        }
        else
        {
            QMessageBox msgBox;
            msgBox.setText("Settings could not be loaded from DB file.");
            msgBox.exec();
        }

        db.close();
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Database file could not opened.");
        msgBox.exec();
    }
}

void MainWindow::updateSettingsUi()
{
    ui->spinBoxMinute->setValue(minute);
    ui->spinBoxHour->setValue(hour);
    ui->checkBoxCross->setChecked(isCross);
    ui->checkBoxIsActive->setChecked(isActive);
}

void MainWindow::saveSettingsToDB()
{
    if(isFirstSettingsLodingCompleted)
    {
        if(db.open())
        {
            QString queryString;
            queryString += "UPDATE settings SET isActive = ";
            queryString += QString::number(isActive);
            queryString += ", isCross = ";
            queryString += QString::number(isCross);
            queryString += ", hour = ";
            queryString += QString::number(hour);
            queryString += ", minute = ";
            queryString += QString::number(minute);
            queryString += " WHERE handle = 1";

            QSqlQuery query;
            query.exec(queryString);
            query.lastError();

            db.close();
        }
        else
        {
            QMessageBox msgBox;
            msgBox.setText("Settings could not be saved to DB file.");
            msgBox.exec();
        }
    }
}

void MainWindow::getSettingsValuesFromUi()
{
    if(isFirstSettingsLodingCompleted)
    {
        minute = ui->spinBoxMinute->value();
        hour = ui->spinBoxHour->value();
        isCross = ui->checkBoxCross->isChecked();
        isActive = ui->checkBoxIsActive->isChecked();

        timeIntervalMinute = (hour * 60) + minute;
    }
}

void MainWindow::on_checkBoxIsActive_stateChanged()
{
    getSettingsValuesFromUi();
    saveSettingsToDB();
}

void MainWindow::on_checkBoxCross_stateChanged()
{
    getSettingsValuesFromUi();
    saveSettingsToDB();
}

void MainWindow::on_spinBoxHour_valueChanged()
{
    getSettingsValuesFromUi();
    saveSettingsToDB();

    startTimer();
}

void MainWindow::on_spinBoxMinute_valueChanged()
{
    getSettingsValuesFromUi();
    saveSettingsToDB();

    startTimer();
}

void MainWindow::startTimer()
{
    pastMinuteAfterLastQuestion = 0;
    timer.start();
}
