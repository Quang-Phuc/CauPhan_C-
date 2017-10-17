#include "menudialog.h"
#include "ui_menudialog.h"
#include "quanlythongtin.h"
#include"quanlyketquahoctap.h"
#include"quanlylophoc.h"
#include "hoso.h"

menuDialog::menuDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menuDialog)
{
    ui->setupUi(this);
}

menuDialog::~menuDialog()
{
    delete ui;
}

void menuDialog::on_trangchu_clicked()
{

}

void menuDialog::on_quanlythongtin_clicked()
{
  //  menuDialog menudialog;
    //menudialog.setModal(true);
    //menudialog.exec();
    quanlythongtin qlthongtin;
    qlthongtin.setModal(true);
    qlthongtin.exec();
}

void menuDialog::on_quanlyketquahoctap_clicked()
{
    quanlyketquahoctap qlketquahoctap;
    qlketquahoctap.setModal(true);
    qlketquahoctap.exec();
}

void menuDialog::on_quanlythongtinlophoc_clicked()
{
   quanlylophoc qllophoc;
   qllophoc.setModal(true);
   qllophoc.exec();
}

void menuDialog::on_hoso_clicked()
{
    hoso qlhoso;
    qlhoso.setModal(true);
    qlhoso.exec();
}
