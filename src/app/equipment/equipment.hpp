#pragma once
#include "product.hpp"
#include <string>

class Equipment : public Product
{
    std::string material_;
    std::string description_;

  public:
    Equipment(const std::string& name, const double price, const int amount, const std::string& material,
              const std::string& description);

    std::map<std::string, std::string> getInfo() const override;
};
