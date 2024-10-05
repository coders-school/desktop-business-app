#include "enumerations/sex/Sex.hpp"
#include <gtest/gtest.h>

namespace common
{

namespace sex
{

namespace tests
{

TEST(SexTests, GivenSexWhenToStringThenReturnStringRepresentation)
{
    EXPECT_EQ("Male", toString(Sex::Male));
    EXPECT_EQ("Female", toString(Sex::Female));
}

TEST(SexTests, GivenInvalidSexWhenToStringThenThrow)
{
    EXPECT_THROW(toString(static_cast<Sex>(10)), std::invalid_argument);
}

TEST(SexTests, GivenStringWhenToEnumThenReturnValidSex)
{
    EXPECT_EQ(Sex::Male, toEnum("Male"));
    EXPECT_EQ(Sex::Female, toEnum("Female"));
}

TEST(SexTests, GivenInvalidStringWhenToEnumThenThrow)
{
    EXPECT_THROW(toEnum("Invalid"), std::invalid_argument);
    EXPECT_THROW(toEnum("123"), std::invalid_argument);
    EXPECT_THROW(toEnum(""), std::invalid_argument);
}

} // namespace tests
} // namespace sex
} // namespace common
