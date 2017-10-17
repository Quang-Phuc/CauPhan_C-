#ifndef QUANLYTHONGTIN_H
#define QUANLYTHONGTIN_H

#include <QDialog>

namespace Ui {
class quanlythongtin;
}

class quanlythongtin : public QDialog
{
    Q_OBJECT

public:
    explicit quanlythongtin(QWidget *parent = 0);
    ~quanlythongtin();

private:
    Ui::quanlythongtin *ui;
};

#endif // QUANLYTHONGTIN_H
