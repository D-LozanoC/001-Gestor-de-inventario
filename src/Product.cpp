#include <iomanip>
#include <iostream>
#include "Product.h"

using std::string;
using std::setw;

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
    const string cyan = "\033[36m";
    const string reset = "\033[0m";

    os << cyan << "| " << reset << std::left
       << setw(5) << p.id << cyan << " | " << reset
       << setw(18) << p.name << cyan << " | " << reset
       << setw(13) << p.category << cyan << " | " << reset
       << setw(8) << p.quantity << cyan << " | " << reset
       << setw(8) << p.price << cyan << " |" << reset;

    return os;
}
