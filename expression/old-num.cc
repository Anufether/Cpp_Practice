/**
 * @file old-num.cc
 * @author anufether (anufether@sina.com)
 * @brief 编写一段程序,使用条件运算符从vector<int>中遭到那些元素的值是奇数,然后将这些奇数值翻倍
 * @date 2023-07-21
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6};
    for (auto &i : v)
    {
        i = (i % 2 == 0) ? i : i * 2;
    }
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}