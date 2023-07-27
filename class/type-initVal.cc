/**
 * @file type-initVal.cc
 * @author anufether (anufether@sina.com)
 * @brief 练习7.35：修改代码错误
 * @date 2023-07-27
 *
 */
#include <iostream>
#include <string>

typedef std::string Type;
Type initVal();
class Exercise
{
public:
    typedef double Type;
    Type setVal(Type);
    Type initVal();

private:
    int val;
};

// 添加了Exercise
Exercise::Type Exercise::setVal(Type parm)
{
    val = parm + initVal();
    return val;
}