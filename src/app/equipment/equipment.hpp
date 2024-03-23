#pragma once
#include "product.hpp"
#include <string>

class Equipment : public Product
{
    std::string material_;
    std::string description_;

  public:
    Equipment() = delete;
    Equipment(const std::string &name, const double price, const int amount, const std::string &material,
              const std::string &description);

    std::string_view getMaterial() const;
    std::string_view getDescription() const;

    void setMaterial(const std::string &material);
    void setDescription(const std::string &description);
};
