#include "warehouse.hpp"
#include "product.hpp"

void Warehouse::increaseAmount(const std::string &name, const uint amount)
{
    for (auto &el : products_)
    {
        if (el->getName() == name)
        {
            el->increaseAmount(amount);
        }
    }
}

void Warehouse::decreaseAmount(const std::string &name, uint amount)
{
    for (auto &el : products_)
    {
        if (el->getName() == name)
        {
            el->decreaseAmount(amount);
        }
    }
}

void Warehouse::addProducts(const std::vector<std::shared_ptr<Product>> products)
{
    for (const auto &product : products)
    {
        if (std::ranges::all_of(products_, [&](const auto &el) { return el->getName() != product->getName(); }))
        {
            products_.push_back(product);
        }
    }
}

bool Warehouse::validateAdd(const std::string &name)
{
    return std::ranges::any_of(products_, [&](const auto &el) { return el->getName() == name; });
}

void Warehouse::removeProducts(const std::vector<std::shared_ptr<Product>> &products)
{
    for (const auto &product : products)
    {
        for (auto it = begin(products_); it != end(products_); it++)
        {
            if ((*it)->getName() == product->getName())
            {
                products_.erase(it);
            }
        }
    }
}

bool Warehouse::validateRemoval(const std::string &name)
{
    return std::ranges::all_of(products_, [&](const auto &el) { return el->getName() != name; });
}

std::shared_ptr<Product> Warehouse::getPtrToProduct(std::string name)
{
    for (const auto &product_ : products_)
    {
        if (product_->getName() == name)
        {
            return product_;
        }
    }
    return nullptr;
}

std::vector<std::shared_ptr<Product>> Warehouse::getExpiredProducts()
{
    std::vector<std::shared_ptr<Product>> ret;
    // TODO: write this function when type Date will be created
    return ret;
}

std::vector<std::shared_ptr<Product>> &Warehouse::getProducts()
{
    return products_;
}
