#include "menudialog.h"


MenuDialog::MenuDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MenuDialog)
{
    ui->setupUi(this);
}

MenuDialog::~MenuDialog()
{
    delete ui;
}
