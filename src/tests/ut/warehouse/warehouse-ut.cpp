#include "medicine.hpp"
#include "product.hpp"
#include "warehouse.hpp"
#include "gtest/gtest.h"

#include <utility>

struct WarehouseTest : ::testing::Test
{
    Warehouse testWarehouse;
    ~WarehouseTest() override
    {
    }

    void SetUp() override
    {
    }

    void TearDown() override
    {
    }
};

TEST_F(WarehouseTest, addSingleMedicineTest)
{
    std::string name{"anaesthetic"};
    std::pair storage_temperature{-10, 0};
    std::vector<std::string> composition{"chemicals"};
    auto anaesthetic = std::make_shared<Medicine>(name, 45, 100, 10122025, storage_temperature, composition);
    testWarehouse.addProducts({anaesthetic});

    EXPECT_EQ(testWarehouse.getProducts().at(0)->getName(), name);
    EXPECT_EQ(testWarehouse.getProducts().size(), 1);
}

TEST_F(WarehouseTest, addTwoMedicinesTest)
{
    std::string name1{"anaesthetic"};
    std::pair storage_temperature1{-10, 0};
    std::vector<std::string> composition1{"chemicals"};
    auto anaesthetic = std::make_shared<Medicine>(name1, 45, 100, 10122025, storage_temperature1, composition1);
    testWarehouse.addProducts({anaesthetic});

    std::string name2{"painkiller"};
    std::pair storage_temperature2{0, 20};
    std::vector<std::string> composition2{"ibuprofenum"};
    auto painkiller = std::make_shared<Medicine>(name2, 20, 100, 05062026, storage_temperature2, composition2);
    testWarehouse.addProducts({painkiller});

    EXPECT_EQ(testWarehouse.getProducts().at(0)->getName(), "anaesthetic");
    EXPECT_EQ(testWarehouse.getProducts().at(1)->getName(), "painkiller");
    EXPECT_EQ(testWarehouse.getProducts().size(), 2);
}

TEST_F(WarehouseTest, addTwoMedicinesInOneVectorTest)
{
    std::string name1{"anaesthetic"};
    std::pair storage_temperature1{-10, 0};
    std::vector<std::string> composition1{"chemicals"};
    auto anaesthetic = std::make_shared<Medicine>(name1, 45, 100, 10122025, storage_temperature1, composition1);

    std::string name2{"painkiller"};
    std::pair storage_temperature2{0, 20};
    std::vector<std::string> composition2{"ibuprofenum"};
    auto painkiller = std::make_shared<Medicine>(name2, 20, 100, 05062026, storage_temperature2, composition2);

    std::vector<std::shared_ptr<Product>> addedProducts{anaesthetic, painkiller};
    testWarehouse.addProducts(addedProducts);

    EXPECT_EQ(testWarehouse.getProducts().at(0)->getName(), "anaesthetic");
    EXPECT_EQ(testWarehouse.getProducts().at(1)->getName(), "painkiller");
    EXPECT_EQ(testWarehouse.getProducts().size(), 2);
}
