#include "equipment.hpp"

Equipment::Equipment(const std::string &name, const double price, const int amount, const std::string &material,
                     const std::string &description)
    : Product(name, price, amount), material_{material}, description_{description}
{
}

std::map<std::string, std::string> Equipment::getInfo() const
{
    return {{{"material"}, {material_}}, {{"description"}, {description_}}};
}
