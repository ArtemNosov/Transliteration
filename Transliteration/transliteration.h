#ifndef TRANSLITERATION_H
#define TRANSLITERATION_H

#include <QWidget>

namespace Ui {
class Transliteration;
}

class Transliteration : public QWidget
{
    Q_OBJECT

public:
    explicit Transliteration(QWidget *parent = 0);
    ~Transliteration();

private:
    Ui::Transliteration *ui;
};

#endif // TRANSLITERATION_H
