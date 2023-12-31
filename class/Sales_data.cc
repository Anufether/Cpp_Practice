/**
 * @file Sales_data.cc
 * @author anufether (anufether@sina.com)
 * @brief 练习7.1：使用2.6.1节定义的Sales_data类为1.6节的交易处理程序编写一个新版本
 * @date 2023-07-25
 *
 *
 * @question  练习7.8:为什么read函数将其Sales_data参数定义成普通的引用，而print将其参数定义成常量引用
 * @answer	答：因为读入的时候是内存中的值未固定，还不能定义为常量。且定义为常量后不能被改写，不合逻辑。
 * 
 * @question 练习7.20：友元在什么时候有用？请分别列举使用友元的利弊
 * @answer 类以外的函数访问类中的私有属性时，需要声明友元。
 * 利：友元机制能让特定的类或函数访问另一个类的私有成员，无需经过公用接口，某些情况下提高了性能。增加了代码的可读性。
 * 弊：友元破坏了类的封装性，是的外部代码可以直接访问私有成员，增加了复杂性。降低了代码的安全性
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
	item.revenue = item.units_sold * price;

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
	Sales_data data1, data2;

	// 调用read函数，从输入流中读取交易信息并存储在data1对象中
	read(std::cin, data1);
	read(std::cin, data2);

	// 调用print函数，打印
	print(std::cout, data1);
	print(std::cout, data2);

	// 将结果相加
	Sales_data sum = add(data1, data2);

	/**
	 * @brief 第一个read函数：从标准输入读取数据，并将数据存储在data1对象中。
	 *	第二个read函数：从标准输入再次读取数据，并将数据存储在data2对象中。
	 *	if语句：检查第二个read函数的返回值。由于read函数的返回类型是std::istream&，
	 *  会隐式转换为布尔值。如果读取成功，则条件为true，否则为false
	 *
	 */
	if (read(read(std::cin, data1), data2))
	{
		std::cout << "success" << std::endl;
	}

	// if (data1.bookNo == data2.bookNo)
	// {
	// 	unsigned totalCnt = data1.units_sold + data2.units_sold;
	// 	double totalRevenue = data1.revenue + data2.revenue;

	// 	// 打印信息
	// 	std::cout << data1.bookNo << " " << totalCnt << " " << totalRevenue << " ";

	// 	if (totalCnt != 0)
	// 	{
	// 		std::cout << totalRevenue / totalCnt << std::endl;
	// 	}
	// 	else
	// 	{
	// 		std::cout << "(no sales)" << std::endl;
	// 	}

	// 	return 0;
	// }
	// else
	// {
	// 	std::cerr << "Data must refer to the same ISBN"
	// 			  << std::endl;
	// 	return -1;
	// }
}
