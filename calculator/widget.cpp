#include <QString>
#include <QDebug>

#include "widget.h"
#include "ui_widget.h"
#include "calculate.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("计算器");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_num0_clicked()
{
    expression = ui->lineEdit->text();
    expression += "0";
    ui->lineEdit->setText(expression);
}


void Widget::on_num1_clicked()
{
    expression = ui->lineEdit->text();
    expression += "1";
    ui->lineEdit->setText(expression);
}


void Widget::on_num2_clicked()
{
    expression = ui->lineEdit->text();
    expression += "2";
    ui->lineEdit->setText(expression);
}


void Widget::on_num3_clicked()
{
    expression = ui->lineEdit->text();
    expression += "3";
    ui->lineEdit->setText(expression);
}


void Widget::on_num4_clicked()
{
    expression = ui->lineEdit->text();
    expression += "4";
    ui->lineEdit->setText(expression);
}


void Widget::on_num5_clicked()
{
    expression = ui->lineEdit->text();
    expression += "5";
    ui->lineEdit->setText(expression);
}


void Widget::on_num6_clicked()
{
    expression = ui->lineEdit->text();
    expression += "6";
    ui->lineEdit->setText(expression);
}


void Widget::on_num7_clicked()
{
    expression = ui->lineEdit->text();
    expression += "7";
    ui->lineEdit->setText(expression);
}


void Widget::on_num8_clicked()
{
    expression = ui->lineEdit->text();
    expression += "8";
    ui->lineEdit->setText(expression);
}


void Widget::on_num9_clicked()
{
    expression = ui->lineEdit->text();
    expression += "9";
    ui->lineEdit->setText(expression);
}


void Widget::on_leftParen_clicked()
{
    expression = ui->lineEdit->text();
    expression += "(";
    ui->lineEdit->setText(expression);
}


void Widget::on_rightParen_clicked()
{
    expression = ui->lineEdit->text();
    expression += ")";
    ui->lineEdit->setText(expression);
}


void Widget::on_div_clicked()
{
    expression = ui->lineEdit->text();
    expression += "/";
    ui->lineEdit->setText(expression);
}


void Widget::on_mul_clicked()
{
    expression = ui->lineEdit->text();
    expression += "*";
    ui->lineEdit->setText(expression);
}


void Widget::on_sub_clicked()
{
    expression = ui->lineEdit->text();
    expression += "-";
    ui->lineEdit->setText(expression);
}


void Widget::on_add_clicked()
{
    expression = ui->lineEdit->text();
    expression += "+";
    ui->lineEdit->setText(expression);
}


void Widget::on_clear_clicked()
{
    expression.clear();
    ui->lineEdit->setText(expression);
}


void Widget::on_del_clicked()
{
    expression = ui->lineEdit->text();
    expression.chop(1);
    ui->lineEdit->setText(expression);
}


void Widget::on_pushButton_eq_clicked()
{
    expression = ui->lineEdit->text();
    ui->lineEdit->setText(QString::number(Calculator::calculate(expression)));
}
