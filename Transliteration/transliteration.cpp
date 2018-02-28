#include "transliteration.h"
#include "ui_transliteration.h"

#include <QDebug>

Transliteration::Transliteration(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Transliteration){
    ui->setupUi(this);
    connect(ui->translateButton, SIGNAL(clicked()), this, SLOT(translateButtonProcessing()));
    connect(ui->bufferButton, SIGNAL(clicked()), this, SLOT(bufferButtonProcessing()));

}

void Transliteration::translateButtonProcessing(){

    bool isFound = false;
    if (ui->checkBox->isChecked()){
        QFile dictionary("dictionary.txt");
        dictionary.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream writeStream(&dictionary);
        QString space = writeStream.readLine();
        while (!writeStream.atEnd()) {
            QString rus = writeStream.readLine();
            QString eng = writeStream.readLine();
            if (ui->rusButton->isChecked() && (ui->firstTextEdit->toPlainText() == rus)){
                ui->secondTextEdit->setText(eng);
                isFound = true;
            }
            else if (ui->firstTextEdit->toPlainText() == eng){
                ui->secondTextEdit->setText(rus);
                isFound = true;
            }
        }
        dictionary.close();
    }

    if (!isFound){
        QString str1 = ui->firstTextEdit->toPlainText();
        QString str2;
        QMap<QString, QString> map =  transliterationMethods.getMap(ui->comboBox->currentIndex());
        for (auto c : str1){
            str2 += map[c];
        }
        ui->secondTextEdit->setText(str2);
    }
}

void Transliteration::bufferButtonProcessing(){
    QApplication::clipboard()->setText(ui->secondTextEdit->toPlainText());
    QFile dictionary("dictionary.txt");
    dictionary.open(QIODevice::Append | QIODevice::Text | QIODevice::ReadWrite);
    QTextStream writeStream(&dictionary);
    if (ui->rusButton->isChecked()){
        writeStream << "\n" + ui->firstTextEdit->toPlainText() + "\n" + ui->secondTextEdit->toPlainText();
    }
    else{
        writeStream << "\n" + ui->secondTextEdit->toPlainText() + "\n" +  ui->firstTextEdit->toPlainText();
    }
    dictionary.close();
}


Transliteration::~Transliteration(){
    delete ui;
}
