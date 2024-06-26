#include "enumerations/specialization/Specialization.hpp"
#include <gtest/gtest.h>
namespace common
{
namespace specialization
{
namespace tests
{

TEST(SpecializationTest, GivenSpecializationWhenToStringCalledThenReturnCorrectString)
{
    const auto specialization = Specialization::Dentist;
    const auto expected_output = "Dentist";
    const auto output = toString(specialization);

    EXPECT_EQ(output, expected_output);
}

TEST(SpecializationTest, GivenInvalidSpecializationWhenToStringCalledThenReturnUnknown)
{
    const auto specialization = static_cast<Specialization>(250);
    const auto expected_output = "Unknown";
    const auto output = toString(specialization);

    EXPECT_EQ(output, expected_output);
}

TEST(SpecializationTest, GivenSpecializationStringWhenToEnumCalledThenReturnCorrectSpecialization)
{
    const auto specialization = "Dentist";
    const auto expected_output = Specialization::Dentist;
    const auto output = toEnum(specialization);

    EXPECT_EQ(output, expected_output);
}

TEST(SpecializationTest, GivenInvalidSpecializationStringWhenToEnumCalledThenReturnUnknown)
{
    const auto specialization = "Invalid";
    const auto expected_output = Specialization::Unknown;
    const auto output = toEnum(specialization);

    EXPECT_EQ(output, expected_output);
}

} // namespace tests
} // namespace specialization
} // namespace common
