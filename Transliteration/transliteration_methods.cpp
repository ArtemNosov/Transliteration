#include "transliteration_methods.h"

transliteration_methods::transliteration_methods(){
  Nauchnuaya();
  GOST7792000SystemA();
  GOST7792000SystemB();
  GOST1687671Table1();
  GOST1687671Table2();
  BGNPCGN();
  BrytanskyStandart();
  ALALC();
  PrikazMVD782();
  PrikazMVD995();
  PrikazMVD310();
  GOST525351();
  StandartIKAO();
  PrikazMID4271();
  MezhdynarodnyeTellegramy();
}

void transliteration_methods::Nauchnuaya(){
  rusMap_.clear();
  SetStandartSymbols();
  rusMap_["е"] = "e";
  rusMap_["ё"] = "ё";
  rusMap_["ж"] = "ž";
  rusMap_["и"] = "i";
  rusMap_["й"] = "j";
  rusMap_["х"] = "x";
  rusMap_["ц"] = "c";
  rusMap_["ч"] = "č";
  rusMap_["ш"] = "š";
  rusMap_["щ"] = "šč";
  rusMap_["ъ"] = "\"";
  rusMap_["ы"] = "y";
  rusMap_["ь"] = "′";
  rusMap_["э"] = "è";
  rusMap_["ю"] = "ju";
  rusMap_["я"] = "ja";
  SetEngMap();
  SetUppercase();
  transliterationRusMethod_.push_back(rusMap_);
}

void transliteration_methods::GOST7792000SystemA(){
  rusMap_.clear();
  SetStandartSymbols();
  rusMap_["е"] = "e";
  rusMap_["ё"] = "ё";
  rusMap_["ж"] = "ž";
  rusMap_["и"] = "i";
  rusMap_["й"] = "j";
  rusMap_["х"] = "h";
  rusMap_["ц"] = "c";
  rusMap_["ч"] = "č";
  rusMap_["ш"] = "š";
  rusMap_["щ"] = "ŝ";
  rusMap_["ъ"] = "\"";
  rusMap_["ы"] = "y";
  rusMap_["ь"] = "′";
  rusMap_["э"] = "è";
  rusMap_["ю"] = "û";
  rusMap_["я"] = "â";
  SetEngMap();
  SetUppercase();
  transliterationRusMethod_.push_back(rusMap_);
}

void transliteration_methods::GOST7792000SystemB(){
  rusMap_.clear();
  SetStandartSymbols();
  rusMap_["е"] = "e";
  rusMap_["ё"] = "yo";
  rusMap_["ж"] = "zh";
  rusMap_["и"] = "i";
  rusMap_["й"] = "j";
  rusMap_["х"] = "x";
  rusMap_["ц"] = "c";
  rusMap_["ч"] = "ch";
  rusMap_["ш"] = "sh";
  rusMap_["щ"] = "shh";
  rusMap_["ъ"] = "``";
  rusMap_["ы"] = "y`";
  rusMap_["ь"] = "`";
  rusMap_["э"] = "e`";
  rusMap_["ю"] = "yu";
  rusMap_["я"] = "ya";
  SetEngMap();
  SetUppercase();
  transliterationRusMethod_.push_back(rusMap_);
}

void transliteration_methods::GOST1687671Table1(){
  rusMap_.clear();
  SetStandartSymbols();
  rusMap_["е"] = "e";
  rusMap_["ё"] = "ё";
  rusMap_["ж"] = "ž";
  rusMap_["и"] = "i";
  rusMap_["й"] = "j";
  rusMap_["х"] = "h";
  rusMap_["ц"] = "c";
  rusMap_["ч"] = "č";
  rusMap_["ш"] = "š";
  rusMap_["щ"] = "ŝ";
  rusMap_["ъ"] = "\"";
  rusMap_["ы"] = "y";
  rusMap_["ь"] = "'";
  rusMap_["э"] = "è";
  rusMap_["ю"] = "û";
  rusMap_["я"] = "â";
  SetEngMap();
  SetUppercase();
  transliterationRusMethod_.push_back(rusMap_);
}

