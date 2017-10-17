#include "qlsv.h"
#include "ui_qlsv.h"

QLSV::QLSV(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QLSV)
{
    ui->setupUi(this);
}

QLSV::~QLSV()
{
    delete ui;
}
