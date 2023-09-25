/**
 * @file function_compare.cc
 * @author anufether (anufether@sina.com)
 * @brief 练习6.18，将包含两个方法的实现
 * @date 2023-09-25
 *
 */
#include "Matrix.hpp"
#include <iostream>

int main()
{
    // 创建一个3x3的矩阵对象
    Matrix myMatrix(3, 3);

    // 设置矩阵中的元素值
    myMatrix.set(0, 0, 1.0);
    myMatrix.set(0, 1, 2.0);
    myMatrix.set(0, 2, 3.0);
    myMatrix.set(1, 0, 4.0);
    myMatrix.set(1, 1, 5.0);
    myMatrix.set(1, 2, 6.0);
    myMatrix.set(2, 0, 7.0);
    myMatrix.set(2, 1, 8.0);
    myMatrix.set(2, 2, 9.0);

    // 打印矩阵
    std::cout << "Matrix myMatrix:" << std::endl;
    myMatrix.print();

    // 替换矩阵中的值
    myMatrix.replaceValue(1, 1, 42.0);

    // 再次打印矩阵，检查替换是否生效
    std::cout << "Matrix myMatrix after replacement:" << std::endl;
    myMatrix.print();
    myMatrix.replaceValue(1, 1, 5.0);

    // 新增一个矩阵，将其打印、比较
    // 创建一个3x3的矩阵对象
    Matrix myMatrix1(3, 3);

    // 设置矩阵中的元素值
    myMatrix1.set(0, 0, 1.0);
    myMatrix1.set(0, 1, 2.0);
    myMatrix1.set(0, 2, 3.0);
    myMatrix1.set(1, 0, 4.0);
    myMatrix1.set(1, 1, 5.0);
    myMatrix1.set(1, 2, 6.0);
    myMatrix1.set(2, 0, 7.0);
    myMatrix1.set(2, 1, 8.0);
    myMatrix1.set(2, 2, 9.0);

    std::cout << "Add Matrix:" << std::endl;
    myMatrix1.print();

    if (myMatrix == myMatrix1)
    {
        std::cout << "两个矩阵相等" << std::endl;
    }
    else
    {
        std::cout << "两个矩阵不相等" << std::endl;
    }

    std::cout << "修改myMatrix1,修改第二行的数据" << std::endl;
    int rowToChange = 1;
    std::vector<double> newValue = {32.0, 4.0, 1.4};

    // 调用change_val函数并获取返回的迭代器
    std::vector<double>::iterator it = myMatrix1.change_val(rowToChange, newValue);
    // 打印修改后的函数
    myMatrix1.print();

    return 0;
}