#ifndef TRANSLITERATION_H
#define TRANSLITERATION_H

#include "transliteration_methods.h"
#include <QWidget>
#include <QString>
#include <QClipboard>
#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <fstream>
#include <QList>
#include <QPair>
#include <QKeyEvent>

namespace Ui {
class Transliteration;
}

class transliteration : public QWidget{
  Q_OBJECT
public:
  explicit transliteration(QWidget *parent = 0);
  // Функция для тестирования.
  QString TestFunction(bool aIsDictionary, bool aIsRus, int aTranslateIndex, QString aText);
  ~transliteration();
public slots:
  // Слот, срабатывающий при нажатии на кнопку "Перевести".
  void TranslateButtonProcessing();
  // Слот, срабатывающий при нажатии на кнопку "Копировать в буфер".
  void BufferButtonProcessing();
protected:
  void keyPressEvent(QKeyEvent* aEvent);
private:
  Ui::Transliteration *ui_;
  transliteration_methods transliterationMethods_;
};

#endif // TRANSLITERATION_H
