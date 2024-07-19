#include <QString>
#include <QVector>
#include <QChar>
#include <QStack>
#include <QDebug>
#include <QVariant>
#include "calculate.h"

int precedence(const QChar& op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

double performOperation(double num1, double num2, QChar op) {
    switch (op.toLatin1()) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            return num1 / num2;
        default:
            return 0.0;
    }
}

//将标准表达式转化成逆波兰表达式
QVector<QVariant> infixToPostfix(const QString &expression) {
    QStack<QChar> opStack;
    QVector<QVariant> postfixExpression;
    double sum = 0;
    bool flag = false;
    for (int i = 0; i < expression.size(); i++) {
        while (i < expression.size() && expression[i].isDigit()) {
            flag = true;
            sum = sum * 10 + expression[i].digitValue();
            i++;
        }
        if (flag) {
            postfixExpression.append(QVariant(sum));
            sum = 0;
            flag = false;
        }
        if (i == expression.size()) break;

        QChar c = expression[i];
        if (c == '(') {
            opStack.push(c);
        }
        else if (c == ')') {
            while (opStack.top() != '(') {
                postfixExpression.append(QVariant(opStack.top()));
                opStack.pop();
            }
            opStack.pop();
        }
        else {
            while (!opStack.empty() && precedence(opStack.top()) >= precedence(c)) {
                postfixExpression.append(QVariant(opStack.top()));
                opStack.pop();
            }
            opStack.push(c);
        }
    }

    while (!opStack.empty()) {
        postfixExpression.append(QVariant(opStack.top()));
        opStack.pop();
    }

    return postfixExpression;
}

double Calculate::calculate(const QString &expression) {
    QVector<QVariant> postfixExpression = infixToPostfix(expression);
    QStack<double> numStack;

    for (const auto& item : postfixExpression) {
        if (item.canConvert<QChar>()) {
            QChar ch = item.toChar();
            double num2 = numStack.top();
            numStack.pop();
            double num1 = numStack.top();
            numStack.pop();
            numStack.push(performOperation(num1, num2, ch));
        } else {
            numStack.push(item.toDouble());
        } 
    }
    return numStack.top();
}