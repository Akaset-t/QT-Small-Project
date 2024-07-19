#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QString>
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
    void on_num0_clicked();

    void on_num1_clicked();

    void on_num2_clicked();

    void on_num3_clicked();

    void on_num4_clicked();

    void on_num5_clicked();

    void on_num6_clicked();

    void on_num7_clicked();

    void on_num8_clicked();

    void on_num9_clicked();

    void on_leftParen_clicked();

    void on_rightParen_clicked();

    void on_div_clicked();

    void on_mul_clicked();

    void on_sub_clicked();

    void on_add_clicked();

    void on_clear_clicked();

    void on_del_clicked();

    void on_pushButton_eq_clicked();

private:
    Ui::Widget *ui;
    QString expression;
};
#endif // WIDGET_H
