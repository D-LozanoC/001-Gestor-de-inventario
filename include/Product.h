#pragma once
#include <string>
#include <ostream>

class Product
{
public:
    // Constructor
    Product(int id, const std::string &name, const std::string &category, unsigned int quantity, double price);

    // Getters
    int getId() const;
    const std::string &getName() const;
    const std::string &getCategory() const;
    unsigned int getQuantity() const;
    double getPrice() const;
    // Setters
    void setName(const std::string &n);
    void setCategory(const std::string &c);
    void setQuantity(unsigned int q);
    void setPrice(double p);
    // Printer
    friend std::ostream &operator<<(std::ostream &os, const Product &p);

private:
    int id;
    std::string name;
    std::string category;
    unsigned int quantity;
    double price;
};