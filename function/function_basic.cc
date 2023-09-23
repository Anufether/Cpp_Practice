#include <iostream>

using namespace std;

// 计算阶乘函数
int fact(int val)
{
    int ret = 1;
    while (val > 1)
    {
        ret *= val--;
    }
    return ret;
}

int main()
{
    int j = fact(5);
    cout << "5! is " << j << endl;
    return 0;
}