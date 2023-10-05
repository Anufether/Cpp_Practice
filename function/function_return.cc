/**
 * @file function_return.cc
 * @author anufether (anufether@sina.com)
 * @brief
 * @date 2023-09-27
 * 6.30：以报错
 * 6.31：引用局部变量时，引用会无效；局部常量
 * 6.32：index是局部变量，其返回是无效的
 */
#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

// bool str_subrange(const string &str1, const string &str2)
// {
//     // 大小相同：此时用普通的相等性判断结果作为返回值
//     if (str1.size() == str2.size())
//     {
//         return str1 == str2;
//     }

//     auto size = (str1.size() < str2.size()) ? str1.size() : str2.size();
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

// 严重错误：这个函数试图返回局部对象的引用
// const string &manip()
// {
//     string ret;
//     if (!ret.empty())
//         return ret; // 错误：返回局部对象的引用！
//     else
//         return "Empty"; // 错误：“Empty”是一个局部临时变量！
// }

// 返回值是左值
char &get_val(string &str, string::size_type ix)
{
    return str[ix]; // get_val假定索引值是有效的
}

vector<string> process()
{
    string expected;
    string actual;
    // expected和actual是string对象
    if (expected.empty())
    {
        return {};
    }
    else if (expected == actual)
    {
        return {"functionX", "okay"};
    }
    else
    {
        return {"functionX", expected, actual};
    }
}

/**
 * @brief 6.34，当输入的数小于0时，会无限递归下去，直到超出界定的内存
 * 报错
 * 6.35：我们返回时使用的时(val - 1)* val,val--在运算前已经完成，既
 * 修改变量和读取变量在同一条表达式中，报错Segmentation fault
 * @param val
 * @return int
 */
int factorial(int val)
{
    // if (val != 0)
    if (val > 1)
    {
        return factorial(val - 1) * val;
    }
    return 1;
}

// 6.32
// int &get(int &arry, int index)
// {
//     return arry[index];
// }

// 6.33
void print(vector<int> ivec, size_t index)
{
    if (index < ivec.size())
    {
        cout << ivec[index] << endl;
        print(ivec, index + 1);
    }
    else
    {
        cout << endl;
    }
}

int main()
{
    // cout << manip() << endl;
    string s("a value"); // 输出a value
    cout << s << endl;   // 将s[0]的值改为A
    get_val(s, 0) = 'A'; // 输出A value
    cout << s << endl;

    cout << factorial(5) << endl;

    vector<int> ivec = {1, 2, 3, 4, 5};
    print(ivec, 0);

    return 0;
}