#include "themthongtin.h"
#include "ui_themthongtin.h"
#include "khoacntt.h"
#include <QMessageBox>
#include <stdio.h>
#include <iostream>
#include <conio.h>


themthongtin::themthongtin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::themthongtin)
{
    ui->setupUi(this);
     KhoaCNTT conn;
    if(!conn.connOpen())
        ui->tinhtrang->setText("Faile to open the database");
    else
        ui->tinhtrang->setText("Connetcted...");

}

themthongtin::~themthongtin()
{
    delete ui;
}

void themthongtin::on_buttonBox_accepted()
{

}

void themthongtin::on_pushButton_clicked()
{
     KhoaCNTT conn;
    QString Masv, Tensv,Ngaysinh,Giotinh,SDT,Email,Diachi;
    Masv=ui->masv->text();
    Tensv=ui->tensv->text();
    Ngaysinh=ui->ngaysinh->text();
    Giotinh=ui->gioitinh->text();
    SDT=ui->sdt->text();
    Email=ui->email->text();
    Diachi=ui->diachi->text();
    if(!conn.connOpen())
    {
        qDebug()<<"Failed to open the database";
        return;



    }

    conn.connOpen();
    QSqlQuery qry;




    if(Masv==""||Tensv==""||Ngaysinh==""||Diachi=="")
    {
        QMessageBox::information(this,tr("Thông báo"),tr("Khong duoc de trong"));

    }
    else
    {
    qry.prepare("insert into QLthongtin (Masv,Tensv,Ngaysinh,Gioitinh,SDT,Email,Diachi) values ('"+Masv+"','"+Tensv+"','"+Ngaysinh+"','"+Giotinh+"','"+SDT+"','"+Email+"','"+Diachi+"')");
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

void themthongtin::on_pushButton_2_clicked()
{
    KhoaCNTT conn;
   QString Masv, Tensv,Ngaysinh,Giotinh,SDT,Email,Diachi;
   Masv=ui->masv->text();
   Tensv=ui->tensv->text();
   Ngaysinh=ui->ngaysinh->text();
   Giotinh=ui->gioitinh->text();
   SDT=ui->sdt->text();
   Email=ui->email->text();
   Diachi=ui->diachi->text();
   if(!conn.connOpen())
   {
       qDebug()<<"Failed to open the database";
       return;



   }

   conn.connOpen();
   QSqlQuery qry;




   if(Masv==""||Tensv==""||Ngaysinh==""||Diachi=="")
   {
       QMessageBox::information(this,tr("Thông báo"),tr("Khong duoc de trong"));

   }
   else
   {
   qry.prepare("update QLthongtin set Masv='"+Masv+"',Tensv='"+Tensv+"',Ngaysinh='"+Ngaysinh+"',Gioitinh='"+Giotinh+"',SDT='"+SDT+"',Email='"+Email+"',Diachi='"+Diachi+"' where Masv='"+Masv+"' ");
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

void themthongtin::on_pushButton_3_clicked()
{
    KhoaCNTT conn;
   QString Masv, Tensv,Ngaysinh,Giotinh,SDT,Email,Diachi;
   Masv=ui->masv->text();
  // Tensv=ui->tensv->text();
   //Ngaysinh=ui->ngaysinh->text();
   //Giotinh=ui->gioitinh->text();
  // SDT=ui->sdt->text();
  // Email=ui->email->text();
  // Diachi=ui->diachi->text();
   if(!conn.connOpen())
   {
       qDebug()<<"Failed to open the database";
       return;



   }

   conn.connOpen();
   QSqlQuery qry;





   qry.prepare("Delete from QLthongtin  where Masv='"+Masv+"' ");

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

void themthongtin::on_Load_clicked()
{
    KhoaCNTT conn;
    QSqlQueryModel * modal= new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery* qry= new QSqlQuery(conn.mydb);
    qry->prepare("select * from QLthongtin");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    conn.connClose();
    qDebug()<<(modal->rowCount());
}
