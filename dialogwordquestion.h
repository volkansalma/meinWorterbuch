#ifndef DIALOGWORDQUESTION_H
#define DIALOGWORDQUESTION_H

#include <QDialog>
#include <QPalette>
#include "WordRecord.h"


namespace Ui {
class dialogWordQuestion;
}

class dialogWordQuestion : public QDialog
{
    Q_OBJECT
    
public:
    explicit dialogWordQuestion(QWidget *parent = 0);
    ~dialogWordQuestion();
    
    void setWordInfo(WordRecord& wordInfo, bool isCross);

private slots:
    void on_pushButtonShowAnswer_clicked();

private:
    Ui::dialogWordQuestion *ui;

    void drawAllBlack();
    void drawAllBlue();
    void drawAllRed();
};

#endif // DIALOGWORDQUESTION_H