void transliteration_methods::GOST1687671Table2(){
  rusMap_.clear();
  SetStandartSymbols();
  rusMap_["е"] = "e";
  rusMap_["ё"] = "jo";
  rusMap_["ж"] = "zh";
  rusMap_["и"] = "i";
  rusMap_["й"] = "jj";
  rusMap_["х"] = "kh";
  rusMap_["ц"] = "c";
  rusMap_["ч"] = "ch";
  rusMap_["ш"] = "sh";
  rusMap_["щ"] = "shh";
  rusMap_["ъ"] = "\"";
  rusMap_["ы"] = "y";
  rusMap_["ь"] = "'";
  rusMap_["э"] = "eh";
  rusMap_["ю"] = "ju";
  rusMap_["я"] = "ja";
  SetEngMap();
  SetUppercase();
  transliterationRusMethod_.push_back(rusMap_);
}

void transliteration_methods::BGNPCGN(){
  rusMap_.clear();
  SetStandartSymbols();
  rusMap_["е"] = "e";
  rusMap_["ё"] = "ë";
  rusMap_["ж"] = "zh";
  rusMap_["и"] = "i";
  rusMap_["й"] = "y";
  rusMap_["х"] = "kh";
  rusMap_["ц"] = "ts";
  rusMap_["ч"] = "ch";
  rusMap_["ш"] = "sh";
  rusMap_["щ"] = "shch";
  rusMap_["ъ"] = "\"";
  rusMap_["ы"] = "y";
  rusMap_["ь"] = "'";
  rusMap_["э"] = "e";
  rusMap_["ю"] = "yu";
  rusMap_["я"] = "ya";
  SetEngMap();
  SetUppercase();
  transliterationRusMethod_.push_back(rusMap_);
}

void transliteration_methods::BrytanskyStandart(){
  rusMap_.clear();
  SetStandartSymbols();
  rusMap_["е"] = "e";
  rusMap_["ё"] = "ë";
  rusMap_["ж"] = "zh";
  rusMap_["и"] = "i";
  rusMap_["й"] = "ĭ";
  rusMap_["х"] = "kh";
  rusMap_["ц"] = "ts";
  rusMap_["ч"] = "ch";
  rusMap_["ш"] = "sh";
  rusMap_["щ"] = "shch";
  rusMap_["ъ"] = "\"";
  rusMap_["ы"] = "ȳ";
  rusMap_["ь"] = "'";
  rusMap_["э"] = "é";
  rusMap_["ю"] = "yu";
  rusMap_["я"] = "ya";
  SetEngMap();
  SetUppercase();
  transliterationRusMethod_.push_back(rusMap_);
}

void transliteration_methods::ALALC(){
  rusMap_.clear();
  SetStandartSymbols();
  rusMap_["е"] = "e";
  rusMap_["ё"] = "ë";
  rusMap_["ж"] = "zh";
  rusMap_["и"] = "i";
  rusMap_["й"] = "ĭ";
  rusMap_["х"] = "kh";
  rusMap_["ц"] = "t͡s";
  rusMap_["ч"] = "ch";
  rusMap_["ш"] = "sh";
  rusMap_["щ"] = "shch";
  rusMap_["ъ"] = "\"";
  rusMap_["ы"] = "y";
  rusMap_["ь"] = "'";
  rusMap_["э"] = "ė";
  rusMap_["ю"] = "i͡u";
  rusMap_["я"] = "i͡a";
  SetEngMap();
  SetUppercase();
  transliterationRusMethod_.push_back(rusMap_);
}

void transliteration_methods::PrikazMVD782(){
  rusMap_.clear();
  SetStandartSymbols();
  rusMap_["е"] = "e";
  rusMap_["ё"] = "e";
  rusMap_["ж"] = "zh";
  rusMap_["и"] = "i";
  rusMap_["й"] = "y";
  rusMap_["х"] = "kh";
  rusMap_["ц"] = "ts";
  rusMap_["ч"] = "ch";
  rusMap_["ш"] = "sh";
  rusMap_["щ"] = "shch";
  rusMap_["ъ"] = "'";
  rusMap_["ы"] = "y";
  rusMap_["ь"] = "'";
  rusMap_["э"] = "e";
  rusMap_["ю"] = "yu";
  rusMap_["я"] = "ya";
  SetEngMap();
  SetUppercase();
  transliterationRusMethod_.push_back(rusMap_);
}

