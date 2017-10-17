#include "qlsv.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QLSV w;
    w.show();

    return a.exec();
}
