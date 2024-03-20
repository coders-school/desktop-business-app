#include "medicine.hpp"
#include "product.hpp"
#include "warehouse.hpp"
#include "gtest/gtest.h"

#include <utility>

struct WarehouseTest : ::testing::Test
{
    Warehouse testWarehouse;
    std::shared_ptr<Product> anaesthetic = std::make_shared<Medicine>(
        std::string{"anaesthetic"}, 45, 100, 10122025, std::pair{-10, 0}, std::vector<std::string>{{"chemicals"}});
    std::shared_ptr<Product> painkiller = std::make_shared<Medicine>(
        std::string{"painkiller"}, 20, 100, 05062026, std::pair{0, 20}, std::vector<std::string>{"ibuprofenum"});
};

TEST_F(WarehouseTest, increaseAmountTest)
{
    std::vector<std::shared_ptr<Product>> addedProducts{anaesthetic};
    testWarehouse.addProducts(addedProducts);
    testWarehouse.increaseAmount("anaesthetic", 5);

    EXPECT_EQ(testWarehouse.getProducts().at(0)->getAmount(), 105);
}

TEST_F(WarehouseTest, decreaseAmountTest)
{
    std::vector<std::shared_ptr<Product>> addedProducts{anaesthetic};
    testWarehouse.addProducts(addedProducts);
    testWarehouse.decreaseAmount("anaesthetic", 5);

    EXPECT_EQ(testWarehouse.getProducts().at(0)->getAmount(), 95);
}

TEST_F(WarehouseTest, addSingleMedicineTest)
{
    testWarehouse.addProducts({anaesthetic});

    EXPECT_EQ(testWarehouse.getProducts().at(0)->getName(), "anaesthetic");
    EXPECT_EQ(testWarehouse.getProducts().size(), 1);
}

TEST_F(WarehouseTest, addTwoMedicinesTest)
{
    testWarehouse.addProducts({anaesthetic, painkiller});

    EXPECT_EQ(testWarehouse.getProducts().at(0)->getName(), "anaesthetic");
    EXPECT_EQ(testWarehouse.getProducts().at(1)->getName(), "painkiller");
    EXPECT_EQ(testWarehouse.getProducts().size(), 2);
}

TEST_F(WarehouseTest, addZeroMedicinesInVectorTest)
{
    std::vector<std::shared_ptr<Product>> addedProducts{};
    testWarehouse.addProducts(addedProducts);

    EXPECT_EQ(testWarehouse.getProducts().size(), 0);
}

TEST_F(WarehouseTest, addTwoMedicinesInVectorTest)
{
    std::vector<std::shared_ptr<Product>> addedProducts{anaesthetic, painkiller};
    testWarehouse.addProducts(addedProducts);

    EXPECT_EQ(testWarehouse.getProducts().at(0)->getName(), "anaesthetic");
    EXPECT_EQ(testWarehouse.getProducts().at(1)->getName(), "painkiller");
    EXPECT_EQ(testWarehouse.getProducts().size(), 2);
}

TEST_F(WarehouseTest, validateAddTest)
{
    std::vector<std::shared_ptr<Product>> addedProducts{anaesthetic};
    testWarehouse.addProducts(addedProducts);

    EXPECT_EQ(testWarehouse.validateAdd("anaesthetic"), true);
    EXPECT_EQ(testWarehouse.validateAdd("painkiller"), false);
}

TEST_F(WarehouseTest, removeSingleMedicineTest)
{
    std::vector<std::shared_ptr<Product>> addedProducts{anaesthetic, painkiller};
    testWarehouse.addProducts(addedProducts);
    testWarehouse.removeProducts({{"anaesthetic"}});

    EXPECT_EQ(testWarehouse.getProducts().at(0)->getName(), "painkiller");
    EXPECT_EQ(testWarehouse.getProducts().size(), 1);
}

TEST_F(WarehouseTest, removeTwoMedicineTest)
{
    std::vector<std::shared_ptr<Product>> addedProducts{anaesthetic, painkiller};
    testWarehouse.addProducts(addedProducts);
    testWarehouse.removeProducts({{"anaesthetic"}, {"painkiller"}});

    EXPECT_EQ(testWarehouse.getProducts().size(), 0);
}

TEST_F(WarehouseTest, validateRemovalTest)
{
    std::vector<std::shared_ptr<Product>> addedProducts{anaesthetic, painkiller};
    testWarehouse.addProducts(addedProducts);
    testWarehouse.removeProducts({{"anaesthetic"}});

    EXPECT_EQ(testWarehouse.validateRemoval("anaesthetic"), true);
    EXPECT_EQ(testWarehouse.validateRemoval("painkiller"), false);
}

TEST_F(WarehouseTest, getPtrToProductExistingProductTest)
{
    std::vector<std::shared_ptr<Product>> addedProducts{anaesthetic};
    testWarehouse.addProducts(addedProducts);
    auto ptrToProduct = testWarehouse.getPtrToProduct("anaesthetic");

    EXPECT_EQ((*ptrToProduct).getName(), "anaesthetic");
    EXPECT_NE(ptrToProduct, nullptr);
}

TEST_F(WarehouseTest, getPtrToProductNonExistingProductTest)
{
    std::vector<std::shared_ptr<Product>> addedProducts{anaesthetic};
    testWarehouse.addProducts(addedProducts);
    auto ptrToProduct = testWarehouse.getPtrToProduct("painkiller");

    EXPECT_EQ(ptrToProduct, nullptr);
}
