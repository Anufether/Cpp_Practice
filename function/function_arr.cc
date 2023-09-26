/**
 * @file function_arr.cc
 * @author anufether (anufether@sina.com)
 * @brief 6.2.4节数组形参
 * @date 2023-09-26
 *
 */
#include <iostream>

template <typename T>
void print(const T &container)
{
    for (const auto &element : container)
    {
        std::cout << element << std::endl;
    }
}

int main()
{
    int i = 0, j[2] = {0, 1};
    print(j);

    return 0;
}