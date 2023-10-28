/**
 * @file function_overload.cc
 * @author anufether (anufether@sina.com)
 * @brief 函数重载实现
 * @date 2023-10-28
 *
 */
#include <iostream>
#include <string>

// 比较两个string对象的长度，返回较短的那个引用
const std::string &shorterString(const std::string &s1, const std::string &s2)
{
    return s1.size() <= s2.size() ? s1 : s2;
}

std::string &shorterString(std::string &s1, std::string &s2)
{
    auto &r = shorterString(const_cast<const std::string &>(s1),
                            const_cast<const std::string &>(s2));
    return const_cast<std::string &>(r);
}

// 6.39.a
int calc(int, int);
// 与第一项不同，传入参数必须是常量引用
int calc(const int, const int);

// 6.39.b
int get();
// 变量不同，不构成引用
double get();

int *reset(int *);
// 返回单位不同
// double *reset(double *);
// 构成重载
int *reset(double *);