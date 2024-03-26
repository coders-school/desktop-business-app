#include "equipment.hpp"
#include "product.hpp"
#include "gtest/gtest.h"

struct EquipmentTest : ::testing::Test
{
    std::shared_ptr<Product> dentalDrill = std::make_shared<Equipment>(
        std::string{"painkiller"}, 20, 100, std::string("steel"), std::string("steel dental drill"));
};

TEST_F(EquipmentTest, getInfoTest)
{
    auto infoVec = dentalDrill->getInfo();
    EXPECT_EQ(infoVec.at("material"), "steel");
    EXPECT_EQ(infoVec.at("description"), "steel dental drill");
}

TEST_F(EquipmentTest, increaseAmountTest)
{
    dentalDrill->increaseAmount(100);
    EXPECT_EQ(dentalDrill->getAmount(), 200);
}

TEST_F(EquipmentTest, decreaseAmountTest)
{
    dentalDrill->decreaseAmount(50);
    EXPECT_EQ(dentalDrill->getAmount(), 50);
}
