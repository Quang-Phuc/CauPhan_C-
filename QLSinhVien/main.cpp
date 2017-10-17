#include "quanlysinhvien.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QuanLySinhVien w;
    w.show();

    return a.exec();
}
