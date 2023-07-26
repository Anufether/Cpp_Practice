/**
 * @file Sales_data_constructor.cc
 * @author anufether (anufether@sina.com)
 * @brief 7.1.4节练习
 * @date 2023-07-25
 *
 * @question 练习7.8：为什么read函数将其Sales_data参数定义成普通的引用，而print将其参数定义为常量引用
 * @answer 因为读写的操作会改变流的内容，所以两个函数接收的都是普通引用，而非对常量的引用
 */

#include <iostream>
#include <string>
#include "Sales_data.h"

/**
 * @brief 返回平均价格
 *
 * @return double
 */
double Sales_data::avg_price() const
{
    if (units_sold)
    {
        return revenue / units_sold;
    }
    else
    {
        return 0;
    }
}

/**
 * @brief 函数combine的设计类似于+=,调用该函数的对象代表的时赋值运算符左侧的运算对象，右侧是传入对象。
 *
 * @param rhs
 * @return Sales_data&
 */
Sales_data &Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold; // 把rhs的成员加到this对象的成员上
    revenue += rhs.revenue;
    return *this; // 返回调用该函数的对象
}

// 输入的交易信息包括ISBN、售出的册数以及销售价格
std::istream &read(std::istream &is, Sales_data &item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

// 打印交易信息
std::ostream &print(std::ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " "
       << item.revenue << " " << item.avg_price() << "\n";

    return os;
}

// 定义add函数，add函数接收两个Sales_data对象组为器参数，返回值是一个新的Sales_data,用于表示前两个对象的和
Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    // 把lhs的数据成员拷贝给sum
    Sales_data sum = lhs;
    sum.combine(lhs);
    // 把rhs的数据成员加到sum当中
    return sum;
}

int main()
{
    // // 默认构造函数（synthesized default constructor)
    // Sales_data data1;
    // read(std::cin, data1);
    // print(std::cout, data1);

    // // 构造函数初始值列表
    // Sales_data data2("ISBN123123");
    // Sales_data data3("ISBN12341234", 5, 5.5);
    // print(std::cout, data2);
    // print(std::cout, data3);

    // // 在类的外部定义构造函数
    // Sales_data data4(std::cin);
    // print(std::cout, data4);

    Sales_data total;
    if (read(std::cin, total))
    {
        Sales_data trans;
        while (read(std::cin, trans))
        {
            if (total.isbn() == trans.isbn())
            {
                total = add(total, trans);
            }
            else
            {
                print(std::cout, total);
                total = trans;
            }
        }
    }
    else
    {
        std::cerr << "No data?" << std::endl;
    }

    return 0;
}