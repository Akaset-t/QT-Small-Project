#include <QAction>
#include <QFileDialog>
#include <QFile>
#include <QCoreApplication>
#include <QByteArray>
#include <QString>
#include <QDebug>
#include <QIODevice>
#include <QKeyEvent>
#include <QStandardPaths>
#include <Qt>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), openFile(nullptr)
{
    ui->setupUi(this);
    connect(ui->newFile, SIGNAL(triggered()), this, SLOT(newFileSlot()));
    connect(ui->openFile, &QAction::triggered, this, &MainWindow::openFileSlot);
    connect(ui->saveAsFile, &QAction::triggered, this, &MainWindow::saveAsFileSlot);
    connect(ui->saveFile, &QAction::triggered, this,  &MainWindow::saveFileSlot);
}

MainWindow::~MainWindow()
{
    delete ui;
    if (openFile != nullptr) {
        openFile->close();
        delete openFile;
        openFile = nullptr;
    }
}

void MainWindow::newFileSlot() {
    ui->textEdit->clear();
    this->setWindowTitle("新建文本文档.txt");
}

void MainWindow::openFileSlot() {
    QString desktopPath = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    QString fileName = QFileDialog::getOpenFileName(this, "选择一个文本文件",
                                                    desktopPath, "Text Files (*.txt)");

    if (!fileName.isEmpty()) {
        if (openFile != nullptr) {
            openFile->close();
            delete openFile;
            openFile = nullptr;
        }
        openFile = new QFile(fileName);
        openFile->open(QIODevice::ReadWrite);
        QByteArray file_text = openFile->readAll();
        ui->textEdit->setPlainText(QString(file_text));
    }
}

void MainWindow::saveAsFileSlot() {
    QString desktopPath = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    QString fileName = QFileDialog::getSaveFileName(this, "Save File",
                                                    desktopPath + "/新建文本文档.txt", 
                                                    "Text Files (*.txt)");
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        file.open(QIODevice::WriteOnly);
        QString file_text = ui->textEdit->toPlainText();
        file.write(file_text.toUtf8());
        file.close();
    }
}

void MainWindow::saveFileSlot() {
    if (openFile == nullptr) return;

    QString file_text = ui->textEdit->toPlainText();
    openFile->resize(0);
    openFile->write(file_text.toUtf8());
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    if (event->modifiers() == Qt::ControlModifier && event->key() == Qt::Key_S) {
        if (openFile == nullptr) 
            saveAsFileSlot();
        else {
            saveFileSlot();
        }
    }
}