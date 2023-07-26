/**
 * @file Screen.h
 * @author anufether (anufether@sina.com)
 * @brief 练习7.23、7.24
 * @date 2023-07-26
 *
 */

#include <string>
#include <iostream>

// extern std::ostream &storeOn(std::ostream &, Screen &);
class Screen
{
public:
    typedef std::string::size_type pos;
    Screen() = default;
    Screen(pos ht = 0, pos wd = 0) : height(ht), width(wd), contents(ht * wd, ' ') {}
    // cursor被其类内初始化为0
    friend class Window_mgr;
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}
    inline char get(pos ht, pos wd) const; // 显示内联
    Screen &move(pos r, pos c);            // 能在之后被设置为内联
    void some_member() const;
    Screen &set(char);
    Screen &set(pos, pos, char);
    Screen &display(std::ostream &os)
    {
        do_display(os);
        return *this;
    }
    const Screen &display(std::ostream &os) const
    {
        do_display(os);
        return *this;
    }
    pos size() const
    {
        return height * width;
    }

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
    mutable size_t access_ctr; // 即使在一个const对象内也能被修改
    void do_display(std::ostream &os) const
    {
        os << contents;
    }
};

void Screen::some_member() const
{
    ++access_ctr; // 保存一个计数值，用于记录成员函数被调用的次数
}

char Screen::get(pos r, pos c) const // 在类的内部声明成inline
{
    pos row = r * width;      // 计算行的位置
    return contents[row + c]; // 返回给定列的字符
}

inline Screen &Screen::move(pos r, pos c)
{
    pos row = r * width; // 计算行的位置
    cursor = row + c;    // 在行内将光标移动到指定的列
    return *this;        // 以左值的形式返回对象
}

inline Screen &Screen::set(char c)
{
    contents[cursor] = c; // set the new value at the current cursor location
    return *this;         // return this object as an lvalue
}
inline Screen &Screen::set(pos r, pos col, char ch)
{
    contents[r * width + col] = ch; // set specified location to given value
    return *this;                   // return this object as an lvalue
}