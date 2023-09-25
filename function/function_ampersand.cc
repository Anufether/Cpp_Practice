/**
 * @file function_ampersand.cc
 * @author anufether (anufether@sina.com)
 * @brief 6.2.2传引用参数
 * @date 2023-09-24
 * 练习6.11，本文件就是，懒得写了
 * 练习6.12，见function_ampersand_tran.cc
 * 练习6.15，-不使用就会报错呀-；occurs需要修改并返回，而s不能被修改。
 * 虽然删除const后结果相同，但是我们需要确保s字符串不能被修改，即保证结果的稳定。
 * occurs是常量引用时会报错。。常量不可被修改
 * 
 * 练习6.16：未使用const，编译容易报错，且调用对象容易与const对象不匹配报错
 */
#include <iostream>
#include <string>

// void reset(int &i)
// {
//     i = 1;
// }

// void reset_test(int i)
// {
//     i = 1;
// }

std::string::size_type find_char(const std::string &s, char c, std::string::size_type &occurs)
{
    auto ret = s.size(); // 第一次出现的位置
    occurs = 0;
    for (decltype(ret) i = 0; i != s.size(); i++)
    {
        if (s[i] == c)
        {
            if (ret == s.size())
                ret = i + 1;
            ++occurs;
        }
    }
    return ret;
}

int main()
{
    // int a = 3;
    // reset_test(a);
    // std::cout << a << std::endl;
    // reset(a);
    // std::cout << a << std::endl;

    std::string s = "12cccc4j1ofca";
    char a = 'c';
    std::string::size_type occurs = 0;
    std::cout << find_char(s, a, occurs) << " " << occurs << std::endl;

    return 0;
}