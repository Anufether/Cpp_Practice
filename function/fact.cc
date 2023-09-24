#include "Chapter6.h"
#include <iostream>

using namespace std;

string f()
{
    string myString = "这是一个字符串类型";
    return myString;
}

void f2(int i)
{
    cout << "我是函数体f2" << endl;
}

int calc(int v1, int v2)
{
    cout << "v1 + v2 = " << v1 + v2 << endl;
    return v1 + v2;
}

double square(double x)
{
    return x * x;
}