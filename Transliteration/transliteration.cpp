#include "transliteration.h"
#include "ui_transliteration.h"

Transliteration::Transliteration(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Transliteration){
    ui->setupUi(this);
    connect(ui->translateButton, SIGNAL(clicked()), this, SLOT(translateButtonProcessing()));
    connect(ui->bufferButton, SIGNAL(clicked()), this, SLOT(bufferButtonProcessing()));
}

void Transliteration::translateButtonProcessing(){
    QString str1 = ui->firstTextEdit->toPlainText();
    QString str2;
    QMap<QString, QString> map =  transliterationMethods.getMap(ui->comboBox->currentIndex());
    for (auto c : str1){
        str2 += map[c];
    }
    ui->secondTextEdit->setText(str2);
}

void Transliteration::bufferButtonProcessing(){

}

Transliteration::~Transliteration(){
    delete ui;
}
