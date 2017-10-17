#ifndef QUANLYSINHVIEN_H
#define QUANLYSINHVIEN_H

#include <QMainWindow>

namespace Ui {
class QuanLySinhVien;
}

class QuanLySinhVien : public QMainWindow
{
    Q_OBJECT

public:
    explicit QuanLySinhVien(QWidget *parent = 0);
    ~QuanLySinhVien();

private:
    Ui::QuanLySinhVien *ui;
};

#endif // QUANLYSINHVIEN_H
