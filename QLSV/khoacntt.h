#ifndef KHOACNTT_H
#define KHOACNTT_H

#include <QMainWindow>
#include<QtSql>
#include<QtDebug>
#include<QFileInfo>

namespace Ui {
class KhoaCNTT;
}

class KhoaCNTT : public QWidget
{
    Q_OBJECT

public:
    explicit KhoaCNTT(QWidget *parent = 0);
    ~KhoaCNTT();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::KhoaCNTT *ui;
    QSqlDatabase mydb;
};

#endif // KHOACNTT_H
