/**
 * @file function_local_static_object.cc
 * @author anufether (anufether@sina.com)
 * @brief 6.1.1局部静态对象在程序的执行调用后仍然可用
 * @date 2023-09-24
 * 练习6.6：说明形参、局部变量、局部静态变量的区别
 * 形参和函数体内部定义的变脸统称为局部变量（local variable）
 * 静态局部变量，区别于局部变量在于生命周期，它直到程序结束才会被销毁
 */
#include <iostream>

using namespace std;

size_t static_count_calls()
{
    static size_t ctr = 0; // 调用结束后，这个值仍然有效
    return ++ctr;
}

size_t count_calls()
{
    size_t ctr = 0;
    return ++ctr;
}

int main()
{
    for (size_t i = 0; i != 10; i++)
    {
        cout << static_count_calls() << " ";
    }

    cout << endl;

    for (size_t i = 0; i != 10; i++)
    {
        cout << count_calls() << " ";
    }

    return 0;
}