#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_startbutton_clicked();

    void on_stopButton_clicked();
    void timeoutSlot();

private:
    Ui::Widget *ui;
    QTimer *timer;
    int picId;
};
#endif // WIDGET_H
