#include "product.hpp"

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
