/**
 * @file function_main.cc
 * @author anufether (anufether@sina.com)
 * @brief
 * @date 2023-09-26
 * 6.2.5节练习
 */
#include <iostream>

int main(int argc, char *argv[])
{
    std::cout << "Number of command-line arguments: " << argc << std::endl;

    // 使用循环打印所有命令行参数
    for (int i = 0; i < argc; ++i)
    {
        std::cout << "Argument " << i << ": " << argv[i] << std::endl;
    }

    return 0;
}