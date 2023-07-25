/**
 * @file Sales_data.h
 * @author anufether (anufether@sina.com)
 * @brief 图书类编写
 * @date 2023-07-25
 *
 */
#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>

struct Sales_data
{

	// 新成员：关于Sales_data对象的操作
	std::string isbn() const
	{
		return this->bookNo;
	}

	Sales_data &combine(const Sales_data &);

	double avg_price() const;

	/**
	 * @brief 图书编号
	 *
	 */
	std::string bookNo;

	/**
	 * @brief 售出单位
	 *
	 */
	unsigned units_sold = 0;

	/**
	 * @brief 收益
	 *
	 */
	double revenue = 0.0;
};

// Sales_data的非成员接口函数
Sales_data add(const Sales_data &, const Sales_data &);
std::ostream &print(std::ostream &, const Sales_data &);
std::istream &read(std::istream &, Sales_data &);

#endif
