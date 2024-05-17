#pragma once

#include "clinic_facade.hpp"
#include "medicine.hpp"
#include "product.hpp"
#include "test_utils.hpp"
#include "warehouse.hpp"
#include "gtest/gtest.h"

using namespace std::chrono_literals;

constexpr uint price1{45};
constexpr uint price2{20};
constexpr uint amount{100};
constexpr std::pair storage_temperature1{-10, 0};
constexpr std::pair storage_temperature2{-10, 0};

struct WarehouseTest : ::testing::Test
{
  public:
    std::shared_ptr<Warehouse> test_warehouse;
    std::shared_ptr<Product> anaesthetic;
    std::shared_ptr<Product> painkiller;
    std::chrono::year_month_day expiration_date{2030y, std::chrono::January, 31d};

  protected:
    void SetUp()
    {
        Warehouse::createWarehouse();
        test_warehouse = Clinic::getWarehouse();

        std::shared_ptr<Product> anaesthetic =
            std::make_shared<Medicine>(std::string{"anaesthetic"}, price1, amount, expiration_date,
                                       storage_temperature1, std::vector<std::string>{{"chemicals"}});
        std::shared_ptr<Product> painkiller =
            std::make_shared<Medicine>(std::string{"painkiller"}, price2, amount, expiration_date, storage_temperature2,
                                       std::vector<std::string>{"ibuprofenum"});
    }

    void TearDown()
    {
        cleanupClinic();
    }
};
