#ifndef HOSO_H
#define HOSO_H

#include <QDialog>

namespace Ui {
class hoso;
}

class hoso : public QDialog
{
    Q_OBJECT

public:
    explicit hoso(QWidget *parent = 0);
    ~hoso();

private:
    Ui::hoso *ui;
};

#endif // HOSO_H
