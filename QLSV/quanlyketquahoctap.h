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

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::quanlyketquahoctap *ui;
};

#endif // QUANLYKETQUAHOCTAP_H
