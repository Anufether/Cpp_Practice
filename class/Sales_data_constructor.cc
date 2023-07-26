/**
 * @file Sales_data_constructor.cc
 * @author anufether (anufether@sina.com)
 * @brief 7.1.4节练习、7.2节练习
 * @date 2023-07-25
 *
 * @question 练习7.8：为什么read函数将其Sales_data参数定义成普通的引用，而print将其参数定义为常量引用
 * @answer 因为读写的操作会改变流的内容，所以两个函数接收的都是普通引用，而非对常量的引用
 * 
 * @question 练习7.16：在类的定义中对于访问说明符出现的位置和次数有限定吗？如果有，是什么
 * @answer 一个类可以包含0个活多个范文说明符，而且对于某个访问说明符能出现多少次也没有严格的限定。
 * 每个访问说明符指向了接下来的成员的访问级别，其有效范围知道出现下一个访问说明符或者到达类的结尾处为止
 * 
 * @question 练习7.16:什么样的成员你应该定义在public说明符之后，什么洋的成员应该定义在private说明符之后
 * @answer 我认为一个类的成员变量应该在private之后，这样可以隐藏类的细节，防止被滥用。类的访问方法应该在public
 * 给外界使用
 * @gpt 一般来说，公有成员（public members）应该放置在 public 访问说明符之后，这样它们可以被类的外部访问，从而提供类的接口（interface）。
 * 这些公有成员通常是类的用户（其他代码）需要使用的函数和数据成员，用于表示类的行为和状态。
 * 私有成员（private members）应该放置在 private 访问说明符之后，这样它们只能在类的内部使用，不能被类的用户直接访问。
 * 私有成员通常用于类的实现细节，隐藏了类的内部表示和实现细节，防止外部代码直接访问和修改类的私有状态，从而实现了封装（encapsulation）的概念。
 * 
 * @question 练习7.17：使用class和struct时有区别吗？如果有，是什么
 * @answer 使用class或struct关键字时只有唯一一点区别，struct和class的more访问权限不太一样。
 * 推荐：类可以在它的第一个访问说明符之前定义成员，对这种成员的访问权限依赖于定类定义的方式。
 * 当我们希望定义的类的所有成员时public时，使用struct，
 * 反之，如果希望成员是private时，使用class
 * 
 * @question 练习7.18：封装是何含义？它有什么用处
 * @answer 1、外部代码无法直接访问和修改类的私有成员。可以避免非法或不必要的操作
 * 2、外部调用不需要了解内部的内容，直接调方法
 * 3、实现解耦，内部的变化不会影响外部的接口
 * 
 * 
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