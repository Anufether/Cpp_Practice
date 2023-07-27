/**
 * @file Screen_temp1.h
 * @author anufether (anufether@sina.com)
 * @brief 7.4.1节练习、实现
 * @date 2023-07-27
 *
 */
#include <iostream>

int height; // 定义了一个明治，稍后将在Screen中使用
class Screen
{
public:
    typedef std::string::size_type pos;
    Screen(pos ht, pos wd) : height(ht), width(wd) {}
    // void setHeight(pos);
    // pos height = 0; // 隐藏了外层作用域中的height
    void dummy_fun(pos height)
    {
        cursor = width * height;
    }

private:
    pos cursor = 0;
    pos height = 0, width = 0;
};

// Screen::pos verify(Screen::pos);
// void Screen::setHeight(pos var)
// {
//     // var:参数
//     // height:类的成员
//     // verify:全局函数
//     height = verify(var);
// }