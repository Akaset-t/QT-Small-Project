#include <QTcpSocket>
#include <QMessageBox>
#include <QHostAddress>
#include <QAbstractSocket>
#include <QDebug>
#include <QString>
#include <Qt>
#include "widget.h"
#include "ui_widget.h"
#include "chat.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    // setAttribute(Qt::WA_DeleteOnClose);
    ui->setupUi(this);
    socket = new QTcpSocket(this);
}

Widget::~Widget()
{
    delete ui;
    socket->close();
    delete socket;
}

void Widget::on_cancelButton_clicked()
{
    this->close();
}


void Widget::on_connectButton_clicked() {
    QString ip_addr = ui->ipLineEdit->text();
    QString port = ui->portLineEdit->text();
    //简单监测输入是否为空，其他不合法情况暂不考虑
    if (ip_addr.isEmpty() || port.isEmpty()) {
        return;
    }
    socket->connectToHost(QHostAddress(ip_addr), port.toUShort());
    connect(socket, &QTcpSocket::connected, [this]{
        QMessageBox::information(this, "提示", "服务器连接成功");
        this->hide();
        Chat *chat = new Chat(socket);
        chat->show();
    });
    connect(socket, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error), 
        [this] (QAbstractSocket::SocketError socketError) {
            qDebug() << socketError;
            QMessageBox::warning(this, "警告", "服务器连接失败");
        }
    );
    connect(socket, &QTcpSocket::disconnected, [this] {
        QMessageBox::warning(this, "警告", "服务器连接断开");
    });

}