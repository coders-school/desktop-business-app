#include "gtest/gtest.h"

#include "visitStatus.hpp"

TEST(EnumVisitStatusTest, ToStringShouldReturnCanceled)
{
    EXPECT_EQ(toString(VisitStatus::Canceled), "Canceled");
    EXPECT_EQ(toString(VisitStatus::Confirmed), "Confirmed");
    EXPECT_EQ(toString(VisitStatus::Relocated), "Relocated");
    EXPECT_EQ(toString(VisitStatus::Visited), "Visited");
}
