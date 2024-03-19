#include "product.hpp"

Product::Product(const std::string &name, double price, int amount) : name_(name), price_(price), amount_(amount)
{
}

void Product::increaseAmount(int amount)
{
    amount_ += amount;
}

void Product::decreaseAmount(int amount)
{
    amount_ -= amount;
}

std::string_view Product::getName() const
{
    return name_;
}
