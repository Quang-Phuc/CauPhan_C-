#include "quanlyketquahoctap.h"
#include "ui_quanlyketquahoctap.h"
#include "khoacntt.h"
#include <QMessageBox>

quanlyketquahoctap::quanlyketquahoctap(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::quanlyketquahoctap)
{
    ui->setupUi(this);
}

quanlyketquahoctap::~quanlyketquahoctap()
{
    delete ui;
}

void quanlyketquahoctap::on_pushButton_clicked()
{

    KhoaCNTT conn;
   QString Masv, Mamon,Tenmon,D1,D2,D3,Dt;
  // Masv=ui->masv->text();
   Mamon=ui->mamon->text();
   Tenmon=ui->tenmon->text();
   D1=ui->diem1->text();
   D2=ui->diem2->text();
   D3=ui->diem3->text();
   Dt=ui->diemthi->text();

   if(!conn.connOpen())
   {
       qDebug()<<"Failed to open the database";
       return;



   }

   conn.connOpen();
   QSqlQuery qry;
   if(Mamon==""||Tenmon=="")
   {
       QMessageBox::information(this,tr("Thông báo"),tr("Khong duoc de trong"));
   }
   else
   {
   qry.prepare("insert into QLketquahoctap (Masv,Mamon,Tenmon,D1,D2,D3,Dt) values ('"+Masv+"','"+Mamon+"','"+Tenmon+"','"+D1+"','"+D2+"','"+D3+"','"+Dt+"')");
    }
   if(qry.exec( ))
   {

      QMessageBox::information(this,tr("Thông báo"),tr("Thêm thông tin thành công"));
      conn.connClose();

   }
   else
   {
        QMessageBox::information(this,tr("Lỗi "),qry.lastError().text());
   }


}

void quanlyketquahoctap::on_pushButton_2_clicked()
{

    KhoaCNTT conn;
   QString Masv, Mamon,Tenmon,D1,D2,D3,Dt;
   //Masv=ui->masv->text();
   Mamon=ui->mamon->text();
   Tenmon=ui->tenmon->text();
   D1=ui->diem1->text();
   D2=ui->diem2->text();
   D3=ui->diem3->text();
   Dt=ui->diemthi->text();

   if(!conn.connOpen())
   {
       qDebug()<<"Failed to open the database";
       return;



   }

   conn.connOpen();
   QSqlQuery qry;
   if(Mamon==""||Tenmon=="")
   {
       QMessageBox::information(this,tr("Thông báo"),tr("Khong duoc de trong"));
   }
   else
   {
   qry.prepare("update QLketquahoctap set Masv='"+Masv+"',Mamon='"+Mamon+"',Tenmon='"+Tenmon+"',D1='"+D1+"',D2='"+D2+"',D3='"+D3+"',Dt='"+Dt+"' where Mamon='"+Mamon+"' ");
   }
   if(qry.exec( ))
   {
      QMessageBox::information(this,tr("Thông báo"),tr("Bạn đã sửa thông tin thành công"));
      conn.connClose();

   }
   else
   {
        QMessageBox::information(this,tr("Lỗi "),qry.lastError().text());
   }


}

void quanlyketquahoctap::on_pushButton_3_clicked()
{
    KhoaCNTT conn;
   QString Masv, Mamon,Tenmon,D1,D2,D3,Dt;
  // Masv=ui->masv->text();
   Mamon=ui->mamon->text();
  // Tenmon=ui->tenmon->text();
  // D1=ui->diem1->text();
  // D2=ui->diem2->text();
  // D3=ui->diem3->text();
 //  Dt=ui->diemthi->text();

   if(!conn.connOpen())
   {
       qDebug()<<"Failed to open the database";
       return;



   }

   conn.connOpen();
   QSqlQuery qry;




   qry.prepare("Delete from QLketquahoctap  where Mamon='"+Mamon+"' ");

   if(qry.exec( ))
   {
      QMessageBox::information(this,tr("Thông báo"),tr("Bạn đã xóa thông tin thành công"));
      conn.connClose();

   }
   else
   {
        QMessageBox::information(this,tr("Lỗi "),qry.lastError().text());
   }

}

void quanlyketquahoctap::on_pushButton_4_clicked()
{
    KhoaCNTT conn;
    QSqlQueryModel * modal= new QSqlQueryModel();
     QSqlQueryModel * modal2= new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery* qry= new QSqlQuery(conn.mydb);
    QSqlQuery* qry2= new QSqlQuery(conn.mydb);
    qry->prepare("select * from QLketquahoctap");
     qry2->prepare("select Masv from QLthongtin");
    qry->exec();
    qry2->exec();
    modal->setQuery(*qry);
    modal2->setQuery(*qry2);
    ui->masv->setModel(modal2);
    ui->tableView->setModel(modal);
    conn.connClose();
    qDebug()<<(modal->rowCount());
    qDebug()<<(modal2->rowCount());
}
