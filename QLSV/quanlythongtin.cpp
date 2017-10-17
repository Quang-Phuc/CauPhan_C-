#include "quanlythongtin.h"
#include "ui_quanlythongtin.h"

quanlythongtin::quanlythongtin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::quanlythongtin)
{
    ui->setupUi(this);
}

quanlythongtin::~quanlythongtin()
{
    delete ui;
}
