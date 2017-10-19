#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
     mydb=QSqlDatabase ::addDatabase("QSQLITE");
    mydb.setDatabaseName("E:/Cau_Phan/Quanlysinhvien.sqlite");
    if(!mydb.open())
        ui->label->setText("Faile to open the database");
    else
        ui->label->setText("Connetcted...");



}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
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
            ui->label->setText("Taikhoan va mat khau is contect");

        if(count>1)
            ui->label->setText("Duplicate Taikhoan va mat khau");

        if(count<1)
            ui->label->setText("Taikhoan va mat khau is no contect");

    }
}
