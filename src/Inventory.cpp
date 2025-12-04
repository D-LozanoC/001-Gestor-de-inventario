#include <iostream>
#include "Inventory.h"

using std::string;

// CRUD

bool Inventory::add(const Product &p)
{
    if (i.count(p.getId()))
        return false;
    i.insert({p.getId(), p});
    return true;
}

bool Inventory::remove(int id) { return i.erase(id) > 0; }

bool Inventory::update(
    int id,
    const std::optional<std::string> &name,
    const std::optional<std::string> &category,
    const std::optional<unsigned int> &quantity,
    const std::optional<double> &price)
{
    auto it = i.find(id);
    if (it == i.end())
        return false;

    if (name)
        it->second.setName(*name);
    if (category)
        it->second.setCategory(*category);
    if (quantity)
        it->second.setQuantity(*quantity);
    if (price)
        it->second.setPrice(*price);

    return true;
}

const Product *Inventory::find(int id) const
{
    auto it = i.find(id);
    return it != i.end() ? &it->second : nullptr;
}

const std::map<int, Product> &Inventory::list() const { return i; }

// Files

bool Inventory::loadFromFile(const std::string &name)
{
}
bool Inventory::saveToFile(const std::string &name)
{
}