#include "fish.h"
#include "ui_fish.h"
#include "functions.h"
#include "qtimer.h"

int nfish=0;

void delay(int t);
void open();
void close();

void fish::delay(int t)
{
    int i,j;
    system("echo '0' > /sys/class/gpio/gpio11/value");
    system("echo '0' > /sys/class/gpio/gpio15/value");
    while(t--)
    {
        for(i=0;i<200;i++)
            for(j=0;j<200;j++);}
}

void fish::myslot()
{
    qDebug()<<"fish";

}

void fish::open()
{
    system("echo '1' > /sys/class/gpio/gpio11/value");
    system("echo '0' > /sys/class/gpio/gpio15/value");
    qDebug() << "open";
}

void fish::close()
{
    system("echo '0' > /sys/class/gpio/gpio11/value");
    system("echo '1' > /sys/class/gpio/gpio15/value");
   // timer = new QTimer;
//    connect(timer,SIGNAL(timeout()),this,SLOT(close()));
   qDebug() << "close";
}

fish::fish(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::fish)
{
    ui->setupUi(this);
    system("sudo bash");
    system("echo '11' > /sys/class/gpio/export");
    system("echo 'out' > /sys/class/gpio/gpio11/direction");
    system("echo '15' > /sys/class/gpio/export");
    system("echo 'out' > /sys/class/gpio/gpio11/direction");

   //timer->start();
}

fish::~fish()
{
    delete ui;
}

void fish::on_pushButton_clicked()
{
    QString fish = ui->lineEdit->text();

    nfish=fish.toInt();

    if(nfish<5)
    {
       open();
       delay(5000);
       close();
    }
    if(nfish>5 & nfish<10)
    {
       open();
       delay(8000);
       close();
    }
    if(nfish>10 & nfish<15)
    {
       open();
       delay(10000);
       close();
    }
    if(nfish>15 & nfish<20)
    {
       open();
       delay(15000);
       close();
    }
    if(nfish<=0 | nfish>=20 )
    {
        qDebug()<<"either no fish or more than limit fishes";
    }
}
