/**
 * @file function_basic.cc
 * @author anufether (anufether@sina.com)
 * @brief 6.1节实例
 * @date 2023-09-24
 * 6.1节练习
 * 练习6.1：实参和形参的区别是什么？
 * 实参是形参的初始值。第一个个实参初始化第一个形参，第二个实参初始化第二个形参
 * 练习6.2：
 * a)函数定义返回值为int，而实际返回值为字符串，应该将int修改如下是一个实例：见function_return_string.cc
 * b)缺少返回值类型void,c++中若没有返回值类型，应该返回void,即：void f2(int i){...}
 * c)两个相同的参数
 * d)函数体应该定义在{}中
 * 练习6.3：见此实例
 * 练习6.5：见实例function_
 */
#include <iostream>

using namespace std;

// 计算阶乘函数
int fact(int val)
{
    int ret = 1;
    while (val > 1)
    {
        ret *= val--;
    }
    return ret;
}

int main()
{
    int j = fact(5);
    cout << "5! is " << j << endl;
    return 0;
}