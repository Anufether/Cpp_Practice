/**
 * @file function_ptr_arr_practice.cc
 * @author anufether (anufether@sina.com)
 * @brief 6.3.3节练习
 * @date 2023-10-28
 *  第三种返回方式，可能是我最喜欢的，这可用使得风格更加紧凑，且易读
 */
#include <iostream>
#include <string>

std::string temp[10];

// 使用原始的数组指针返回
std::string (*arrPtr(int i))[10]
{
    return &temp;
}

// 使用数组的别名进行返回
using StringArray = std::string[10];

StringArray *arrPtrUsingAlias(int i)
{
    return &temp;
}

// 使用尾置指针进行返回
auto arrPtrTrailingReturn(int i) -> std::string (*)[10]
{
    return &temp;
}

// 使用decltype进行返回
decltype(temp) *arrPtrDecltype(int i)
{
    return &temp;
}

int odd[] = {1, 3, 5, 7, 9};
int even[] = {0, 2, 4, 6, 8};

decltype(odd) *arr_ptr_decltype(int i)
{
    return (i % 2) ? &odd : &even;
}

auto arr_ptr_trailing_return(int i) -> int (*)[5]
{
    return (i % 2) ? &odd : &even;
}

using IntArray = int[5];
IntArray *arr_ptr_using_alias(int i)
{
    return (i % 2) ? &odd : &even;
}

int (*arr_ptr(int i))[5]
{
    return (i % 2) ? &odd : &even;
}

int main()
{
    temp[0] = "a";
    temp[1] = "b";
    temp[2] = "c";
    temp[3] = "d";
    temp[4] = "e";
    temp[5] = "f";
    temp[6] = "g";
    temp[7] = "h";
    temp[8] = "i";
    temp[9] = "j";
    // std::string temp[10] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j"};

    std::string(*ptr1)[10] = arrPtr(0);
    std::string(*ptr2)[10] = arrPtr(0);
    std::string(*ptr3)[10] = arrPtr(0);
    std::string(*ptr4)[10] = arrPtr(0);

    std::cout << "Array elements: " << std::endl;
    for (int j = 0; j < 10; j++)
    {
        std::cout << (*ptr1)[j] << " ";
    }
    std::cout << std::endl;

    for (int j = 0; j < 10; j++)
    {
        std::cout << (*ptr2)[j] << " ";
    }
    std::cout << std::endl;

    for (int j = 0; j < 10; j++)
    {
        std::cout << (*ptr3)[j] << " ";
    }
    std::cout << std::endl;

    for (int j = 0; j < 10; j++)
    {
        std::cout << (*ptr4)[j] << " ";
    }
    std::cout << std::endl;

    ///////////////////////////////

    int i = 1; // 1 for odd, 0 for even

    int(*ptr_int1)[5] = arr_ptr(i);
    int(*ptr_int2)[5] = arr_ptr_decltype(i);
    int(*ptr_int3)[5] = arr_ptr_trailing_return(i);
    int(*ptr_int4)[5] = arr_ptr_using_alias(i);

    std::cout << "Array elements: ";
    for (int j = 0; j < 5; j++)
    {
        std::cout << (*ptr_int1)[j] << " ";
    }
    std::cout << std::endl;

    std::cout << "Array elements (decltype): ";
    for (int j = 0; j < 5; j++)
    {
        std::cout << (*ptr_int2)[j] << " ";
    }
    std::cout << std::endl;

    std::cout << "Array elements (trailing return): ";
    for (int j = 0; j < 5; j++)
    {
        std::cout << (*ptr_int3)[j] << " ";
    }
    std::cout << std::endl;

    std::cout << "Array elements (using alias): ";
    for (int j = 0; j < 5; j++)
    {
        std::cout << (*ptr_int4)[j] << " ";
    }
    std::cout << std::endl;

    return 0;
}