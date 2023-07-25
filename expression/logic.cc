/**
 * @file logic.cc
 * @author anufether (anufether@sina.com)
 * @brief
 * @date 2023-07-20
 *
 */

#include <iostream>
#include <string>

int main()
{
    // int i = 0, j = 1, k = 2;
    // std::cout << (i < j < k) << std::endl;
    // std::cout << (i < j && j < k) << std::endl;

    // int logic = 1;
    // int j = NULL;
    // if (logic <= (j = ++logic))
    // {
    //     std::cout << "logic <= logic++" << std::endl;
    // } else
    // {
    //     std::cout << "logic > logic++" << std::endl;
    // }

    // int i; double d;
    // d = i = 3.5;
    // std::cout << "i = " << i << std::endl;
    // std::cout << "d = " << d << std::endl;
    // i = d = 3.5;
    // std::cout << "i = " << i << std::endl;
    // std::cout << "d = " << d << std::endl;

    // double dval;
    // int ival;
    // int *pi;

    // dval = 0.0;   // 将 dval 赋值为 0.0
    // ival = 0;     // 将 ival 赋值为 0
    // pi = nullptr; // 将 pi 设置为空指针

    // std::vector<int> v = {1, 2, -3, 4, 5};
    // auto pbeg = v.begin(), pend = v.end();

    // // 输出元素直至遇到第一个负值为止
    // while (pbeg != pend && *pbeg >= 0)
    // {
    //     std::cout << *++pbeg << std::endl;
    // }

    // std::string s1 = "a string", *p = &s1;
    // auto n = s1.size();
    // auto m = p->size();
    // auto l = (*p).size();

    // std::cout << "n = " << n << std::endl;
    // std::cout << "m = " << m << std::endl;
    // std::cout << "l = " << l << std::endl;

    int grade;
    std::cin >> grade;
    std::string finalgrade = (grade < 60) ? "loser" : (grade < 75) ? "low pass"
                                                  : (grade < 90)   ? "pass"
                                                                   : "high pass";
    std::cout << finalgrade << std::endl;

    std::cout << ((grade < 60) ? "loser" : (grade < 75) ? "low pass"
                                       : (grade < 90)   ? "pass"
                                                        : "high pass");
    std::cout << (grade < 60) ? "loser" : (grade < 75) ? "low pass"
                                      : (grade < 90)   ? "pass"
                                                       : "high pass";
    // std::cout << grade < 60 ? "loser" : (grade < 75) ? "low pass" : (grade < 90) ? "pass" : "high pass" << std::endl;

    return 0;
}