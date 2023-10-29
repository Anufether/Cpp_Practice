/**
 * @file function_pointer.cc
 * @author anufether (anufether@sina.com)
 * @brief 6.7节函数指针
 * @date 2023-10-29
 *
 */
#include <iostream>
#include <cstring>

// 比较两个string对象的长度
bool lengthCompare(const std::string &, const std::string &);

// pf指向一个函数，该函数的参数是两个const string的引用，返回值是bool类型
bool (*pf)(const std::string &, const std::string &);

// *pf两端的括号必不可少，若没有则返回的是bool指针的函数，而不是函数指针

std::string::size_type sumLength(const std::string &, const std::string &);

bool cstringCompare(const char *, const char *);

void useBigger(const std::string &s1, const std::string &s2,
               bool pf(const std::string &, const std::string &));

// Func和Func2是函数类型
typedef bool Func(const std::string &, const std::string &);
typedef decltype(lengthCompare) Func2; // 等价的类型

// FuncP和FuncP2是指向函数的指针
typedef bool (*FuncP)(const std::string &, const std::string &);
typedef decltype(lengthCompare) *FuncP2; // 等价的类型

// 等价声明,编译器会自动将Func表示的函数类型转化为指针
void useBigger(const std::string &s1, const std::string &s2, Func);
void useBigger(const std::string &s1, const std::string &s2, FuncP2);

// 返回指向函数的指针
using F = int(int *, int);      // F是函数类型，不是指针
using PF = int (*)(int *, int); // PF是指针类型

// 定义函数
PF f1(int); // 正确：PF是指向函数的指针，f1返回指向函数的指针
// F f1(int);  // 错误：F是函数类型，f1不能返回一个函数
F *f1(int); // 正确：显式的指定返回类型是指向函数的指针

// 当然，我们也能直接声明f1
int (*f1(int))(int *, int);
// 也可以使用尾置返回类型
auto f1(int) -> int (*)(int *, int);

// 将auto、decltype用于函数指针
decltype(sumLength) *getFcn(const std::string &);

int main()
{
    pf = lengthCompare;               // 函数和指针的类型精确匹配
    bool b1 = pf("hello", "goodbye"); // 调用lengthCompare函数
    std::cout << b1 << std::endl;
    bool b2 = (*pf)("hello", "goodbye"); // 一个等价的调用
    std::cout << b2 << std::endl;
    bool b3 = lengthCompare("hello", "goodbye"); // 另一个等价的调用
    std::cout << b3 << std::endl;

    pf = 0;
    // pf = sumLength; // 返回类型不匹配
    // pf = cstringCompare; // 形参类型不匹配

    ///////////////////////////////////////

    // 函数指针形参
    useBigger("hello", "goodbye", lengthCompare);

    return 0;
}

bool lengthCompare(const std::string &str1, const std::string &str2)
{
    return str1.length() > str2.length();
}
std::string::size_type sumLength(const std::string &str1, const std::string &str2)
{
    return str1.length() + str2.length();
}
bool cstringCompare(const char *str1, const char *str2)
{
    // 使用strcmp函数比较两个C风格字符串
    return std::strcmp(str1, str2) == 0;
}
void useBigger(const std::string &s1, const std::string &s2,
               bool (*pf)(const std::string &, const std::string &))
{
    if (pf(s1, s2))
    {
        std::cout << "s1 is bigger." << std::endl;
    }
    else
    {
        std::cout << "s2 is bigger." << std::endl;
    }
}