void transliteration_methods::PrikazMVD995(){
  rusMap_.clear();
  SetStandartSymbols();
  rusMap_["е"] = "e";
  rusMap_["ё"] = "e";
  rusMap_["ж"] = "zh";
  rusMap_["и"] = "i";
  rusMap_["й"] = "i";
  rusMap_["х"] = "kh";
  rusMap_["ц"] = "ts";
  rusMap_["ч"] = "ch";
  rusMap_["ш"] = "sh";
  rusMap_["щ"] = "shch";
  rusMap_["ъ"] = "ie";
  rusMap_["ы"] = "y";
  rusMap_["ь"] = "'";
  rusMap_["э"] = "e";
  rusMap_["ю"] = "iu";
  rusMap_["я"] = "ia";
  SetEngMap();
  SetUppercase();
  transliterationRusMethod_.push_back(rusMap_);
}

void transliteration_methods::PrikazMVD310(){
  rusMap_.clear();
  SetStandartSymbols();
  rusMap_["е"] = "e";
  rusMap_["ё"] = "e";
  rusMap_["ж"] = "zh";
  rusMap_["и"] = "i";
  rusMap_["й"] = "y";
  rusMap_["х"] = "kh";
  rusMap_["ц"] = "ts";
  rusMap_["ч"] = "ch";
  rusMap_["ш"] = "sh";
  rusMap_["щ"] = "shch";
  rusMap_["ъ"] = "\"";
  rusMap_["ы"] = "y";
  rusMap_["ь"] = "'";
  rusMap_["э"] = "e";
  rusMap_["ю"] = "yu";
  rusMap_["я"] = "ya";
  SetEngMap();
  SetUppercase();
  transliterationRusMethod_.push_back(rusMap_);
}

void transliteration_methods::GOST525351(){
  rusMap_.clear();
  SetStandartSymbols();
  rusMap_["е"] = "e";
  rusMap_["ё"] = "e";
  rusMap_["ж"] = "zh";
  rusMap_["и"] = "i";
  rusMap_["й"] = "i";
  rusMap_["х"] = "kh";
  rusMap_["ц"] = "tc";
  rusMap_["ч"] = "ch";
  rusMap_["ш"] = "sh";
  rusMap_["щ"] = "shch";
  rusMap_["ъ"] = "'";
  rusMap_["ы"] = "y";
  rusMap_["ь"] = "'";
  rusMap_["э"] = "e";
  rusMap_["ю"] = "iu";
  rusMap_["я"] = "ia";
  SetEngMap();
  SetUppercase();
  transliterationRusMethod_.push_back(rusMap_);
}

void transliteration_methods::StandartIKAO(){
  rusMap_.clear();
  SetStandartSymbols();
  rusMap_["е"] = "e";
  rusMap_["ё"] = "e";
  rusMap_["ж"] = "zh";
  rusMap_["и"] = "i";
  rusMap_["й"] = "i";
  rusMap_["х"] = "kh";
  rusMap_["ц"] = "ts";
  rusMap_["ч"] = "ch";
  rusMap_["ш"] = "sh";
  rusMap_["щ"] = "shch";
  rusMap_["ъ"] = "ie";
  rusMap_["ы"] = "y";
  rusMap_["ь"] = "'";
  rusMap_["э"] = "e";
  rusMap_["ю"] = "iu";
  rusMap_["я"] = "ia";
  SetEngMap();
  SetUppercase();
  transliterationRusMethod_.push_back(rusMap_);
}

void transliteration_methods::PrikazMID4271(){
  rusMap_.clear();
  SetStandartSymbols();
  rusMap_["е"] = "e";
  rusMap_["ё"] = "e";
  rusMap_["ж"] = "zh";
  rusMap_["и"] = "i";
  rusMap_["й"] = "i";
  rusMap_["х"] = "kh";
  rusMap_["ц"] = "ts";
  rusMap_["ч"] = "ch";
  rusMap_["ш"] = "sh";
  rusMap_["щ"] = "shch";
  rusMap_["ъ"] = "ie";
  rusMap_["ы"] = "y";
  rusMap_["ь"] = "'";
  rusMap_["э"] = "e";
  rusMap_["ю"] = "iu";
  rusMap_["я"] = "ia";
  SetEngMap();
  SetUppercase();
  transliterationRusMethod_.push_back(rusMap_);
}

