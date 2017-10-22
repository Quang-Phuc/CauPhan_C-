#ifndef THEMLOPHOC_H
#define THEMLOPHOC_H

#include <QDialog>

namespace Ui {
class themlophoc;
}

class themlophoc : public QDialog
{
    Q_OBJECT

public:
    explicit themlophoc(QWidget *parent = 0);
    ~themlophoc();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::themlophoc *ui;
};

#endif // THEMLOPHOC_H
