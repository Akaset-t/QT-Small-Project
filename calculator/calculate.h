#ifndef CALCULATe_H
#define CALCULATe_H

#include <QString>


class Calculator {
public:
    // 目前只能计算正整数,且不支持不合法的表达式
    static double calculate(const QString& expression);
};

#endif // CALCULATe_H