void transliteration_methods::MezhdynarodnyeTellegramy(){
  rusMap_.clear();
  SetStandartSymbols();
  rusMap_["е"] = "e";
  rusMap_["ё"] = "e";
  rusMap_["ж"] = "j";
  rusMap_["и"] = "i";
  rusMap_["й"] = "i";
  rusMap_["х"] = "h";
  rusMap_["ц"] = "c";
  rusMap_["ч"] = "ch";
  rusMap_["ш"] = "sh";
  rusMap_["щ"] = "sc";
  rusMap_["ъ"] = "'";
  rusMap_["ы"] = "y";
  rusMap_["ь"] = "'";
  rusMap_["э"] = "e";
  rusMap_["ю"] = "iu";
  rusMap_["я"] = "ia";
  SetEngMap();
  SetUppercase();
  transliterationRusMethod_.push_back(rusMap_);
}

void transliteration_methods::SetStandartSymbols(){
  rusMap_["а"] = "a";
  rusMap_["б"] = "b";
  rusMap_["в"] = "v";
  rusMap_["г"] = "g";
  rusMap_["д"] = "d";
  rusMap_["з"] = "z";
  rusMap_["к"] = "k";
  rusMap_["л"] = "l";
  rusMap_["м"] = "m";
  rusMap_["н"] = "n";
  rusMap_["о"] = "o";
  rusMap_["п"] = "p";
  rusMap_["р"] = "r";
  rusMap_["с"] = "s";
  rusMap_["т"] = "t";
  rusMap_["у"] = "u";
  rusMap_["ф"] = "f";
  rusMap_["0"] = "0";
  rusMap_["1"] = "1";
  rusMap_["2"] = "2";
  rusMap_["3"] = "3";
  rusMap_["4"] = "4";
  rusMap_["5"] = "5";
  rusMap_["6"] = "6";
  rusMap_["7"] = "7";
  rusMap_["8"] = "8";
  rusMap_["9"] = "9";
  rusMap_[" "] = " ";
  rusMap_["\n"] = "\n";
}

void transliteration_methods::SetUppercase(){
  rusMap_["А"] = rusMap_["a"];
  rusMap_["Б"] = rusMap_["б"];
  rusMap_["В"] = rusMap_["в"];
  rusMap_["Г"] = rusMap_["г"];
  rusMap_["Д"] = rusMap_["д"];
  rusMap_["Е"] = rusMap_["е"];
  rusMap_["Ё"] = rusMap_["ё"];
  rusMap_["Ж"] = rusMap_["ж"];
  rusMap_["З"] = rusMap_["з"];
  rusMap_["И"] = rusMap_["и"];
  rusMap_["Й"] = rusMap_["й"];
  rusMap_["К"] = rusMap_["к"];
  rusMap_["Л"] = rusMap_["л"];
  rusMap_["М"] = rusMap_["м"];
  rusMap_["Н"] = rusMap_["н"];
  rusMap_["О"] = rusMap_["о"];
  rusMap_["П"] = rusMap_["п"];
  rusMap_["Р"] = rusMap_["р"];
  rusMap_["С"] = rusMap_["с"];
  rusMap_["Т"] = rusMap_["т"];
  rusMap_["У"] = rusMap_["у"];
  rusMap_["Ф"] = rusMap_["ф"];
  rusMap_["Х"] = rusMap_["х"];
  rusMap_["Ц"] = rusMap_["ц"];
  rusMap_["Ч"] = rusMap_["ч"];
  rusMap_["Ш"] = rusMap_["ш"];
  rusMap_["Щ"] = rusMap_["щ"];
  rusMap_["Ъ"] = rusMap_["ъ"];
  rusMap_["Ы"] = rusMap_["ы"];
  rusMap_["Ь"] = rusMap_["ь"];
  rusMap_["Э"] = rusMap_["э"];
  rusMap_["Ю"] = rusMap_["ю"];
  rusMap_["Я"] = rusMap_["я"];
  rusMap_[" "] = rusMap_[" "];
}

void transliteration_methods::SetEngMap(){
  engMap_.clear();
  foreach (QString key, rusMap_.keys()){
    engMap_[rusMap_.value(key)] = key;
  }
  transliterationEngMethod_.push_back(engMap_);
}

QMap<QString, QString> transliteration_methods::GetRusMap(int aMethodNumber){
  return transliterationRusMethod_[aMethodNumber];
}

QMap<QString, QString> transliteration_methods::GetEngMap(int aMethodNumber){
  return transliterationEngMethod_[aMethodNumber];
}
