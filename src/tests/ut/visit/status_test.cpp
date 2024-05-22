#include "gtest/gtest.h"

#include "status.hpp"

TEST(EnumStatusTest1, ToStringShouldReturnCanceled)
{
    EXPECT_EQ(toString(Status::Canceled), "Canceled");
}

TEST(EnumStatusTest2, ToStringShouldReturnConfirmed)
{
    EXPECT_EQ(toString(Status::Confirmed), "Confirmed");
}

TEST(EnumStatusTest3, ToStringShouldReturnRelocated)
{
    EXPECT_EQ(toString(Status::Relocated), "Relocated");
}

TEST(EnumStatusTest4, ToStringShouldReturnRelocated)
{
    EXPECT_EQ(toString(Status::Visited), "Visited");
}