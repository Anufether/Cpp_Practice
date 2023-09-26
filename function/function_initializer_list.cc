/**
 * @file function_initializer_list.cc
 * @author anufether (anufether@sina.com)
 * @brief
 * @date 2023-09-26
 * 练习6.27，计算列表中的和
 * 练习6.28：string类型
 * 练习6.29：因为initializer_list并不适合修改元素，传入引用类型没有必要
 */
#include <iostream>
#include <initializer_list>

using namespace std;

int sum(initializer_list<int> i)
{
    int result = 0;

    for (auto beg = i.begin(); beg != i.end(); ++beg)
    {
        result += *beg;
    }

    return result;
}

int main()
{
    cout << sum({1, 2, 5}) << endl;

    cout << sum({32, 42, 1}) << endl;

    cout << sum({2, 54}) << endl;

    return 0;
}