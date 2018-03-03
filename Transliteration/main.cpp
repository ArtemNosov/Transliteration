#include "transliteration.h"
#include <QApplication>
#include <QTextCodec>
#include <QDebug>

#define TAP_COMPILE
#include "libtap\cpp_tap.h"

int main(int argc, char *argv[]){
  QApplication a(argc, argv);
  transliteration w;
  w.show();
  //
  plan_tests(9);
  // Общая проверка работоспособности программы.
  ok (w.TestFunction(false, true, 7, "шипящий") == "shipi͡ashchiĭ", "Result of test number 1.");
  ok (w.TestFunction(false, true, 0, "плывет акула") == "plyvet akula", "Result of test number 2.");
  ok (w.TestFunction(false, false, 3, "bel'e na suške") == "белье на сушке", "Result of test number 3.");
  // Проверка на выявление некорректного текста.
  ok (w.TestFunction(false, true, 6, "я сказал hello") == "", "Result of test number 4.");
  ok (w.TestFunction(false, false, 6, "я сказал hello") == "", "Result of test number 5.");
  // Проверка работоспособности словаря.
  ok (w.TestFunction(true, true, 3, "здесь шумно") == "zdes′ šumno", "Result of test number 6.");
  ok (w.TestFunction(true, true, 5, "здесь шумно") == "zdes′ šumno", "Result of test number 7.");
  ok (w.TestFunction(true, true, 10, "здесь шумно") == "zdes′ šumno", "Result of test number 8.");
  ok (w.TestFunction(true, true, 14, "здесь шумно") == "zdes′ šumno", "Result of test number 9.");
  //
  return exit_status();
  return a.exec();
}
