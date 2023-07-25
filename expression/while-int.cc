/**
 * @file while-int.cc
 * @author anufether (anufether@sina.com)
 * @brief 为while循环写一个条件，十七从标准输入中读取整数，遇到42时停止。
 * @date 2023-07-21
 * 
 */
#include <iostream>

using namespace std;

int main()
{
    int i;
    while (cin >> i && i != 42)
    {
        cout << i << endl;
    }

    return 0;
}