#ifndef STUDENTDIALOG_H
#define STUDENTDIALOG_H

#include <QDialog>

namespace Ui {
class StudentDialog;
}

class StudentDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StudentDialog(QWidget *parent = 0);
    ~StudentDialog();

private:
    Ui::StudentDialog *ui;
};

#endif // STUDENTDIALOG_H
