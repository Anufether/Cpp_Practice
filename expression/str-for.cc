/**
 * @file str-for.cc
 * @author anufether (anufether@sina.com)
 * @brief for循环中的引用
 * @date 2023-07-21
 *
 */
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<string> text{"hello world."};
    for (const auto &s : text)
    {
        cout << s;
        if (s.empty() || s[s.size() - 1] == ' ')
        {
            cout << endl;
        }
        else
        {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}