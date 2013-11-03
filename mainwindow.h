#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QtSql/QtSql>
#include <QTimer>
#include "dialogaddword.h"
#include "dialogwordquestion.h"
#include "WordRecord.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_pushButtonAddWord_clicked();

    void on_checkBoxIsActive_stateChanged();

    void on_checkBoxCross_stateChanged();

    void on_spinBoxHour_valueChanged();

    void on_spinBoxMinute_valueChanged();

    void timerEventOneMinute();

private:
    Ui::MainWindow *ui;
    DialogAddWord uiAddWordDialog;
    dialogWordQuestion uiDialogWordQuestion;
    QSqlDatabase db;
    QTimer timer;

    unsigned long timeIntervalMinute;
    unsigned long pastMinuteAfterLastQuestion;

    bool isActive;
    bool isCross;
    unsigned int hour;
    unsigned int minute;

    bool isFirstSettingsLodingCompleted;

    void loadSettingsFromDB();
    void saveSettingsToDB();
    void updateSettingsUi();
    void getSettingsValuesFromUi();
    void startTimer();
    void selectRandomRecordFromDB(WordRecord &result);
};

#endif // MAINWINDOW_H
