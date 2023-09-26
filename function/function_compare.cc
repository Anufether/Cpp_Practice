/**
 * @file function_compare.cc
 * @author anufether (anufether@sina.com)
 * @brief 练习6.21
 * @date 2023-09-26
 * 轻易可得应该用的是int
 */
#include <iostream>

int compare(int a, int *b)
{
    if (a > *b)
    {
        return a;
    }
    else
    {
        return *b;
    }
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a = 1, b = 2;
    std::cout << compare(a, &b) << std::endl;
    swap(&a, &b);
    std::cout << a << b << std::endl;
    return 0;
}