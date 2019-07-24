#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    changeMoney(0);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::returnMoney(){
    int cnt[4] = {0};
    cnt[0] = mon / 500;
    mon %= 500;
    cnt[1] = mon / 100;
    mon %= 100;
    cnt[2] = mon / 50;
    mon %= 50;
    cnt[3] = mon / 10;
    mon %= 10;

    QMessageBox msg;
    msg.information(nullptr,"Return", "Returned\n500 * " + QString::number(cnt[0]) + "\n"
            +"100 * "+QString::number(cnt[1]) + "\n"
            +"50 * "+QString::number(cnt[2]) + "\n"
            +"10 * "+QString::number(cnt[3]) + "\n"
            );
    ui->money->display(QString::number(mon));
    changeMoney(0);


}


void Widget::changeMoney(int n){
    mon += n;
    if(mon < 100){
        ui->pbCoffee->setEnabled(false);
        ui->pbTea->setEnabled(false);
        ui->pbIcetea->setEnabled(false);
    }else if(mon < 150){
        ui->pbCoffee->setEnabled(true);
        ui->pbTea->setEnabled(false);
        ui->pbIcetea->setEnabled(false);
    }else if(mon < 200){
        ui->pbCoffee->setEnabled(true);
        ui->pbTea->setEnabled(true);
        ui->pbIcetea->setEnabled(false);
    }else{
        ui->pbCoffee->setEnabled(true);
        ui->pbTea->setEnabled(true);
        ui->pbIcetea->setEnabled(true);
    }



    if(n > 0){
        QMessageBox msg;
        msg.information(nullptr,"Money Inserted", "Inserted " + QString::number(n));
        ui->money->display(QString::number(mon));
    }else if(n<0){
        QMessageBox msg;
        msg.information(nullptr,"Payment Done", "Used " + QString::number(-1*n));
        ui->money->display(QString::number(mon));
    }

}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
}

void Widget::on_pb50_clicked()
{
    changeMoney(50);
}

void Widget::on_pb100_clicked()
{

    changeMoney(100);
}

void Widget::on_pb500_clicked()
{
    changeMoney(500);
}


void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}

void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}

void Widget::on_pbIcetea_clicked()
{
    changeMoney(-200);
}

void Widget::on_pbreturn_clicked()
{
    returnMoney();
}
