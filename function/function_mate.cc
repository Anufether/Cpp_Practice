/**
 * @file function_mate.cc
 * @author anufether (anufether@sina.com)
 * @brief 6.6节练习，函数匹配
 * @date 2023-10-29
 *
 */
#include <iostream>

// Function to print a message for null parameters
void f()
{
    std::cout << __func__ << " - parameters for null" << std::endl;
}

// Function to print a message for an integer parameter
void f(int index)
{
    std::cout << __func__ << " - parameters for " << index << std::endl;
}

// Function with default parameters for two integers
void f(int param1, int param2)
{
    std::cout << __func__ << " - parameters: " << param1 << " " << param2 << std::endl;
}

// Function with default parameters for two doubles
void f(double param1, double param2 = 3.14)
{
    std::cout << __func__ << " - parameters: " << param1 << " " << param2 << std::endl;
}

int calc(int &, int &);
int calc(const int &, const int &);

int calc(char *, char *);
int calc(const char *, const char *);

int calc(const char *, char *const);

int main()
{
    f(42, 0);
    f(42);
    f(2.56, 3.14);
    // 错误调用：不能区分void f(int param1, int param2)与void f(double param1, double param2 = 3.14)
    // f(2.54, 42);
    f();

    return 0;
}