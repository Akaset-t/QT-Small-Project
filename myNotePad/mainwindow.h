#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QFile>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void keyPressEvent(QKeyEvent *event);

private slots:
    void newFileSlot();
    void openFileSlot();
    void saveAsFileSlot();
    void saveFileSlot();

private:
    Ui::MainWindow *ui;
    QFile *openFile;
};
#endif // MAINWINDOW_H
