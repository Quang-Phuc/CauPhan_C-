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

void QuanLySinhVien::on_pushButton_clicked()
{
    QString s="a";
    QString s1="a";
    if(ui->nhapmatkhau->text()==s && ui->nhaptaikhoan->text()==s1)
    {
        ui->thongbao->setText("Ban dang nhap thanh cong");

    }
    else
        ui->thongbao->setText("Tai khoan hoac mat khau khong dung");
}

void QuanLySinhVien::on_pushButton_2_clicked()
{
    close();
}
