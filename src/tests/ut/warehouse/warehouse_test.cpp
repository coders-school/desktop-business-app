#include "warehouse_test.hpp"
#include <utility>

TEST_F(WarehouseTest, increaseAmountTest)
{
    test_warehouse->addProducts({anaesthetic});
    test_warehouse->increaseAmount(anaesthetic, 5);

    auto ptrsToProducts = test_warehouse->getPtrsToProducts("anaesthetic");
    EXPECT_EQ(ptrsToProducts.at(0)->getAmount(), 105);
}

TEST_F(WarehouseTest, decreaseAmountTest)
{
    test_warehouse->addProducts({anaesthetic});
    test_warehouse->decreaseAmount(anaesthetic, 5);

    auto ptrsToProducts = test_warehouse->getPtrsToProducts("anaesthetic");
    EXPECT_EQ(ptrsToProducts.at(0)->getAmount(), 95);
}

TEST_F(WarehouseTest, decreaseAmountBelow0Test)
{
    test_warehouse->addProducts({anaesthetic});
    test_warehouse->decreaseAmount(anaesthetic, 200);

    auto ptrsToProducts = test_warehouse->getPtrsToProducts("anaesthetic");
    EXPECT_EQ(ptrsToProducts.at(0)->getAmount(), 0);
}

TEST_F(WarehouseTest, addSingleMedicineTest)
{
    test_warehouse->addProducts({anaesthetic});

    auto ptrsToProducts = test_warehouse->getPtrsToProducts("anaesthetic");
    EXPECT_EQ(ptrsToProducts.at(0)->getName(), "anaesthetic");
    EXPECT_EQ(test_warehouse->getProducts().size(), 1);
}

TEST_F(WarehouseTest, addTwoMedicinesTest)
{
    test_warehouse->addProducts({anaesthetic, painkiller});

    auto ptrsToProducts1 = test_warehouse->getPtrsToProducts("anaesthetic");
    EXPECT_EQ(ptrsToProducts1.at(0)->getName(), "anaesthetic");
    auto ptrsToProducts2 = test_warehouse->getPtrsToProducts("painkiller");
    EXPECT_EQ(ptrsToProducts2.at(0)->getName(), "painkiller");
    EXPECT_EQ(test_warehouse->getProducts().size(), 2);
}

TEST_F(WarehouseTest, addZeroMedicinesInVectorTest)
{
    std::vector<std::shared_ptr<Product>> addedProducts{};
    test_warehouse->addProducts(addedProducts);

    EXPECT_EQ(test_warehouse->getProducts().size(), 0);
}

TEST_F(WarehouseTest, addTwoMedicinesInVectorTest)
{
    std::vector<std::shared_ptr<Product>> addedProducts{anaesthetic, painkiller};
    test_warehouse->addProducts(addedProducts);

    auto ptrsToProducts1 = test_warehouse->getPtrsToProducts("anaesthetic");
    EXPECT_EQ(ptrsToProducts1.at(0)->getName(), "anaesthetic");
    auto ptrsToProducts2 = test_warehouse->getPtrsToProducts("painkiller");
    EXPECT_EQ(ptrsToProducts2.at(0)->getName(), "painkiller");
    EXPECT_EQ(test_warehouse->getProducts().size(), 2);
}

TEST_F(WarehouseTest, addDuplicateMedicineTest)
{
    test_warehouse->addProducts({anaesthetic, painkiller});
    test_warehouse->addProducts({anaesthetic});

    EXPECT_EQ(test_warehouse->getProducts().size(), 2);
}

TEST_F(WarehouseTest, addTwoMedicinesWithSameNameTest)
{
    test_warehouse->addProducts({anaesthetic, painkiller});
    std::shared_ptr<Product> otherAnaesthetic =
        std::make_shared<Medicine>(std::string{"anaesthetic"}, price1, amount, expiration_date, storage_temperature1,
                                   std::vector<std::string>{{"chemicals"}});
    test_warehouse->addProducts({otherAnaesthetic});

    auto ptrsToProducts1 = test_warehouse->getPtrsToProducts("anaesthetic");
    EXPECT_EQ(ptrsToProducts1.at(0)->getName(), "anaesthetic");
    EXPECT_EQ(ptrsToProducts1.at(1)->getName(), "anaesthetic");
    auto ptrsToProducts2 = test_warehouse->getPtrsToProducts("painkiller");
    EXPECT_EQ(ptrsToProducts2.at(0)->getName(), "painkiller");
    EXPECT_EQ(test_warehouse->getProducts().size(), 3);
}

TEST_F(WarehouseTest, removeSingleMedicineTest)
{
    std::vector<std::shared_ptr<Product>> addedProducts{anaesthetic, painkiller};
    test_warehouse->addProducts(addedProducts);
    test_warehouse->removeProducts({anaesthetic});

    auto ptrsToProducts = test_warehouse->getPtrsToProducts("painkiller");
    EXPECT_EQ(ptrsToProducts.at(0)->getName(), "painkiller");
    EXPECT_EQ(test_warehouse->getProducts().size(), 1);
}

TEST_F(WarehouseTest, removeTwoMedicineTest)
{
    std::vector<std::shared_ptr<Product>> addedProducts{anaesthetic, painkiller};
    test_warehouse->addProducts(addedProducts);
    test_warehouse->removeProducts({anaesthetic, painkiller});

    EXPECT_EQ(test_warehouse->getProducts().size(), 0);
}

TEST_F(WarehouseTest, getPtrToProductExistingProductTest)
{
    std::vector<std::shared_ptr<Product>> addedProducts{anaesthetic};
    test_warehouse->addProducts(addedProducts);
    auto ptrsToProducts = test_warehouse->getPtrsToProducts("anaesthetic");

    EXPECT_EQ(ptrsToProducts.at(0), anaesthetic);
    EXPECT_EQ(ptrsToProducts.size(), 1);
}

TEST_F(WarehouseTest, getPtrToProductNonExistingProductTest)
{
    std::vector<std::shared_ptr<Product>> addedProducts{anaesthetic};
    test_warehouse->addProducts(addedProducts);
    auto ptrsToProducts = test_warehouse->getPtrsToProducts("painkiller");

    EXPECT_EQ(ptrsToProducts.size(), 0);
}
