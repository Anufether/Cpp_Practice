/**
 * @file function_ptr_arr.cc
 * @author anufether (anufether@sina.com)
 * @brief
 * @date 2023-10-05
 *
 */
#include <iostream>

typedef int arrT[10];
using arrT = int[10];
arrT *func(int i);

int (*func(int i))[10];

int main()
{

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0}; // 使用大括号进行数组初始化

    // arrT是一个类型别名，它表示的类型是含有10个整数的数组
    // p1是一个含有10个指针的数组，可以不初始化，因为它是一个数组，不是一个指针
    int *p1[10];

    // p2是一个指针，它指向含有10个整数的数组
    int(*p2)[10] = &arr;

    // 使用循环打印数组中的元素
    for (int i = 0; i < 10; ++i)
    {
        std::cout << arr[i] << " ";
    }
    for (int i = 0; i < 10; ++i)

    {
        std::cout << (*p2)[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
