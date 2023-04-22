#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setMaximumSize(400,550);
    this->setMinimumSize(400,550);
    this->setWindowTitle("计算器");
    QFont font("微软雅黑",16);
    ui->ans->setFont(font);

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_button1_clicked()
{
    expression += "1";
    ui->ans->setText(expression);
}

void Widget::on_button2_clicked()
{
    expression += "2";
    ui->ans->setText(expression);
}

void Widget::on_button3_clicked()
{
    expression += "3";
    ui->ans->setText(expression);
}

void Widget::on_button4_clicked()
{
    expression += "4";
    ui->ans->setText(expression);
}

void Widget::on_button5_clicked()
{
    expression += "5";
    ui->ans->setText(expression);
}

void Widget::on_button6_clicked()
{
    expression += "6";
    ui->ans->setText(expression);
}

void Widget::on_button7_clicked()
{
    expression += "7";
    ui->ans->setText(expression);
}

void Widget::on_button8_clicked()
{
    expression += "8";
    ui->ans->setText(expression);
}

void Widget::on_button9_clicked()
{
    expression += "9";
    ui->ans->setText(expression);
}

void Widget::on_button0_clicked()
{
    expression += "0";
    ui->ans->setText(expression);
}

void Widget::on_buttonplu_clicked()
{
    expression += "+";
    ui->ans->setText(expression);
}

void Widget::on_buttonmin_clicked()
{
    expression += "-";
    ui->ans->setText(expression);
}

void Widget::on_buttonmul_clicked()
{
    expression += "*";
    ui->ans->setText(expression);
}

void Widget::on_buttondiv_clicked()
{
    expression += "/";
    ui->ans->setText(expression);
}

void Widget::on_buttonclear_clicked()
{
    expression.clear();
    ui->ans->clear();
}

void Widget::on_buttondel_clicked()
{
    expression.chop(1);
    ui->ans->setText(expression);
}

void Widget::on_buttonequ_clicked()
{
    QStack<int> s_num, s_opt;

    char opt[128] = {0};
    int i = 0, tmp = 0, num1, num2;

    //把QString转换成char *
    QByteArray ba;
    ba.append(expression);   //把QString转换成QByteArray
    strcpy(opt, ba.data());  //data可以把QByteArray转换成const char *

    while (opt[i] != '\0' || s_opt.empty() != true)
    {
        if (opt[i] >= '0' && opt[i] <= '9')
        {
            tmp = tmp * 10 + opt[i] - '0';
            i++;
            if (opt[i] < '0' || opt[i] > '9')
            {
                s_num.push(tmp);
                tmp = 0;
            }
        }
        else           //操作符
        {
            if (s_opt.empty() == true || Priority(opt[i]) > Priority(s_opt.top()) ||
                    (s_opt.top() == '(' && opt[i] != ')'))
            {
                s_opt.push(opt[i]);
                i++;
                continue;
            }

            if (s_opt.top() == '(' && opt[i] == ')')
            {
                s_opt.pop();
                i++;
                continue;
            }

            if (Priority(opt[i]) <= Priority(s_opt.top()) || (opt[i] == ')' && s_opt.top() != '(') ||
                (opt[i] == '\0' && s_opt.empty() != true))
            {
                char ch = s_opt.top();
                s_opt.pop();
                switch(ch)
                {
                    case '+':
                        num1 = s_num.top();
                        s_num.pop();
                        num2 = s_num.top();
                        s_num.pop();
                        s_num.push(num1 + num2);
                        break;
                    case '-':
                        num1 = s_num.top();
                        s_num.pop();
                        num2 = s_num.top();
                        s_num.pop();
                        s_num.push(num1 - num2);
                        break;
                    case '*':
                        num1 = s_num.top();
                        s_num.pop();
                        num2 = s_num.top();
                        s_num.pop();
                        s_num.push(num1 * num2);
                        break;
                    case '/':
                        num1 = s_num.top();
                        s_num.pop();
                        num2 = s_num.top();
                        s_num.pop();
                        s_num.push(num2 / num1);
                        break;
                }
            }
        }
    }
    ui->ans->setText(QString::number(s_num.top()));
}

int Widget::Priority(char ch)
{
    switch(ch)
    {
        case '(':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

void Widget::on_buttonleft_clicked()
{
    expression += "(";
    ui->ans->setText(expression);
}

void Widget::on_buttonright_clicked()
{
    expression += ")";
    ui->ans->setText(expression);
}
