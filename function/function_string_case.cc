/**
 * @file function_string_case.cc
 * @author anufether (anufether@sina.com)
 * @brief 练习6.17，这里判断是否有大小写字面时使用的是常量，理由是使用常量
 * 更能保证代码的健壮性（const与普通的值传入均能通过）。大小写转换因为需要改变
 * 自然不适用const
 * @date 2023-09-24
 *
 */
#include <iostream>
#include <string>

using namespace std;

/**
 * @brief 判断字符串中是否有大写字母
 *
 * @param str
 * @return true
 * @return false
 */
bool is_uppercase_present(const string &str)
{
    for (decltype(str.size()) i = 0; i != str.size(); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            return true;
    }
    return false; // 循环结束后返回 false
}

void convert_upper_to_lower(string &str)
{
    for (char &ch : str)
    {
        if (ch >= 'A' && ch <= 'Z')
            ch = ch - 'A' + 'a';
    }
}

int main()
{
    string str = "Hello World!";
    cout << is_uppercase_present(str) << endl;
    convert_upper_to_lower(str);
    cout << str << endl;
    return 0;
}