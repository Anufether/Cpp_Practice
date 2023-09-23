/**
 * @file class_type.cc
 * @author anufether (anufether@sina.com)
 * @brief 7.3.3节练习
 * @date 2023-07-26
 *
 */

#include <iostream>
class X
{
    Y *next;
};

class Y
{
    X next;
};

// 这里也可以调换rem，base初始化的顺序。
class Z
{
    Z(int i, int j) : base(i)
    {
        rem = base % j;
    }
    int rem, base;
}

int
main()
{
}