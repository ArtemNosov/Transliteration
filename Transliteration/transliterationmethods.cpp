#include "transliterationmethods.h"

TransliterationMethods::TransliterationMethods(){
    Nauchnuaya();
    GOST7792000SystemA();
    GOST7792000SystemB();
    GOST1687671Table2();
}

void TransliterationMethods::Nauchnuaya(){
    rusMap.clear();
    setStandartSymbols();
    rusMap["е"] = "e";
    rusMap["ё"] = "ё";
    rusMap["ж"] = "ž";
    rusMap["и"] = "i";
    rusMap["й"] = "j";
    rusMap["х"] = "x";
    rusMap["ц"] = "c";
    rusMap["ч"] = "č";
    rusMap["ш"] = "š";
    rusMap["щ"] = "šč";
    rusMap["ъ"] = "\"";
    rusMap["ы"] = "y";
    rusMap["ь"] = "′";
    rusMap["э"] = "è";
    rusMap["ю"] = "ju";
    rusMap["я"] = "ja";
    setEngMap();
    setUppercase();
    transliterationRusMethod.push_back(rusMap);
}

void TransliterationMethods::GOST7792000SystemA(){
    rusMap.clear();
    setStandartSymbols();
    rusMap["е"] = "e";
    rusMap["ё"] = "ё";
    rusMap["ж"] = "ž";
    rusMap["и"] = "i";
    rusMap["й"] = "j";
    rusMap["х"] = "h";
    rusMap["ц"] = "c";
    rusMap["ч"] = "č";
    rusMap["ш"] = "š";
    rusMap["щ"] = "ŝ";
    rusMap["ъ"] = "\"";
    rusMap["ы"] = "y";
    rusMap["ь"] = "′";
    rusMap["э"] = "è";
    rusMap["ю"] = "û";
    rusMap["я"] = "â";
    setEngMap();
    setUppercase();
    transliterationRusMethod.push_back(rusMap);
}

void TransliterationMethods::GOST7792000SystemB(){
    rusMap.clear();
    setStandartSymbols();
    rusMap["е"] = "e";
    rusMap["ё"] = "yo";
    rusMap["ж"] = "zh";
    rusMap["и"] = "i";
    rusMap["й"] = "j";
    rusMap["х"] = "x";
    rusMap["ц"] = "c";
    rusMap["ч"] = "ch";
    rusMap["ш"] = "sh";
    rusMap["щ"] = "shh";
    rusMap["ъ"] = "``";
    rusMap["ы"] = "y`";
    rusMap["ь"] = "`";
    rusMap["э"] = "e`";
    rusMap["ю"] = "yu";
    rusMap["я"] = "ya";
    setEngMap();
    setUppercase();
    transliterationRusMethod.push_back(rusMap);
}

void TransliterationMethods::GOST1687671Table2(){
    rusMap.clear();
    setStandartSymbols();
    rusMap["е"] = "e";
    rusMap["ё"] = "jo";
    rusMap["ж"] = "zh";
    rusMap["и"] = "i";
    rusMap["й"] = "jj";
    rusMap["х"] = "kh";
    rusMap["ц"] = "c";
    rusMap["ч"] = "ch";
    rusMap["ш"] = "sh";
    rusMap["щ"] = "shh";
    rusMap["ъ"] = "\"";
    rusMap["ы"] = "y";
    rusMap["ь"] = "'";
    rusMap["э"] = "eh";
    rusMap["ю"] = "ju";
    rusMap["я"] = "ja";
    setEngMap();
    setUppercase();
    transliterationRusMethod.push_back(rusMap);
}

void TransliterationMethods::setStandartSymbols(){
    rusMap["а"] = "a";
    rusMap["б"] = "b";
    rusMap["в"] = "v";
    rusMap["г"] = "g";
    rusMap["д"] = "d";
    rusMap["з"] = "z";
    rusMap["к"] = "k";
    rusMap["л"] = "l";
    rusMap["м"] = "m";
    rusMap["н"] = "n";
    rusMap["о"] = "o";
    rusMap["п"] = "p";
    rusMap["р"] = "r";
    rusMap["с"] = "s";
    rusMap["т"] = "t";
    rusMap["у"] = "u";
    rusMap["ф"] = "f";
    rusMap[" "] = " ";
    rusMap["\n"] = "\n";
}

void TransliterationMethods::setUppercase(){
    rusMap["А"] = rusMap["a"];
    rusMap["Б"] = rusMap["б"];
    rusMap["В"] = rusMap["в"];
    rusMap["Г"] = rusMap["г"];
    rusMap["Д"] = rusMap["д"];
    rusMap["Е"] = rusMap["е"];
    rusMap["Ё"] = rusMap["ё"];
    rusMap["Ж"] = rusMap["ж"];
    rusMap["З"] = rusMap["з"];
    rusMap["И"] = rusMap["и"];
    rusMap["Й"] = rusMap["й"];
    rusMap["К"] = rusMap["к"];
    rusMap["Л"] = rusMap["л"];
    rusMap["М"] = rusMap["м"];
    rusMap["Н"] = rusMap["н"];
    rusMap["О"] = rusMap["о"];
    rusMap["П"] = rusMap["п"];
    rusMap["Р"] = rusMap["р"];
    rusMap["С"] = rusMap["с"];
    rusMap["Т"] = rusMap["т"];
    rusMap["У"] = rusMap["у"];
    rusMap["Ф"] = rusMap["ф"];
    rusMap["Х"] = rusMap["х"];
    rusMap["Ц"] = rusMap["ц"];
    rusMap["Ч"] = rusMap["ч"];
    rusMap["Ш"] = rusMap["ш"];
    rusMap["Щ"] = rusMap["щ"];
    rusMap["Ъ"] = rusMap["ъ"];
    rusMap["Ы"] = rusMap["ы"];
    rusMap["Ь"] = rusMap["ь"];
    rusMap["Э"] = rusMap["э"];
    rusMap["Ю"] = rusMap["ю"];
    rusMap["Я"] = rusMap["я"];
    rusMap[" "] = rusMap[" "];
}

void TransliterationMethods::setEngMap(){
    engMap.clear();
    foreach (QString key, rusMap.keys()){
      engMap[rusMap.value(key)] = key;
    }
    transliterationEngMethod.push_back(engMap);
}

QMap<QString, QString> TransliterationMethods::getRusMap(int methodNumber){
    return transliterationRusMethod[methodNumber];
}

QMap<QString, QString> TransliterationMethods::getEngMap(int methodNumber){
    return transliterationEngMethod[methodNumber];
}
