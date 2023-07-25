/**
 * @file int-dec.cc
 * @author anufether (anufether@sina.com)
 * @brief 
 * @date 2023-07-20
 * 
 */
#include <iostream>
#include <cmath>

int main()
{
    double i;
    std::cin >> i;
    double j = std::floor(i);
    if (i == j)
    {
        std::cout << "i is int" << std::endl;
    }
    else
    {
        std::cout << "i is double" << std::endl;
    }

    return 0;
}
