#pragma once
#include "product.hpp"
#include <vector>

class Medicine : public Product
{
    int expiration_date_;
    std::pair<double, double> storage_temperature_;
    std::vector<std::string> composition_;
};
