/**
 * @file bitwise-operation.cc
 * @author anufether (anufether@sina.com)
 * @brief 位运算在c++中的应用.
 * @date 2023-07-21
 * @deprecated 位运算符(左结合律)
 * ~ 按位取反
 * & 按位与
 * | 按位或
 * ^ 按位异或
 * << 左移
 * >> 右移
 */

#include <iostream>

using namespace std;

int main()
{

    /**
     * @brief 这里使用unsigned long 是因为int类型只能确保占用16位,
     */
    unsigned long quiz1 = 0; // 我们吧这个值当成集合来用
    // unsigned int quiz1 = 0;

    /**
     * @brief quiz1所占位数
     *
     */
    cout << sizeof(quiz1) * 8 << endl;

    /**
     * @brief 使用左移运算符和一个unsigned long类型的整数字面值1
     * 就能得到一个表示学生27通过了测验的数值
     *
     */
    1UL << 27;

    /**
     * @brief 表示学生27通过了测试
     *
     */
    quiz1 |= 1UL << 27;

    /**
     * @brief 查询学生27是否通过了测验
     *
     */
    bool status = quiz1 & (1UL << 27);

    /**
     * @brief 查询学生27是否通过了测验
     *
     */
    cout << status << endl;

    /**
     * @brief 表示学生27没有通过测试
     *
     */
    quiz1 &= ~(1UL << 27);

    status = quiz1 & (1UL << 27);

    cout << status << endl;

    unsigned long ul1 = 3, ul2 = 7;

    cout << (ul1 & ul2) << (ul1 | ul2) << (ul1 && ul2) << (ul1 || ul2);

    return 0;
}