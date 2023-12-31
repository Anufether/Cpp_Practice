/**
 * @file Person.h
 * @author anufether (anufether@sina.com)
 * @brief 练习ren类的书写
 * @date 2023-07-25
 *
 * @question 练习7.19：在你的Person类中，你将把那些成员声明称public，那些声明称private，解释原因
 * @answer 类的成员，声明为private，访问方法声明称public
 */
#ifndef PERSON_H
#define PERSON_H

#include <string>

struct Person
{

    friend Person add(const Person &, const Person &);
    friend std::ostream &print(std::ostream &, const Person &);
    friend std::istream &read(std::istream &, Person &);

public:
    Person() = default;
    Person(const std::string &n, std::string &a) : name(n), address(a){};
    Person(std::istream &is)
    {
        read(is, *this);
    }

    /**
     * @brief Get the Name object
     *
     * @return std::string
     */
    std::string getName() const
    {
        return this->name;
    }

    /**
     * @brief Get the Address object
     *
     * @return std::string
     */
    std::string getAddress() const
    {
        return this->address;
    }

private:
    /**
     * @brief 姓名
     *
     */
    std::string name;

    /**
     * @brief 住址
     *
     */
    std::string address;
};

// Person的非成员接口函数

#endif