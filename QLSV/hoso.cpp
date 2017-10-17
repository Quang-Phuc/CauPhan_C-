#include "hoso.h"
#include "ui_hoso.h"

hoso::hoso(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::hoso)
{
    ui->setupUi(this);
}

hoso::~hoso()
{
    delete ui;
}
