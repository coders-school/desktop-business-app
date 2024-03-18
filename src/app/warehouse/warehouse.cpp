#include "warehouse.hpp"
#include "product.hpp"

void Warehouse::increaseAmount(const std::string &name, const uint amount)
{
    for (auto &el : products_)
    {
        if (el.getName() == name)
        {
            el.increaseAmount(amount);
        }
    }
}

void Warehouse::decreaseAmount(const std::string &name, uint amount)
{
    for (auto &el : products_)
    {
        if (el.getName() == name)
        {
            el.decreaseAmount(amount);
        }
    }
}

void Warehouse::addProducts(const std::vector<Product> &products)
{
    for (const auto &product : products)
    {
        if (std::ranges::all_of(products_, [&](const auto &el) { return el.getName() != product.getName(); }))
        {
            products_.emplace_back(product);
        }
    }
}

bool Warehouse::validateAdd(const std::string &name)
{
    return std::ranges::any_of(products_, [&](const auto &el) { return el.getName() == name; });
}

void Warehouse::removeProducts(const std::vector<Product> &products)
{
    for (const auto &product : products)
    {
        for (auto it = begin(products_); it != end(products_); it++)
        {
            if (it->getName() == product.getName())
            {
                products_.erase(it);
            }
        }
    }
}

bool Warehouse::validateRemoval(const std::string &name)
{
    return std::ranges::all_of(products_, [&](const auto &el) { return el.getName() != name; });
}

std::vector<Product> Warehouse::getExpiredProducts()
{
    std::vector<Product> ret;
    // TODO: write this function when type Date will be created
    return ret;
}

std::vector<Product> &Warehouse::getProducts()
{
    return products_;
}
