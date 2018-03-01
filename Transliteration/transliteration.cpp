#include "transliteration.h"
#include "ui_transliteration.h"

#include <QDebug>

Transliteration::Transliteration(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Transliteration){
    ui->setupUi(this);
    ui->secondTextEdit->setReadOnly(true);
    ui->bufferButton->setEnabled(false);

    connect(ui->translateButton, SIGNAL(clicked()), this, SLOT(translateButtonProcessing()));
    connect(ui->bufferButton, SIGNAL(clicked()), this, SLOT(bufferButtonProcessing()));
}

void Transliteration::translateButtonProcessing(){
    bool isFound = false;
    if (ui->checkBox->isChecked()){
        QFile dictionary("dictionary.txt");
        dictionary.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream writeStream(&dictionary);
        writeStream.setCodec("UTF-8");
        QString space = writeStream.readLine();
        while (!writeStream.atEnd()) {
            QString rus = writeStream.readLine();
            QString eng = writeStream.readLine();

            if (ui->rusButton->isChecked() && (ui->firstTextEdit->toPlainText() == rus)){
                ui->secondTextEdit->setText(eng);
                ui->bufferButton->setEnabled(true);
                ui->warningLabel->setText("");
                isFound = true;
            } else if (ui->firstTextEdit->toPlainText() == eng){
                ui->secondTextEdit->setText(rus);
                ui->bufferButton->setEnabled(true);
                ui->warningLabel->setText("");
                isFound = true;
            }
        }
        dictionary.close();
    }

    if (!isFound){
        QString resultText;
        QMap<QString, QString> map;
        if (ui->rusButton->isChecked()){
            map =  transliterationMethods.getRusMap(ui->comboBox->currentIndex());
        } else {
            map =  transliterationMethods.getEngMap(ui->comboBox->currentIndex());
        }

        bool isCorrect = true;
        int index = 1;
        for (int i = 0; i < ui->firstTextEdit->toPlainText().size(); i += index){
            if (map[ui->firstTextEdit->toPlainText().mid(i, 4)] != ""){
                resultText += map[ui->firstTextEdit->toPlainText().mid(i, 4)];
                index = 4;
            } else if (map[ui->firstTextEdit->toPlainText().mid(i, 3)] != ""){
                resultText += map[ui->firstTextEdit->toPlainText().mid(i, 3)];
                index = 3;
            } else if (map[ui->firstTextEdit->toPlainText().mid(i, 2)] != ""){
                resultText += map[ui->firstTextEdit->toPlainText().mid(i, 2)];
                index = 2;
            } else if (map[ui->firstTextEdit->toPlainText().mid(i, 1)] != ""){
                resultText += map[ui->firstTextEdit->toPlainText().mid(i, 1)];
                index = 1;
            } else{
                isCorrect = false;
            }
        }
        if (isCorrect){
            ui->secondTextEdit->setText(resultText);
            ui->bufferButton->setEnabled(true);
            ui->warningLabel->setText("");
        } else{
            ui->bufferButton->setEnabled(false);
            ui->warningLabel->setText("Провертье введенные данные!");
            ui->secondTextEdit->clear();
        }
    }
}

void Transliteration::bufferButtonProcessing(){
    QApplication::clipboard()->setText(ui->secondTextEdit->toPlainText());
    QFile dictionary("dictionary.txt");
    dictionary.open(QIODevice::Append | QIODevice::Text | QIODevice::ReadWrite);
    QTextStream writeStream(&dictionary);
    writeStream.setCodec("UTF-8");
    if (ui->rusButton->isChecked()){
        writeStream << "\n" + ui->firstTextEdit->toPlainText() +
                       "\n" + ui->secondTextEdit->toPlainText();
    }
    else{
        writeStream << "\n" + ui->secondTextEdit->toPlainText() +
                       "\n" +  ui->firstTextEdit->toPlainText();
    }
    dictionary.close();
}



Transliteration::~Transliteration(){
    delete ui;
}
