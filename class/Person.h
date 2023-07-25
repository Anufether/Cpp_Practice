/**
 * @file Person.h
 * @author anufether (anufether@sina.com)
 * @brief 
 * @date 2023-07-25
 * 
 */
#include <string>


struct Person
{
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
