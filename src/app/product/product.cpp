#include "product.hpp"

Product::Product(const std::string &name, const double price, const uint amount)
    : name_(name), price_(price), amount_(amount)
{
}

void Product::increaseAmount(uint amount)
{
    amount_ += amount;
}

void Product::decreaseAmount(uint amount)
{
    amount_ -= amount;
}

std::string_view Product::getName() const
{
    return name_;
}

double Product::getPrice() const
{
    return price_;
}

uint Product::getAmount() const
{
    return amount_;
}

void Product::setName(const std::string &name)
{
    name_ = name;
}

void Product::setPrice(const double price)
{
    price_ = price;
    if (price_ < 0)
    {
        price_ = 0;
    }
}

void Product::setAmount(const uint amount)
{
    amount_ = amount;
}
