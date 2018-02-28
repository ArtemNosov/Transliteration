#include "transliterationmethods.h"

TransliterationMethods::TransliterationMethods(){
    Nauchnuaya();
    GOST7792000SystemA();
    GOST7792000SystemB();
    GOST1687671Table2();
}

void TransliterationMethods::Nauchnuaya(){
    map.clear();
    setStandartSymbols();
    map["е"] = "e";
    map["ё"] = "ё";
    map["ж"] = "ž";
    map["и"] = "i";
    map["й"] = "j";
    map["х"] = "ch";
    map["ц"] = "c";
    map["ч"] = "č";
    map["ш"] = "š";
    map["щ"] = "šč";
    map["ъ"] = "\"";
    map["ы"] = "y";
    map["ь"] = "′";
    map["э"] = "è";
    map["ю"] = "ju";
    map["я"] = "ja";
    setUppercase();
    transliterationMethod.push_back(map);
}

void TransliterationMethods::GOST7792000SystemA(){
    map.clear();
    setStandartSymbols();
    map["е"] = "e";
    map["ё"] = "ё";
    map["ж"] = "ž";
    map["и"] = "i";
    map["й"] = "j";
    map["х"] = "h";
    map["ц"] = "c";
    map["ч"] = "č";
    map["ш"] = "š";
    map["щ"] = "ŝ";
    map["ъ"] = "\"";
    map["ы"] = "y";
    map["ь"] = "′";
    map["э"] = "è";
    map["ю"] = "û";
    map["я"] = "â";
    setUppercase();
    transliterationMethod.push_back(map);
}

void TransliterationMethods::GOST7792000SystemB(){
    map.clear();
    setStandartSymbols();
    map["е"] = "e";
    map["ё"] = "yo";
    map["ж"] = "zh";
    map["и"] = "i";
    map["й"] = "j";
    map["х"] = "x";
    map["ц"] = "cz";
    map["ч"] = "ch";
    map["ш"] = "sh";
    map["щ"] = "shh";
    map["ъ"] = "``";
    map["ы"] = "y`";
    map["ь"] = "`";
    map["э"] = "e`";
    map["ю"] = "yu";
    map["я"] = "ya";
    setUppercase();
    transliterationMethod.push_back(map);
}

void TransliterationMethods::GOST1687671Table2(){
    map.clear();
    setStandartSymbols();
    map["е"] = "e";
    map["ё"] = "jo";
    map["ж"] = "zh";
    map["и"] = "i";
    map["й"] = "jj";
    map["х"] = "kh";
    map["ц"] = "c";
    map["ч"] = "ch";
    map["ш"] = "sh";
    map["щ"] = "shh";
    map["ъ"] = "\"";
    map["ы"] = "y";
    map["ь"] = "'";
    map["э"] = "eh";
    map["ю"] = "ju";
    map["я"] = "ja";
    setUppercase();
    transliterationMethod.push_back(map);
}

void TransliterationMethods::setStandartSymbols(){
    map["а"] = "a";
    map["б"] = "b";
    map["в"] = "v";
    map["г"] = "g";
    map["д"] = "d";
    map["з"] = "z";
    map["к"] = "k";
    map["л"] = "l";
    map["м"] = "m";
    map["н"] = "n";
    map["о"] = "o";
    map["п"] = "p";
    map["р"] = "r";
    map["с"] = "s";
    map["т"] = "t";
    map["у"] = "u";
    map["ф"] = "f";
    map[" "] = " ";
    map["\n"] = "\n";
}

void TransliterationMethods::setUppercase(){
    map["А"] = map["a"];
    map["Б"] = map["б"];
    map["В"] = map["в"];
    map["Г"] = map["г"];
    map["Д"] = map["д"];
    map["Е"] = map["е"];
    map["Ё"] = map["ё"];
    map["Ж"] = map["ж"];
    map["З"] = map["з"];
    map["И"] = map["и"];
    map["Й"] = map["й"];
    map["К"] = map["к"];
    map["Л"] = map["л"];
    map["М"] = map["м"];
    map["Н"] = map["н"];
    map["О"] = map["о"];
    map["П"] = map["п"];
    map["Р"] = map["р"];
    map["С"] = map["с"];
    map["Т"] = map["т"];
    map["У"] = map["у"];
    map["Ф"] = map["ф"];
    map["Х"] = map["х"];
    map["Ц"] = map["ц"];
    map["Ч"] = map["ч"];
    map["Ш"] = map["ш"];
    map["Щ"] = map["щ"];
    map["Ъ"] = map["ъ"];
    map["Ы"] = map["ы"];
    map["Ь"] = map["ь"];
    map["Э"] = map["э"];
    map["Ю"] = map["ю"];
    map["Я"] = map["я"];
    map[" "] = map[" "];
}

QMap<QString, QString> TransliterationMethods::getMap(int methodNumber){
    return transliterationMethod[methodNumber];
}
