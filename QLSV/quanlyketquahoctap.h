#ifndef QUANLYKETQUAHOCTAP_H
#define QUANLYKETQUAHOCTAP_H

#include <QDialog>

namespace Ui {
class quanlyketquahoctap;
}

class quanlyketquahoctap : public QDialog
{
    Q_OBJECT

public:
    explicit quanlyketquahoctap(QWidget *parent = 0);
    ~quanlyketquahoctap();

private:
    Ui::quanlyketquahoctap *ui;
};

#endif // QUANLYKETQUAHOCTAP_H
