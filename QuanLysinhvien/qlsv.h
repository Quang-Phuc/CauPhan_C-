#ifndef QLSV_H
#define QLSV_H

#include <QWidget>

namespace Ui {
class QLSV;
}

class QLSV : public QWidget
{
    Q_OBJECT

public:
    explicit QLSV(QWidget *parent = 0);
    ~QLSV();

private:
    Ui::QLSV *ui;
};

#endif // QLSV_H
