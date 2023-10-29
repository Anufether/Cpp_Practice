/**
 * @file function_pointer_practice.cc
 * @author anufether (anufether@sina.com)
 * @brief 6.7节练习
 * @date 2023-10-29
 *
 */
#include <iostream>
#include <vector>

int fun_add(int a, int b)
{
    return a + b;
}

int fun_sub(int a, int b)
{
    return a - b;
}

int fun_mul(int a, int b)
{
    return a * b;
}

int fun_div(int a, int b)
{
    return a / b;
}

int (*func_vec_temp)(int, int);

// std::vector<int (*)(int, int)> Func_vec()

// std::vector<decltype(func_vec_temp)> Func_vec()

// using PF = int (*)(int, int);
// std::vector<PF> Func_vec()

auto Func_vec() -> std::vector<int (*)(int, int)>
{
    std::vector<int (*)(int, int)> functionPointers;
    functionPointers.push_back(fun_add);
    functionPointers.push_back(fun_sub);
    functionPointers.push_back(fun_mul);
    functionPointers.push_back(fun_div);

    return functionPointers;
}

int main()
{
    std::vector<int (*)(int, int)> myFuncs = Func_vec();

    std::cout << "Result: "
              << myFuncs[0](10, 20) << " "
              << myFuncs[1](10, 20) << " "
              << myFuncs[2](10, 20) << " "
              << myFuncs[3](10, 20) << std::endl;

    return 0;
}
