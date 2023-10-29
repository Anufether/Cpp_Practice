/**
 * @file function_assert_ndebug.cc
 * @author anufether (anufether@sina.com)
 * @brief assert预处理宏，ndebug预处理变量
 * @date 2023-10-28
 * __FILE__存放文件名的字符串字面值
 * __LINE__存放当前行号的整形字面值
 * __TIME__存放文件编译时间的字符床字面值
 * __DATE__存放文件编译日期的字符串字面值
 */
#include <iostream>
#include <cassert>
#include <vector>

void print(const int ia[], size_t size)
{
#ifndef NDEBUG
    std::cerr << __func__ << ": array size is" << size << std::endl;
#endif
}

void recursiveVectorOutput(const std::vector<int> &vec, size_t index)
{
    if (index >= vec.size())
    {
        return;
    }
    // 输出当前递归情况
    std::cout << vec[index] << " " << std::endl;

#ifndef NDEBUG
    std::cerr << __func__ << ": array size is " << vec.size() << std::endl;
    std::cerr << "array file literal is " << __FILE__ << std::endl;
    std::cerr << "array line is " << __LINE__ << std::endl;
    std::cerr << "array compile time is " << __TIME__ << std::endl;
    std::cerr << "array date is" << __DATE__ << std::endl;
#endif

    recursiveVectorOutput(vec, index + 1);
}

int main()
{
    std::vector<int> myVector = {1, 2, 3, 4, 5};
    recursiveVectorOutput(myVector, 0);
    std::cout << std::endl;

    std::string s;
    while (std::cin >> s && s != "test")
    {
    }
    // assert用于检查永远不会出现的条件，这里的检查合理，但是不合适。
    // 若cin错误，我们应该抛出异常而不是程序出错
    assert(std::cin);

    return 0;
}