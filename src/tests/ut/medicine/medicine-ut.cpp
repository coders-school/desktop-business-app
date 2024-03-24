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
    EXPECT_EQ(infoVec.at(0).second, "10122025");
    EXPECT_EQ(infoVec.at(1).second, "-10.000000 / 0.000000");
    EXPECT_EQ(infoVec.at(2).second, "chemicals, ");
}
