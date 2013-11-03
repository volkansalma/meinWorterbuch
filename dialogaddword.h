#ifndef DIALOGADDWORD_H
#define DIALOGADDWORD_H

#include <QDialog>
#include <QtSql/QtSql>
#include <QMessageBox>

namespace Ui {
class DialogAddWord;
}

class DialogAddWord : public QDialog
{
    Q_OBJECT
    
public:
    explicit DialogAddWord(QWidget *parent = 0);
    ~DialogAddWord();
    
private slots:
    void on_pushButtonAddWord_clicked();

private:
    Ui::DialogAddWord *ui;
};

#endif // DIALOGADDWORD_H
