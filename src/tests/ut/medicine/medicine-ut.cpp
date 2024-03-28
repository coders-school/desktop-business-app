#include "medicine.hpp"
#include "product.hpp"
#include "gtest/gtest.h"

struct MedicineTest : ::testing::Test
{
    std::shared_ptr<Product> anaesthetic = std::make_shared<Medicine>(
        std::string{"anaesthetic"}, 45, 100, 10122025, std::pair{-10, 0}, std::vector<std::string>{{"chemicals"}});
};

TEST_F(MedicineTest, MedicineGetInfoTest)
{
    auto infoVec = anaesthetic->getInfo();
    EXPECT_EQ(infoVec.at("expiration date"), "10122025");
    EXPECT_EQ(infoVec.at("storage temperature"), "-10.000000 / 0.000000");
    EXPECT_EQ(infoVec.at("composition"), "chemicals, ");
}

TEST_F(MedicineTest, increaseAmountTest)
{
    anaesthetic->increaseAmount(100);
    EXPECT_EQ(anaesthetic->getAmount(), 200);
}

TEST_F(MedicineTest, decreaseAmountTest)
{
    anaesthetic->decreaseAmount(50);
    EXPECT_EQ(anaesthetic->getAmount(), 50);
}
