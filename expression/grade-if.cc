/**
 * @file grade-if.cc
 * @author anufether (anufether@sina.com)
 * @brief 使用if语句判断成绩
 * @date 2023-07-21
 *
 */
#include <iostream>

using namespace std;

int main()
{
    // 输入成绩
    int grade;
    cin >> grade;

    if (grade < 60)
    {
        cout << "fail" << endl;
    }
    else if (grade < 80)
    {
        cout << "pass" << endl;
    }
    else
    {
        cout << "high pass" << endl;
    }

    return 0;
}