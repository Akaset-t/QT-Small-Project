#include <chrono>
#include <QPixmap>
#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent), ui(new Ui::Widget)
    , picId(1)
{
    ui->setupUi(this);
    QPixmap pix("D:\\Code\\C\\QT\\QObjectTimer\\img\\1.png");
    ui->label->setPixmap(pix);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::timerEvent(QTimerEvent *event) {
    if (event-> timerId() != timerId) {
        return;
    }
    QString basePath = "D:\\Code\\C\\QT\\QObjectTimer\\img\\";
    QString picturePath = basePath + QString::number((picId++ % 5) + 1) + ".png";
    QPixmap pix(picturePath);
    ui->label->setPixmap(pix);
}

void Widget::on_startbutton_clicked() {
    std::chrono::milliseconds timeout = std::chrono::milliseconds(1000);
    timerId = this->startTimer(timeout);
}


void Widget::on_stopButton_clicked() {
    this->killTimer(timerId);
}

