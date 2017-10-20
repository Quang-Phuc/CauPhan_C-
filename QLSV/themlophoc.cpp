#include "themlophoc.h"
#include "ui_themlophoc.h"
#include "khoacntt.h"
#include <QMessageBox>

themlophoc::themlophoc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::themlophoc)
{
    ui->setupUi(this);
    KhoaCNTT conn;
   if(!conn.connOpen())
       ui->tinhtrang->setText("Faile to open the database");
   else
       ui->tinhtrang->setText("Connetcted...");
}

themlophoc::~themlophoc()
{
    delete ui;
}

void themlophoc::on_pushButton_clicked()
{
    KhoaCNTT conn;
   QString Malop, Tenlop,Soluongsv,Mota;
   Malop=ui->malop->text();
   Tenlop=ui->tenlop->text();
   Soluongsv=ui->soluong->text();
   Mota=ui->mota->text();

   if(!conn.connOpen())
   {
       qDebug()<<"Failed to open the database";
       return;



   }

   conn.connOpen();
   QSqlQuery qry;
   if(Malop==""||Tenlop==""||Soluongsv=="")
   {
       QMessageBox::information(this,tr("Thông báo"),tr("Khong duoc de trong"));
   }
   else
   {
   qry.prepare("insert into QLlophoc (Malop,Tenlop,Soluongsv,Mota) values ('"+Malop+"','"+Tenlop+"','"+Soluongsv+"','"+Mota+"')");
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

void themlophoc::on_pushButton_3_clicked()
{
    KhoaCNTT conn;
   QString Malop, Tenlop,Soluongsv,Mota;
   Malop=ui->malop->text();
   Tenlop=ui->tenlop->text();
   Soluongsv=ui->soluong->text();
   Mota=ui->mota->text();

   if(!conn.connOpen())
   {
       qDebug()<<"Failed to open the database";
       return;



   }

   conn.connOpen();
   QSqlQuery qry;
   if(Malop==""||Tenlop==""||Soluongsv=="")
   {
       QMessageBox::information(this,tr("Thông báo"),tr("Khong duoc de trong"));
   }
   else
   {
   qry.prepare("update QLlophoc set Malop='"+Malop+"',Tenlop='"+Tenlop+"',Soluongsv='"+Soluongsv+"',Mota='"+Mota+"' where Malop='"+Malop+"' ");
    }
   if(qry.exec( ))
   {

      QMessageBox::information(this,tr("Thông báo"),tr("sửa thành công thông tin thành công"));
      conn.connClose();

   }
   else
   {
        QMessageBox::information(this,tr("Lỗi "),qry.lastError().text());
   }

}

void themlophoc::on_pushButton_2_clicked()
{
    KhoaCNTT conn;
   QString Malop, Tenlop,Soluongsv,Mota;
   Malop=ui->malop->text();
  // Tenlop=ui->tenlop->text();
  // Soluongsv=ui->soluong->text();
  // Mota=ui->mota->text();

   if(!conn.connOpen())
   {
       qDebug()<<"Failed to open the database";
       return;



   }

   conn.connOpen();
   QSqlQuery qry;


   qry.prepare("Delete from QLlophoc  where Malop='"+Malop+"'");

   if(qry.exec( ))
   {

      QMessageBox::information(this,tr("Thông báo"),tr("xóa thành công thông tin thành công"));
      conn.connClose();

   }
   else
   {
        QMessageBox::information(this,tr("Lỗi "),qry.lastError().text());
   }

}

void themlophoc::on_pushButton_4_clicked()
{
    KhoaCNTT conn;
    QSqlQueryModel * modal= new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery* qry= new QSqlQuery(conn.mydb);
    qry->prepare("select * from QLlophoc");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    conn.connClose();
    qDebug()<<(modal->rowCount());
}
