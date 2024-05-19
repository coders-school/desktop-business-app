#pragma once
#include "medicine.hpp"
#include "product.hpp"
#include "gtest/gtest.h"

using namespace std::chrono_literals;

constexpr int price{45};
constexpr int amount{100};
constexpr std::pair storage_temperature{-10, 0};

struct MedicineTest : ::testing::Test
{
    std::shared_ptr<Product> anaesthetic;
    std::chrono::year_month_day expiration_date{2030y, std::chrono::January, 31d};

  protected:
    void SetUp()
    {
        anaesthetic = std::make_shared<Medicine>(std::string{"anaesthetic"}, price, amount, expiration_date,
                                                 storage_temperature, std::vector<std::string>{{"chemicals"}});
    }
};
