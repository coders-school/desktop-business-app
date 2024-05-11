#pragma once

#include "clinic_facade.hpp"
#include "medicine.hpp"
#include "product.hpp"
#include "test_utils.hpp"
#include "warehouse.hpp"
#include "gtest/gtest.h"

constexpr int price{45};
constexpr int amount{100};
constexpr int expiration_date{10122025};
constexpr std::pair storage_temperature{-10, 0};

struct WarehouseTest : ::testing::Test
{
    std::shared_ptr<Warehouse> test_warehouse;
    std::shared_ptr<Product> anaesthetic;
    std::shared_ptr<Product> painkiller;

  protected:
    void SetUp()
    {
        Warehouse::createWarehouse();
        test_warehouse = Clinic::getWarehouse();
        const std::string name{"anaesthetic"};
        const std::vector<std::string> composition{"chemicals"};
        anaesthetic =
            std::make_shared<Medicine>(name, price, amount, expiration_date, storage_temperature, composition);
        painkiller = std::make_shared<Medicine>(std::string{"painkiller"}, 20, 100, 05062026, std::pair{0, 20},
                                                std::vector<std::string>{"ibuprofenum"});
    }

    void TearDown()
    {
        cleanupClinic();
    }
};
