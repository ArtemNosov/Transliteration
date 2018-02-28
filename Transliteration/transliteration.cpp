#include "transliteration.h"
#include "ui_transliteration.h"

Transliteration::Transliteration(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Transliteration)
{
    ui->setupUi(this);
}

Transliteration::~Transliteration()
{
    delete ui;
}
