/**
 * @file Window_mgr.cc
 * @author anufether (anufether@sina.com)
 * @brief 练习7.25
 * @date 2023-07-26
 *
 * @answer 不能安全的依赖于拷贝和赋值操作的默认版本，因为不同的显示器需要适配相应的版本，否则容易不适配
 */

#include <vector>
#include "Screen.h"

class Window_mgr
{
public:
    // 窗口中每个屏幕的编号
    using ScreenIndex = std::vector<Screen>::size_type;
    // 按照编号将指定的Screen重置为空白
    void clear(ScreenIndex);

private:
    std::vector<Screen> screens{
        // 默认情况下， 一个Window_mgr包含一个标准尺寸的空白Screen
        Screen(24, 80, ' ')};
};

void Window_mgr::clear(ScreenIndex i)
{
    // s时一个Screen的引用，指向我们想清空的那个屏幕
    Screen &s = screens[i];
    // 将那个选定的Screen重置为空白
    s.contents = std::string(s.height * s.width, ' ');
}