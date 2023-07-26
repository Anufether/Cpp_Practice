/**
 * @file Screen_temp.h
 * @author anufether (anufether@sina.com)
 * @brief 这里时Screen类修改过引用后的版本
 * @date 2023-07-26
 *
 */

#include <string>
#include <iostream>

class Screen
{
public:
    typedef std::string::size_type pos;

    Screen() = default;
    Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') {}
    Screen(pos ht, pos wd, char ch) : height(ht), width(wd), contents(ht * wd, ch) {}

    // 获取光标
    char get() const { return contents[cursor]; }
    char get(pos ht, pos wd) const { return contents[ht * width + wd]; }
    // 移动光标
    Screen move(pos ht, pos wd)
    {
        cursor = ht * width + wd;
        return *this;
    }
    // 输入
    Screen set(char);
    Screen set(pos, pos, char);
    // 显示
    Screen display(std::ostream &os)
    {
        do_display(os);
        return *this;
    }
    const Screen display(std::ostream &os) const
    {
        do_display(os);
        return *this;
    }

private:
    void do_display(std::ostream &os) const;
    // 光标
    pos cursor = 0;
    // 高
    pos height = 0;
    // 宽
    pos width = 0;
    // 内容
    std::string contents;
};

inline Screen Screen::set(char ch)
{
    contents[cursor] = ch;
    return *this;
}

inline Screen Screen::set(pos ht, pos wd, char ch)
{
    contents[ht * width + wd] = ch;
    return *this;
}

inline void Screen::do_display(std::ostream &os) const
{
    for (pos i = 0; i != contents.size(); ++i)
    {
        os << contents[i];
        if (i % width == width - 1)
            os << std::endl;
    }
}
