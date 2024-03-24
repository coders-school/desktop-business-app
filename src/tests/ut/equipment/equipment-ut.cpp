#include "equipment.hpp"
#include "product.hpp"
#include "gtest/gtest.h"

struct MedicineTest : ::testing::Test
{
    std::shared_ptr<Product> dentalDrill = std::make_shared<Equipment>(
        std::string{"painkiller"}, 20, 100, std::string("steel"), std::string("steel dental drill"));
};

TEST_F(MedicineTest, MedicineGetInfoTest)
{
    auto infoVec = dentalDrill->getInfo();
    EXPECT_EQ(infoVec.at(0).second, "steel");
    EXPECT_EQ(infoVec.at(1).second, "steel dental drill");
}
