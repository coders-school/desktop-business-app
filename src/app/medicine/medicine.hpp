#pragma once
#include "product.hpp"
#include <chrono>
#include <vector>

class Medicine : public Product
{
    std::chrono::year_month_day expiration_date_;
    std::pair<double, double> storage_temperature_;
    std::vector<std::string> composition_;

  public:
    Medicine() = delete;
    Medicine(const std::string& name, const double price, const int amount,
             const std::chrono::year_month_day expiration_date, const std::pair<double, double>& storage_temperature,
             const std::vector<std::string>& composition);

    bool isExpired() const override;
    std::map<std::string, std::string> getInfo() const override;
};
