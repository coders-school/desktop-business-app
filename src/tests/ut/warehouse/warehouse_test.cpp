#include "medicine.hpp"
#include "product.hpp"
#include "warehouse.hpp"
#include "gtest/gtest.h"
#include <utility>

using namespace std::chrono_literals;

constexpr uint price1{45};
constexpr uint price2{20};
constexpr uint amount{100};
constexpr std::pair storage_temperature1{-10, 0};
constexpr std::pair storage_temperature2{-10, 0};

class WarehouseTest : public ::testing::Test
{
  public:
    Warehouse testWarehouse;
    std::chrono::year_month_day expiration_date{2030y, std::chrono::January, 31d};
    std::shared_ptr<Product> anaesthetic =
        std::make_shared<Medicine>(std::string{"anaesthetic"}, price1, amount, expiration_date, storage_temperature1,
                                   std::vector<std::string>{{"chemicals"}});
    std::shared_ptr<Product> painkiller =
        std::make_shared<Medicine>(std::string{"painkiller"}, price2, amount, expiration_date, storage_temperature2,
                                   std::vector<std::string>{"ibuprofenum"});
};

TEST_F(WarehouseTest, increaseAmountTest)
{
    testWarehouse.addProducts({anaesthetic});
    testWarehouse.increaseAmount(anaesthetic, 5);

    auto ptrsToProducts = testWarehouse.getPtrsToProducts("anaesthetic");
    EXPECT_EQ(ptrsToProducts.at(0)->getAmount(), 105);
}

TEST_F(WarehouseTest, decreaseAmountTest)
{
    testWarehouse.addProducts({anaesthetic});
    testWarehouse.decreaseAmount(anaesthetic, 5);

    auto ptrsToProducts = testWarehouse.getPtrsToProducts("anaesthetic");
    EXPECT_EQ(ptrsToProducts.at(0)->getAmount(), 95);
}

TEST_F(WarehouseTest, decreaseAmountBelow0Test)
{
    testWarehouse.addProducts({anaesthetic});
    testWarehouse.decreaseAmount(anaesthetic, 200);

    auto ptrsToProducts = testWarehouse.getPtrsToProducts("anaesthetic");
    EXPECT_EQ(ptrsToProducts.at(0)->getAmount(), 0);
}

TEST_F(WarehouseTest, addSingleMedicineTest)
{
    testWarehouse.addProducts({anaesthetic});

    auto ptrsToProducts = testWarehouse.getPtrsToProducts("anaesthetic");
    EXPECT_EQ(ptrsToProducts.at(0)->getName(), "anaesthetic");
    EXPECT_EQ(testWarehouse.getProducts().size(), 1);
}

TEST_F(WarehouseTest, addTwoMedicinesTest)
{
    testWarehouse.addProducts({anaesthetic, painkiller});

    auto ptrsToProducts1 = testWarehouse.getPtrsToProducts("anaesthetic");
    EXPECT_EQ(ptrsToProducts1.at(0)->getName(), "anaesthetic");
    auto ptrsToProducts2 = testWarehouse.getPtrsToProducts("painkiller");
    EXPECT_EQ(ptrsToProducts2.at(0)->getName(), "painkiller");
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

    auto ptrsToProducts1 = testWarehouse.getPtrsToProducts("anaesthetic");
    EXPECT_EQ(ptrsToProducts1.at(0)->getName(), "anaesthetic");
    auto ptrsToProducts2 = testWarehouse.getPtrsToProducts("painkiller");
    EXPECT_EQ(ptrsToProducts2.at(0)->getName(), "painkiller");
    EXPECT_EQ(testWarehouse.getProducts().size(), 2);
}

TEST_F(WarehouseTest, addDuplicateMedicineTest)
{
    testWarehouse.addProducts({anaesthetic, painkiller});
    testWarehouse.addProducts({anaesthetic});

    EXPECT_EQ(testWarehouse.getProducts().size(), 2);
}

TEST_F(WarehouseTest, addTwoMedicinesWithSameNameTest)
{
    testWarehouse.addProducts({anaesthetic, painkiller});
    std::shared_ptr<Product> otherAnaesthetic =
        std::make_shared<Medicine>(std::string{"anaesthetic"}, price1, amount, expiration_date, storage_temperature1,
                                   std::vector<std::string>{{"chemicals"}});
    testWarehouse.addProducts({otherAnaesthetic});

    auto ptrsToProducts1 = testWarehouse.getPtrsToProducts("anaesthetic");
    EXPECT_EQ(ptrsToProducts1.at(0)->getName(), "anaesthetic");
    EXPECT_EQ(ptrsToProducts1.at(1)->getName(), "anaesthetic");
    auto ptrsToProducts2 = testWarehouse.getPtrsToProducts("painkiller");
    EXPECT_EQ(ptrsToProducts2.at(0)->getName(), "painkiller");
    EXPECT_EQ(testWarehouse.getProducts().size(), 3);
}

TEST_F(WarehouseTest, removeSingleMedicineTest)
{
    std::vector<std::shared_ptr<Product>> addedProducts{anaesthetic, painkiller};
    testWarehouse.addProducts(addedProducts);
    testWarehouse.removeProducts({anaesthetic});

    auto ptrsToProducts = testWarehouse.getPtrsToProducts("painkiller");
    EXPECT_EQ(ptrsToProducts.at(0)->getName(), "painkiller");
    EXPECT_EQ(testWarehouse.getProducts().size(), 1);
}

TEST_F(WarehouseTest, removeTwoMedicineTest)
{
    std::vector<std::shared_ptr<Product>> addedProducts{anaesthetic, painkiller};
    testWarehouse.addProducts(addedProducts);
    testWarehouse.removeProducts({anaesthetic, painkiller});

    EXPECT_EQ(testWarehouse.getProducts().size(), 0);
}

TEST_F(WarehouseTest, getPtrToProductExistingProductTest)
{
    std::vector<std::shared_ptr<Product>> addedProducts{anaesthetic};
    testWarehouse.addProducts(addedProducts);
    auto ptrsToProducts = testWarehouse.getPtrsToProducts("anaesthetic");

    EXPECT_EQ(ptrsToProducts.at(0), anaesthetic);
    EXPECT_EQ(ptrsToProducts.size(), 1);
}

TEST_F(WarehouseTest, getPtrToProductNonExistingProductTest)
{
    std::vector<std::shared_ptr<Product>> addedProducts{anaesthetic};
    testWarehouse.addProducts(addedProducts);
    auto ptrsToProducts = testWarehouse.getPtrsToProducts("painkiller");

    EXPECT_EQ(ptrsToProducts.size(), 0);
}
