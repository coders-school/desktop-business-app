#include "gtest/gtest.h"

struct WarehouseTest : ::testing::Test
{
};

TEST_F(WarehouseTest, BasicTest)
{
    EXPECT_EQ(true, true);
}
