#pragma once
#include "product.hpp"
#include <string>

class Medicine : public Product
{
    std::string material_;
    std::string description_;
};
