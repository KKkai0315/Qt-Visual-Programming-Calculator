#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QStack>
#include <cstring>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    QString expression;

private slots:
    void on_button1_clicked();

    void on_button2_clicked();

    void on_button3_clicked();

    void on_button4_clicked();

    void on_button5_clicked();

    void on_button6_clicked();

    void on_button7_clicked();

    void on_button8_clicked();

    void on_button9_clicked();

    void on_button0_clicked();

    void on_buttonplu_clicked();

    void on_buttonmin_clicked();

    void on_buttonmul_clicked();

    void on_buttondiv_clicked();

    void on_buttonclear_clicked();

    void on_buttondel_clicked();

    void on_buttonequ_clicked();

    void on_buttonleft_clicked();

    void on_buttonright_clicked();

private:
    Ui::Widget *ui;
    int Priority(char ch);
};
#endif // WIDGET_H
