#pragma once
#include "product.hpp"
#include <vector>

class Medicine : public Product
{
  public:
    Medicine() = delete;
    Medicine(const std::string &name, double price, int amount, int expiration_date,
             std::pair<double, double> storage_temperature, std::vector<std::string> composition);

  private:
    int expiration_date_;
    std::pair<double, double> storage_temperature_;
    std::vector<std::string> composition_;
};
