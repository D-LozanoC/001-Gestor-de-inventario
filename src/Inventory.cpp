#include <iostream>
#include <fstream>
#include <sstream>
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

bool Inventory::loadFromFile(const std::string &path)
{
    std::ifstream file(path);
    if (!file.is_open())
        return false;

    std::map<int, Product> tmp;
    string line;
    while (std::getline(file, line))
    {
        if (line.empty())
            continue;

        std::stringstream ss(line);
        string idStr, nameStr, catStr, quaStr, priStr;

        if (!std::getline(ss, idStr, ','))
            continue;
        if (!std::getline(ss, nameStr, ','))
            continue;
        if (!std::getline(ss, catStr, ','))
            continue;
        if (!std::getline(ss, quaStr, ','))
            continue;
        if (!std::getline(ss, priStr))
            continue;

        int id;
        unsigned int quantity;
        double price;
        try
        {
            id = std::stoi(idStr);
            quantity = static_cast<unsigned int>(std::stoul(quaStr));
            price = std::stod(priStr);
        }
        catch (...)
        {
            return false;
        }

        if (tmp.count(id))
            return false;

        Product p(id, nameStr, catStr, quantity, price);
        tmp.insert({id, p});
    }

    i = std::move(tmp);
    return true;
}
bool Inventory::saveToFile(const std::string &path)
{
    std::ofstream file(path);
    if (!file.is_open())
        return false;

    for (auto &it : i)
    {
        file << it.second.getId() << ',' 
        << it.second.getName() << ',' 
        << it.second.getCategory() << ',' 
        << it.second.getQuantity() << ',' 
        << it.second.getPrice() << '\n';
    }

    return true;
}