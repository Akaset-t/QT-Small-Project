#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QString>
#include <QSqlTableModel>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setDatabaseName("mydatabase");
    db.setUserName("myuser");
    db.setPassword("mypassword");

    if (!db.open()) {
        qDebug() << "Database error occurred:" << db.lastError().text();
    }
    else {
        qDebug() << "Database connect success";
        model = new QSqlTableModel(this, db);
        model->setTable("student");
        ui->tableView->setModel(model);
    }
    
}

MainWindow::~MainWindow()
{
    delete ui;
    delete model;
}

void MainWindow::on_insertPushButton_clicked() {
    QString id = ui->idLineEdit->text();
    QString name = ui->nameLineEdit->text();
    QString birth = ui->birthLineEdit->text();

    QSqlQuery query;
    query.prepare("INSERT INTO student (id, name, birth) VALUES (:id, :name, :birth)");
    query.bindValue(":id", id);
    query.bindValue(":name", name);
    query.bindValue(":birth", birth);

    if (!query.exec()) {
        qDebug() << "Error inserting into table:\n" << query.lastError();
        db.rollback();
    } else {
        qDebug() << "Insert successful!";
        db.commit();
        model->select();
    }
}


void MainWindow::on_findPushButton_clicked()
{
    // QSqlQuery query;
    // if (!query.exec("SELECT * FROM student")) {
    //     qDebug() << "Error executing query:\n" << query.lastError();
    //     return;
    // }

    // while (query.next()) {
    //     QString id = query.value(0).toString();
    //     QString name = query.value(1).toString();
    //     QString birth = query.value(2).toString();

    //     qDebug() << "ID:" << id << "Name:" << name << "Birth:" << birth;
    // }
    model->select();
}

