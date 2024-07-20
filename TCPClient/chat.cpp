#include <QTcpSocket>
#include <QString>
#include "chat.h"
#include "ui_chat.h"

Chat::Chat(QTcpSocket * _socket, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Chat), socket(_socket)
{
    ui->setupUi(this);
}

Chat::~Chat()
{
    delete ui;
}

void Chat::on_clearButton_clicked() {
    ui->lineEdit->clear();
}


void Chat::on_sendButton_clicked() {
    QString text = ui->lineEdit->text();
    socket->write(text.toUtf8());
}

