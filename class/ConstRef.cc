/**
 * @file ConstRef.cc
 * @author anufether (anufether@sina.com)
 * @brief 7.5节实现
 * @date 2023-07-27
 *
 */

#include <iostream>

class ConstRef
{
public:
    ConstRef(int ii) : i(ii), ci(ii), ri(i) {}

    void printValues() const
    {
        std::cout << "i: " << i << ", ci: " << ci << ", ri: " << ri << std::endl;
    }

private:
    int i;
    const int ci;
    int &ri;
};

int main()
{
    int value = 42;
    ConstRef obj(value);

    obj.printValues();

    return 0;
}
