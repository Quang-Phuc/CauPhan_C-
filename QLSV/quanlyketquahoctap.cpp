#include "quanlyketquahoctap.h"
#include "ui_quanlyketquahoctap.h"

quanlyketquahoctap::quanlyketquahoctap(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::quanlyketquahoctap)
{
    ui->setupUi(this);
}

quanlyketquahoctap::~quanlyketquahoctap()
{
    delete ui;
}
