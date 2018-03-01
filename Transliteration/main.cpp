#include "transliteration.h"
#include <QApplication>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    //QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf-16"));

    QApplication a(argc, argv);
    Transliteration w;
    w.show();

    return a.exec();
}
