/**
 * @file Person.cc
 * @author anufether (anufether@sina.com)
 * @brief
 * @date 2023-07-25
 *
 */
#include <iostream>
#include "Person.h"

std::istream &read(std::istream &is, Person &item)
{
    is >> item.name >> item.address;
    return is;
}

std::ostream &print(std::ostream &os, const Person &item)
{
    os << item.name << " " << item.address << std::endl;
    return os;
}

int main()
{
    Person person;

    // 调用read函数读取
    read(std::cin, person);

    // 调用print，打印
    print(std::cout, person);

    std::cout << "如此便好" << std::endl;
}