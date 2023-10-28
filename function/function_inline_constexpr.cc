/**
 * @file function_inline_constexpr.cc
 * @author anufether (anufether@sina.com)
 * @brief 第6.5.2节，内联函数与constexpr函数
 * @date 2023-10-28
 *
 */

#include <iostream>
#include <string>

// 内联版本：寻找两个string对象中较短的那个
inline const std::string &
shortString(const std::string &s1, const std::string s2)
{
    return s1.size() <= s2.size() ? s1 : s2;
}

constexpr int new_sz()
{
    return 42;
}

constexpr int foo = new_sz();

// 练习6.43我会将其放在头文件内联函数通常会预先展开，方便调用
inline bool eq(const BigInt &, const BigInt &);

// 放在源文件，普通函数
void putValues(int *arr, int size);

// 练习6.44
inline bool
isShorter(const std::string &s1, const std::string &s2)
{
    return s1.size() < s2.size();
}

// 练习6.45，对于一个系统来说，根据调用频率来进行安排更为明智
// 练习6.46,s1,s2长度均已知，可以更改