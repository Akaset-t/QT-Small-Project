#include <QTcpServer>
#include <QHostAddress>
#include <QTcpSocket>
#include <QDebug>
#include <memory>
#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget), server(new QTcpServer(this))
{
    ui->setupUi(this);
    QHostAddress ip_addr = QHostAddress("127.0.0.1");
    quint16 port = 10123;
    ui->ipLineEdit->setText(ip_addr.toString());
    ui->portLineEdit->setText(QString::number(port));
    ui->ipLineEdit->setReadOnly(true);
    ui->portLineEdit->setReadOnly(true);

    server->listen(ip_addr, port);
    connect(server, &QTcpServer::newConnection, this, &Widget::newClientHander);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::newClientHander(){
    
    //建立tcp连接
    QTcpSocket *socket = server->nextPendingConnection();

    ui->textEdit->append(QString(socket->peerAddress().toString() + ":" + QString::number(socket->peerPort()) + " 建立新连接"));
    connect(socket, &QTcpSocket::readyRead, this, &Widget::clientInfoSlot);
}

void Widget::clientInfoSlot() {
    QTcpSocket* socket = qobject_cast<QTcpSocket*>(sender());
    ui->textEdit->append(QString(socket->peerAddress().toString() + ":" + QString::number(socket->peerPort()) + ": ") + QString(socket->readAll()));
}