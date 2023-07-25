/**
 * @file const-sizeof
 * @author anufether (anufether@sina.com)
 * @brief 编写一段程序,输出每一种内置类型所占空间的大小
 * @date 2023-07-21
 * 
 */

#include <iostream>

int main() {
    std::cout << "Size of bool: " << sizeof(bool) << " bytes" << std::endl;
    std::cout << "Size of char: " << sizeof(char) << " bytes" << std::endl;
    std::cout << "Size of short: " << sizeof(short) << " bytes" << std::endl;
    std::cout << "Size of int: " << sizeof(int) << " bytes" << std::endl;
    std::cout << "Size of long: " << sizeof(long) << " bytes" << std::endl;
    std::cout << "Size of long long: " << sizeof(long long) << " bytes" << std::endl;
    std::cout << "Size of float: " << sizeof(float) << " bytes" << std::endl;
    std::cout << "Size of double: " << sizeof(double) << " bytes" << std::endl;
    std::cout << "Size of long double: " << sizeof(long double) << " bytes" << std::endl;
    std::cout << "Size of wchar_t: " << sizeof(wchar_t) << " bytes" << std::endl;

    int x[10];
    int *p = x;

    std::cout << sizeof(x)/sizeof(*x) << std::endl;
    std::cout << sizeof(p)/sizeof(*p) << std::endl;

    return 0;
}
