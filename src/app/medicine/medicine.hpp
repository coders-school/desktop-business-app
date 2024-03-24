#pragma once
#include "product.hpp"
#include <vector>

class Medicine : public Product
{
    int expirationDate_;
    std::pair<double, double> storageTemperature_;
    std::vector<std::string> composition_;

  public:
    Medicine() = delete;
    Medicine(const std::string &name, const double price, const int amount, const int expirationDate,
             const std::pair<double, double> &storageTemperature, const std::vector<std::string> &composition);

    bool checkIfExpired(); // TODO: Write this function when Date will be ready

    std::vector<std::pair<std::string, std::string>> getInfo() const override;
};
