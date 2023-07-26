#include <iostream>
#include <string>

struct Sales_data {
    std::string bookNo;
    int units_sold;
    double revenue;

    Sales_data() : bookNo(""), units_sold(0), revenue(0.0) {}
    Sales_data(std::istream &is) : Sales_data() {
        read(is, *this);
    }

    // Member function to calculate the average price
    double average_price() const {
        return units_sold != 0 ? revenue / units_sold : 0;
    }
};

// Function to read data from the stream and fill the Sales_data object
std::istream &read(std::istream &is, Sales_data &item) {
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = item.units_sold * price;

    return is;
}

int main() {
    std::cout << "Enter book number, units sold, and price: ";
    Sales_data data(std::cin); // Calling the constructor with std::cin (input from the console)

    // Now you can use the data object as needed
    std::cout << "Book number: " << data.bookNo << std::endl;
    std::cout << "Units sold: " << data.units_sold << std::endl;
    std::cout << "Revenue: " << data.revenue << std::endl;
    std::cout << "Average price: " << data.average_price() << std::endl;

    return 0;
}
