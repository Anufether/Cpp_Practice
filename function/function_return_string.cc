/**
 * @file function_return_string.cc
 * @author anufether (anufether@sina.com)
 * @brief 练习6.2（a）修改实例
 * @date 2023-09-24
 * 
 */
#include <iostream>
#include <string>

using namespace std;

string getString()
{
    string myString = "这是一个字符串类型";
    return myString;
}

int main()
{
    string result = getString();

    cout << result << endl;

    return 0;
}