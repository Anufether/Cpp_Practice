/**
 * @file Screen_data
 * @author anufether (anufether@sina.com)
 * @brief 测试类,练习7.27
 * @date 2023-07-26
 *
 */

#include <iostream>
#include "Screen.h"

int main()
{
    // Screen myScreen(5, 3);
    // const Screen blank(5, 3);
    // myScreen.set('#').display(std::cout);
    // blank.display(std::cout);

    Screen myScreen(5, 5, 'X');
    myScreen.move(4, 0).set('#').display(std::cout);
    std::cout << myScreen.size() << std::endl;
}