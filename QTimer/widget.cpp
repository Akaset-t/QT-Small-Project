#include <chrono>
#include <QImage>
#include <QPixmap>
#include <QTimer>
#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent), ui(new Ui::Widget), picId(1)
{
    ui->setupUi(this);
    timer = new QTimer;
    QImage img("D:\\Code\\C\\QT\\QObjectTimer\\img\\1.png");
    ui->label->setPixmap(QPixmap::fromImage(img));

    connect(timer, &QTimer::timeout, this, &Widget::timeoutSlot);
}

Widget::~Widget()
{
    delete ui;
    delete timer;
}

void Widget::on_startbutton_clicked() {
    std::chrono::milliseconds timeout = std::chrono::milliseconds(1000);
    // 每隔一段时间会发出signal
    timer->start(timeout);

    // timrout时间间隔后执行一次槽函数或者函数
    // QTimer::singleShot(timeout, this, &Widget::timeoutSlot);

    // QTimer::singleShot(timeout, [this] {
    //     QString basePath = "D:\\Code\\C\\QT\\QObjectTimer\\img\\";
    //     QString picturePath = basePath + QString::number((picId++ % 5) + 1) + ".png";
    //     QImage img(picturePath);
    //     ui->label->setPixmap(QPixmap::fromImage(img));
    // });
    
}


void Widget::on_stopButton_clicked() {
    timer->stop();
}

void Widget::timeoutSlot() {
    QString basePath = "D:\\Code\\C\\QT\\QObjectTimer\\img\\";
    QString picturePath = basePath + QString::number((picId++ % 5) + 1) + ".png";
    QImage img(picturePath);
    ui->label->setPixmap(QPixmap::fromImage(img));
}
