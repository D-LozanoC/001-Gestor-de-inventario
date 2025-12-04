#pragma once
#include "Product.h"
#include <map>
#include <optional>

class Inventory
{
private:
    std::map<int, Product> i;

public:
    // CRUD
    bool add(const Product &p);
    bool remove(int id);
    bool update(
        int id,
        const std::optional<std::string> &name,
        const std::optional<std::string> &category,
        const std::optional<unsigned int> &quantity,
        const std::optional<double> &price);
    const Product *find(int id) const;
    const std::map<int, Product> &list() const;
    // Files
    bool loadFromFile(const std::string &name);
    bool saveToFile(const std::string &name);
};