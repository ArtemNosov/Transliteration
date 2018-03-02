#ifndef TRANSLITERATIONMETHODS_H
#define TRANSLITERATIONMETHODS_H

#include <QMap>
#include <QList>
#include <QString>

class transliteration_methods{
public:
  transliteration_methods();
  QMap<QString, QString> GetRusMap(int aMethodNumber);
  QMap<QString, QString> GetEngMap(int aMethodNumber);
private:
  QMap<QString, QString> rusMap_;
  QMap<QString, QString> engMap_;
  QList<QMap<QString, QString> > transliterationRusMethod_;
  QList<QMap<QString, QString> > transliterationEngMethod_;
  // Устанавливает общие символы для всех методов.
  void SetStandartSymbols();
  // Устанавливает транлитерацию для больших букв.
  void SetUppercase();
  // Устанавливает обратный перевод.
  void SetEngMap();
  //
  void Nauchnuaya();
  void GOST7792000SystemA();
  void GOST7792000SystemB();
  void GOST1687671Table1();
  void GOST1687671Table2();
  void BGNPCGN();
  void BrytanskyStandart();
  void ALALC();
  void PrikazMVD782();
  void PrikazMVD995();
  void PrikazMVD310();
  void GOST525351();
  void StandartIKAO();
  void PrikazMID4271();
  void MezhdynarodnyeTellegramy();
};

#endif // TRANSLITERATIONMETHODS_H
