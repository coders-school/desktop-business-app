#include "warehouse.hpp"
#include "product.hpp"

void Warehouse::increaseAmount(const std::shared_ptr<Product>& ptrToProduct, const uint amount)
{
    for (auto& product_ : products_)
    {
        if (product_ == ptrToProduct)
        {
            product_->increaseAmount(amount);
        }
    }
}

void Warehouse::decreaseAmount(const std::shared_ptr<Product>& ptrToProduct, uint amount)
{
    for (auto& product_ : products_)
    {
        if (product_ == ptrToProduct)
        {
            if (amount > product_->getAmount())
            {
                product_->setAmount(0);
                return;
            }
            else
                product_->decreaseAmount(amount);
        }
    }
}

void Warehouse::addProducts(const std::vector<std::shared_ptr<Product>>& products)
{
    for (const auto& product : products)
    {
        if (std::ranges::none_of(products_, [&](const auto& ptrToProduct) { return ptrToProduct == product; }))
        {
            products_.insert(product);
        }
    }
}

void Warehouse::removeProducts(const std::vector<std::shared_ptr<Product>>& products)
{
    for (const auto& product : products)
    {
        for (auto it = begin(products_); it != end(products_); it++)
        {
            if (*it == product)
            {
                products_.erase(it);
                break;
            }
        }
    }
}

std::vector<std::shared_ptr<Product>> Warehouse::getPtrsToProducts(const std::string& name)
{
    std::vector<std::shared_ptr<Product>> ret;
    for (const auto& product_ : products_)
    {
        if (product_->getName() == name)
        {
            ret.emplace_back(product_);
        }
    }
    return ret;
}

std::set<std::shared_ptr<Product>>& Warehouse::getProducts()
{
    return products_;
}
