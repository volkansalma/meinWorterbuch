#include "dialogwordquestion.h"
#include "ui_dialogwordquestion.h"

#include "WordRecord.h"

dialogWordQuestion::dialogWordQuestion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialogWordQuestion)
{
    ui->setupUi(this);
}

dialogWordQuestion::~dialogWordQuestion()
{
    delete ui;
}


void dialogWordQuestion::drawAllRed()
{
     QPalette palette = ui->labelArtikel->palette();
     palette.setColor(ui->labelWord->foregroundRole(), Qt::red);
     ui->labelArtikel->setPalette(palette);
     ui->labelMeaning->setPalette(palette);
     ui->labelSuffix->setPalette(palette);
     ui->labelWord->setPalette(palette);
}

void dialogWordQuestion::drawAllBlue()
{
     QPalette palette = ui->labelArtikel->palette();
     palette.setColor(ui->labelWord->foregroundRole(), Qt::blue);
     ui->labelArtikel->setPalette(palette);
     ui->labelMeaning->setPalette(palette);
     ui->labelSuffix->setPalette(palette);
     ui->labelWord->setPalette(palette);
}

void dialogWordQuestion::drawAllBlack()
{
     QPalette palette = ui->labelArtikel->palette();
     palette.setColor(ui->labelWord->foregroundRole(), Qt::black);
     ui->labelArtikel->setPalette(palette);
     ui->labelMeaning->setPalette(palette);
     ui->labelSuffix->setPalette(palette);
     ui->labelWord->setPalette(palette);
}

void dialogWordQuestion::setWordInfo(WordRecord& wordInfo, bool isCross)
{

    drawAllBlack();
    ui->labelWord->setText(wordInfo.word);
    ui->labelMeaning->setText(wordInfo.meaning);

    switch(wordInfo.artikel)
    {
        case 0: // --
            drawAllBlack();
            ui->labelArtikel->setText("");
            break;

        case 1: //-- der
            drawAllBlue();
            ui->labelArtikel->setText("-der");
            break;

        case 2: //-- die
            drawAllRed();
            ui->labelArtikel->setText("-die");
            break;

        case 3: //-- das
            drawAllBlack();
            ui->labelArtikel->setText("-das");
            break;

    }

    switch(wordInfo.suffix)
    {
        case 0:
            ui->labelSuffix->setText("");
            break;

        case 1:
            ui->labelSuffix->setText("-");
            break;

        case 2:
            ui->labelSuffix->setText("-s");
            break;

        case 3:
            ui->labelSuffix->setText("-n");
            break;

        case 4:
            ui->labelSuffix->setText("-e");
            break;

        case 5:
            ui->labelSuffix->setText("-(n)en");
            break;
        case 6:
            ui->labelSuffix->setText("-e");
            break;
        case 7:
            ui->labelSuffix->setText("-er");
            break;
    }

    if(isCross)
    {
        ui->labelSuffix->setHidden(1);
        ui->labelArtikel->setHidden(1);
        ui->labelWord->setHidden(1);
    }
    else
    {
        ui->labelMeaning->setHidden(1);
    }
}

void dialogWordQuestion::on_pushButtonShowAnswer_clicked()
{

    ui->labelSuffix->setHidden(0);
    ui->labelArtikel->setHidden(0);
    ui->labelWord->setHidden(0);
    ui->labelMeaning->setHidden(0);
}
