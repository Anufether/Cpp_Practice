/**
 * @file circular-meaning.cc
 * @author anufether (anufether@sina.com)
 * @brief 解释下面循环的含义
 * @date 2023-07-21
 *
 */

#include <iostream>

using namespace std;

int main()
{
    constexpr int size = 5;
    int ia[size] = {1, 2, 3, 4, 5};
    for (int *ptr = ia, ix = 0; ix != size && ptr != ia + size; ix++, ptr++)
    {
        cout << *ptr << " " << ix << endl; 
    }
}