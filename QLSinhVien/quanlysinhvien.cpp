#include "quanlysinhvien.h"
#include "ui_quanlysinhvien.h"

QuanLySinhVien::QuanLySinhVien(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QuanLySinhVien)
{
    ui->setupUi(this);
}

QuanLySinhVien::~QuanLySinhVien()
{
    delete ui;
}
