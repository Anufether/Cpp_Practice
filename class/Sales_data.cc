/**
 * @file Sales_data.cc
 * @author anufether (anufether@sina.com)
 * @brief 练习7.1：使用2.6.1节定义的Sales_data类为1.6节的交易处理程序编写一个新版本
 * @date 2023-07-25
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

int main()
{
	Sales_data data1, data2;

	// 读取数据1和数据2的代码
	double price = 0;

	std::cin >> data1.bookNo >> data1.units_sold >> price;
	// 计算价格和售出单位的总收益
	data1.revenue = data1.units_sold * price;

	std::cin >> data2.bookNo >> data2.units_sold >> price;
	data2.revenue = data2.units_sold * price;

	std::cout << data1.isbn() << std::endl;

	// data1属性加上data2的属性
	data1.combine(data2);

	std::cout << data1.isbn() << std::endl;

	if (data1.bookNo == data2.bookNo)
	{
		unsigned totalCnt = data1.units_sold + data2.units_sold;
		double totalRevenue = data1.revenue + data2.revenue;

		// 打印信息
		std::cout << data1.bookNo << " " << totalCnt << " " << totalRevenue << " ";

		if (totalCnt != 0)
		{
			std::cout << totalRevenue / totalCnt << std::endl;
		}
		else
		{
			std::cout << "(no sales)" << std::endl;
		}

		return 0;
	}
	else
	{
		std::cerr << "Data must refer to the same ISBN"
				  << std::endl;
		return -1;
	}
}
