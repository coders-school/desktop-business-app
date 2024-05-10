#pragma once

#include "medicine.hpp"
#include "product.hpp"
#include "warehouse.hpp"
#include "clinic_facade.hpp"
#include "test_utils.hpp"
#include "gtest/gtest.h"

struct WarehouseTest : ::testing::Test
{
    std::shared_ptr<Warehouse> testWarehouse;
    std::shared_ptr<Product> anaesthetic;
    std::shared_ptr<Product> painkiller;
    
    protected:
        void SetUp(){
            Warehouse::createWarehouse();
            testWarehouse = Clinic::getWarehouse();
            anaesthetic = std::make_shared<Medicine>(
                std::string{"anaesthetic"}, 45, 100, 10122025, std::pair{-10, 0}, std::vector<std::string>{{"chemicals"}});
            painkiller = std::make_shared<Medicine>(
                std::string{"painkiller"}, 20, 100, 05062026, std::pair{0, 20}, std::vector<std::string>{"ibuprofenum"});
        }

        void TearDown(){
            cleanupClinic();
        }
};
