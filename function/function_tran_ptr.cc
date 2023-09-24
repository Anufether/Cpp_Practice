/**
 * @file function_tran_ptr.cc
 * @author anufether (anufether@sina.com)
 * @brief 6.10节练习
 * @date 2023-09-24
 * 
 */
#include <iostream>

void swap_ptr(int *ptr1, int *ptr2)
{
    int temp;
    temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int main()
{
    int a=1,b=2;
    swap_ptr(&a,&b);
    std::cout << a << " " << b << std::endl;

    return 0;
}