#include "transliteration.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Transliteration w;
    w.show();

    return a.exec();
}
