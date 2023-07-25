/**
 * @file grade-condition.cc
 * @author anufether (anufether@sina.com)
 * @brief 使用条件控制语句判断成绩
 * @date 2023-07-21
 *
 */
#include <iostream>

using namespace std;

int main()
{
    int grade;
    std::cin >> grade;
    std::string finalgrade = (grade < 60) ? "loser" : (grade < 75) ? "low pass"
                                                  : (grade < 90)   ? "pass"
                                                                   : "high pass";
    std::cout << finalgrade << std::endl;

    return 0;
}