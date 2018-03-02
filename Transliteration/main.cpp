#include "transliteration.h"
#include <QApplication>
#include <QTextCodec>

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    transliteration w;
    w.show();
    //
    return a.exec();
}
