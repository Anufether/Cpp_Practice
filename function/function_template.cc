/**
 * @file function_template.cc
 * @author anufether (anufether@sina.com)
 * @brief 练习6.5实例
 * @date 2023-09-24
 * 
 */
#include <iostream>

using namespace std;

template <typename T>
T absoluteValue(T value)
{
    if (value < 0)
    {
        return -value;
    }
    return value;
}

int main()
{
    int intValue = -5;
    double doubleValue = -3.14;

    // 使用泛型函数获取绝对值
    int absIntValue = absoluteValue(intValue);
    double absDoubleValue = absoluteValue(doubleValue);

    cout << "Int型：" << absIntValue << endl;
    cout << "Double型：" << absDoubleValue << endl;

    return 0;
}