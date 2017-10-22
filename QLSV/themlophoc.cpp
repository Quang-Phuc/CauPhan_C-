#include "themlophoc.h"
#include "ui_themlophoc.h"
#include "khoacntt.h"
#include <QMessageBox>
#include <QFile>
#include <QString>

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

void themlophoc::on_pushButton_5_clicked()
{
   /* KhoaCNTT conn;
    QSqlQueryModel * modal= new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery* qry= new QSqlQuery(conn.mydb);
    qry->prepare("Bulk insert from 'file.txt' with(FIELDTERMINATOR='-' ROWTERMINATOR='\n')");
    qry->exec();
    modal->setQuery(*qry);
   // ui->tableView->setModel(modal);
    conn.connClose();
    qDebug()<<(modal->rowCount());
*/

   // QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
   //    db.setDatabaseName("/home/aj/testdatabase.db");

     /*  QString querystr;
      querystr=QString(".separator ","");
       querystr=QString(".separator ","");
       QSqlQuery query(querystr,mydb);
       if(query.exec())
       {
           qDebug()<<"SUCCESSFULLY QUEIRED ";

           QString querystr2;
           querystr=QString(".import import_table.csv test_table");
       }
       else
       {
           qDebug()<<"ERROR DURING QUERY "<<mydb.lastError().text();
       }*/
  //  import sqlite3
   // import openpyxl
   // from openpyxl import load_workbook
   /* import re

    def slugify(text, lower=1):
        if lower == 1:
            text = text.strip().lower()
        text = re.sub(r'[^\w _-]+', '', text)
        text = re.sub(r'[- ]+', '_', text)
        return text

    #Replace with a database name
    con = sqlite3.connect('test.db')
    #replace with the complete path to youe excel workbook
    wb = load_workbook(filename=r'abc.xlsx')

    sheets = wb.get_sheet_names()

    for sheet in sheets:
        ws = wb[sheet]

        columns= []
        query = 'CREATE TABLE ' + str(slugify(sheet)) + '(ID INTEGER PRIMARY KEY AUTOINCREMENT'
        for row in ws.rows[0]:
            query += ', ' + slugify(row.value) + ' TEXT'
            columns.append(slugify(row.value))
        query += ');'

        con.execute(query)

        tup = []
        for i, rows in enumerate(ws):
            tuprow = []
            if i == 0:
                continue
            for row in rows:
                tuprow.append(unicode(row.value).strip()) if unicode(row.value).strip() != 'None' else tuprow.append('')
            tup.append(tuple(tuprow))


        insQuery1 = 'INSERT INTO ' + str(slugify(sheet)) + '('
        insQuery2 = ''
        for col in columns:
            insQuery1 += col + ', '
            insQuery2 += '?, '
        insQuery1 = insQuery1[:-2] + ') VALUES('
        insQuery2 = insQuery2[:-2] + ')'
        insQuery = insQuery1 + insQuery2

        con.executemany(insQuery, tup)
        con.commit()

    con.close()
    */


}

