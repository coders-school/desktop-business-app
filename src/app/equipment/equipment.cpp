#include "equipment.hpp"

Equipment::Equipment(const std::string &name, const double price, const int amount, const std::string &material,
                     const std::string &description)
    : Product(name, price, amount), material_(material), description_(description)
{
}

std::string_view Equipment::getMaterial() const
{
    return material_;
}

std::string_view Equipment::getDescription() const
{
    return description_;
}

void Equipment::setMaterial(const std::string &material)
{
    material_ = material;
}

void Equipment::setDescription(const std::string &description)
{
    description_ = description;
}
