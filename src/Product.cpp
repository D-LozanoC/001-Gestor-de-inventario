#include <iostream>
#include "Product.h"

using std::string;

// Constructor

Product::Product(int id, const string &name, const string &category, unsigned int quantity, double price)
    : id(id), name(name), category(category), quantity(quantity), price(price) {}

// Getters

int Product::getId() const { return id; }
const string &Product::getName() const { return name; }
const string &Product::getCategory() const { return category; }
unsigned int Product::getQuantity() const { return quantity; }
double Product::getPrice() const { return price; }

// Setters

void Product::setName(const string &n) { name = n; }
void Product::setCategory(const string &c) { category = c; }
void Product::setQuantity(unsigned int q) { quantity = q; }
void Product::setPrice(double p) { price = p; }

// Printer

std::ostream &operator<<(std::ostream &os, const Product &p)
{
    os << "Product {\n"
       << "    Id: " << p.id << '\n'
       << "    Name: " << p.name << '\n'
       << "    Category: " << p.category << '\n'
       << "    Quantity: " << p.quantity << '\n'
       << "    Price: " << p.price << '\n'
       << "}";

    return os;
}
