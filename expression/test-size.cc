/**
 * @file test-size.cc
 * @author anufether (anufether@sina.com)
 * @brief 书写一个表达式用于测试4个值a、b、c、d的关系，确保a大于b、b大于c、c大于d
 * @date 2023-07-21
 *
 */
#include <iostream>

int main()
{
    int a, b, c, d;
    char continueInput;

    do
    {
        // 从用户输入获取a、b、c、d的值
        std::cout << "请输入a的值：";
        std::cin >> a;

        std::cout << "请输入b的值：";
        std::cin >> b;

        std::cout << "请输入c的值：";
        std::cin >> c;

        std::cout << "请输入d的值：";
        std::cin >> d;

        // 检查条件是否满足
        if (a > b && b > c && c > d)
        {
            std::cout << "a > b > c > d 条件成立！" << std::endl;
        }
        else
        {
            std::cout << "a > b > c > d 条件不成立！" << std::endl;
        }

        // 询问是否继续输入
        std::cout << "是否继续输入？(输入 'y' 继续，其他键退出): ";
        std::cin >> continueInput;
    } while (continueInput == 'y' || continueInput == 'Y');

    return 0;
}