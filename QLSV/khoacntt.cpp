#include "khoacntt.h"
#include "ui_khoacntt.h"
#include <QMessageBox>
#include "menudialog.h"
KhoaCNTT::KhoaCNTT(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::KhoaCNTT)
{
    ui->setupUi(this);
     mydb=QSqlDatabase ::addDatabase("QSQLITE");
    mydb.setDatabaseName("E:/Cau_Phan/Quanlysinhvien.sqlite");
    if(!mydb.open())
        ui->thongbao->setText("Faile to open the database");
    else
        ui->thongbao->setText("Connetcted...");

}

KhoaCNTT::~KhoaCNTT()
{
    delete ui;
}

void KhoaCNTT::on_pushButton_2_clicked()
{
    close();
}

void KhoaCNTT::on_pushButton_clicked()
{
    QString TaiKhoan, Matkhau;
    TaiKhoan=ui->taikhoan->text();
    Matkhau=ui->matkhau->text();
    if(!mydb.isOpen())
    {
        qDebug()<<"Failed to open the database";
        return;



    }

    QSqlQuery qry;
    if(qry.exec("select * from Dangnhap where TaiKhoan='"+TaiKhoan +"'and Matkhau='"+Matkhau+"'" ))
    {
        int count=0;
        while(qry.next())
        {
            count++;
        }
        if(count==1)
        {
            ui->thongbao->setText("Dang nhap thanh cong");
            menuDialog menudialog;
            menudialog.setModal(true);
            menudialog.exec();
        }

        if(count>1)
        {ui->label->setText("Duplicate Taikhoan va mat khau");}

        if(count<1)
           {  QMessageBox::information(this,tr("Thông báo"),tr("Bạn đã nhập sai"));}

    }

}
    /*
      // ui->thongbao->setText("Tai khoan hoac mat khau khong chinh xac");
        QMessageBox::information(this,tr("Thông báo"),tr("Bạn đã nhập sai"));
    QSqlQuery qry;
    if(qry.exec("select * from Dangnhap where TaiKhoan='"+TaiKhoan +"'and Matkhau='"+Matkhau+"'" ))
    {

        ui->thongbao->setText("Dang nhap thanh cong");
        menuDialog menudialog;
        menudialog.setModal(true);
        menudialog.exec();
   }
//////
    QString TaiKhoan, Matkhau;
    TaiKhoan=ui->taikhoan->text();
    Matkhau=ui->matkhau->text();
    if(!mydb.isOpen())
    {
        qDebug()<<"Failed to open the database";
        return;



    }
    QSqlQuery qry;
    if(qry.exec("select * from Dangnhap where TaiKhoan='"+TaiKhoan +"'and Matkhau='"+Matkhau+"'" ))
    {
        int count=0;
        while(qry.next())
        {
            count++;
        }
        if(count==1)
            ui->label->setText("Taikhoan va mat khau is contect");

        if(count>1)
            ui->label->setText("Duplicate Taikhoan va mat khau");

        if(count<1)
            ui->label->setText("Taikhoan va mat khau is no contect");


    */

