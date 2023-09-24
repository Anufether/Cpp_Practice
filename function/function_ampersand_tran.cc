/**
 * @file function_ampersand_tran.cc
 * @author anufether (anufether@sina.com)
 * @brief 练习6.12:使用引用交换数据;个人认为使用指针来交换数据比较合理，因为指针操作，
 * 数据时，引用只能交换相同类型的值，且必须要传递参数
 * @date 2023-09-24
 * 练习6.13：void f(T)传入的形参不能被修改，void f(T&)属于引用，能够被修改
 * 练习6.14: 当涉及到函数方法需要返回多个参数时，可以使用引用。当调用的值不能被修改
 * 时，不使用引用
 */
#include <iostream>

void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int main()
{
    int x = 1, y = 2;

    swap(x, y);

    std::cout << x << " " << y << std::endl;

    return 0;
}