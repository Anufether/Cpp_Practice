/**
 * @file arith-ex.cc
 * @author anufether (anufether@sina.com)
 * @brief 
 * @version 0.1
 * @date 2023-07-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>

using namespace std;

int main()
{
    cout << -30 * 3 + 21 / 5 << endl;
    cout << -30 + 3 * 21 / 5 << endl;
    cout << 30 / 3 * 21 % 5 << endl;
    cout << -30 / 3 * 21 % 4 << endl;
    cout << 5 + 10 * 20 / 2 << endl;

    int ia[] = {9, 2, 4, 6, 8};
    int last = *(ia + 4);
    cout << last << endl;
    last = *ia + 4;
    cout << last << endl;

    int i = 0;
    cout << i << " " << ++i << endl;

    return 0;
}