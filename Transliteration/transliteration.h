#ifndef TRANSLITERATION_H
#define TRANSLITERATION_H

#include <QWidget>
#include <QString>
#include <QClipboard>
#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <fstream>
#include <QList>
#include <QPair>

#include "transliterationmethods.h"

namespace Ui {
class Transliteration;
}

class Transliteration : public QWidget
{
    Q_OBJECT

public:
    explicit Transliteration(QWidget *parent = 0);
    ~Transliteration();

public slots:
    void translateButtonProcessing();
    void bufferButtonProcessing();


private:
    Ui::Transliteration *ui;
    TransliterationMethods transliterationMethods;
};

#endif // TRANSLITERATION_H
