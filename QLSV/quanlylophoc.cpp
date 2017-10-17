#include "quanlylophoc.h"
#include "ui_quanlylophoc.h"

quanlylophoc::quanlylophoc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::quanlylophoc)
{
    ui->setupUi(this);
}

quanlylophoc::~quanlylophoc()
{
    delete ui;
}
