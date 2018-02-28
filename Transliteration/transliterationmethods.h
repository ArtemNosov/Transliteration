#ifndef TRANSLITERATIONMETHODS_H
#define TRANSLITERATIONMETHODS_H

#include <QMap>
#include <QList>
#include <QString>



class TransliterationMethods
{
public:
    TransliterationMethods();
    QMap<QString, QString> getMap(int methodNumber);

private:
    QMap<QString, QString> map;
    QList<QMap<QString, QString> > transliterationMethod;

    void setStandartSymbols();
    void setUppercase();

    void Nauchnuaya();
    void GOST7792000SystemA();
    void GOST7792000SystemB();
    void GOST1687671Table2();

};

#endif // TRANSLITERATIONMETHODS_H
