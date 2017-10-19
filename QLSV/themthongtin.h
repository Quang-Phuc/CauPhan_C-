#ifndef THEMTHONGTIN_H
#define THEMTHONGTIN_H

#include <QDialog>
#include "khoacntt.h"

namespace Ui {
class themthongtin;
}

class themthongtin : public QDialog
{
    Q_OBJECT

public:

    explicit themthongtin(QWidget *parent = 0);
    ~themthongtin();

private slots:
    void on_buttonBox_accepted();

    void on_pushButton_clicked();

private:
    Ui::themthongtin *ui;
};

#endif // THEMTHONGTIN_H
