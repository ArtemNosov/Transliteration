#ifndef TRANSLITERATIONMETHODS_H
#define TRANSLITERATIONMETHODS_H

#include <QMap>
#include <QList>
#include <QString>

class TransliterationMethods
{
public:
    TransliterationMethods();
    QMap<QString, QString> getRusMap(int methodNumber);
    QMap<QString, QString> getEngMap(int methodNumber);

private:
    QMap<QString, QString> rusMap;
    QMap<QString, QString> engMap;
    QList<QMap<QString, QString> > transliterationRusMethod;
    QList<QMap<QString, QString> > transliterationEngMethod;

    void setStandartSymbols();
    void setUppercase();
    void setEngMap();

    void Nauchnuaya();
    void GOST7792000SystemA();
    void GOST7792000SystemB();
    void GOST1687671Table2();
};

#endif // TRANSLITERATIONMETHODS_H
