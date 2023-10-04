/**
 * @file function_return.cc
 * @author anufether (anufether@sina.com)
 * @brief
 * @date 2023-09-27
 * 6.3
 */
#include <string>
#include <iostream>

using namespace std;

// bool str_subrange(const string &str1, const string &str2)
// {
//     // 大小相同：此时用普通的相等性判断结果作为返回值
//     if (str1.size() == str2.size())
//     {
//         return str1 == str2;
//     }

//     auto size = (str.size() < str2.size()) ? str1.size() : str2.size();
//     // 检查两个string对象的对应字符是否相等，以较短的字符串长度为限
//     for (decltype(size) i = 0; i < size; i++)
//     {
//         if (str1[i] != str2[i])
//         {
//             return; // 错误 #1：没有返回值，编辑器将报告这一错误
//             // 错误 #2：控制流可能尚未返回任何值就结束了函数的执行
//             // 编辑器可能检查不出这一错误
//         }
//     }
// }

string make_plural(size_t ctr, const string &word, const string &ending)
{
    return (ctr > 1) ? word + ending : word;
}

const string &shorterString(const string &s1, const string &s2)
{
    return s1.size() <= s2.size() ? s1 : s2;
}