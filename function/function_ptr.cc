/**
 * @file function_ptr.cc
 * @author anufether (anufether@sina.com)
 * @brief 6.2.1节指针形参
 * @date 2023-09-24
 * 
 */
#include <iostream>

void reset(int* ip)
{
    *ip = 1;
    std::cout << "ip old address: " << &ip << std::endl;
    std::cout << "ip old value: " << ip << std::endl;
    std::cout << "*ip old value: " << *ip << std::endl;

    ip = nullptr;
    std::cout << "ip new address: " << &ip << std::endl;
    std::cout << "ip new value: " << ip << std::endl; // 输出的是 nullptr
}

int main()
{
    int i = 42;
    reset(&i);
    std::cout << "i address: " << &i << std::endl;
    std::cout << "i value: " << i << std::endl;

    return 0;
}
