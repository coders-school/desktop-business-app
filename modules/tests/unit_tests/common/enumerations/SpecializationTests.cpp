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
    Specialization specialization = Specialization::Dentist;
    const std::string expectedString = "Dentist";
    const std::string actualString = toString(specialization);
    EXPECT_EQ(actualString, expectedString);
}

TEST(SpecializationTest, GivenInvalidSpecializationWhenToStringCalledThenReturnUnknown)
{
    Specialization specialization = static_cast<Specialization>(999);
    const std::string expectedString = "Unknown";
    const std::string actualString = toString(specialization);
    EXPECT_EQ(actualString, expectedString);
}

TEST(SpecializationTest, GivenSpecializationStringWhenToEnumCalledThenReturnCorrectSpecialization)
{
    const std::string specializationString = "Dentist";
    Specialization expectedSpecialization = Specialization::Dentist;
    Specialization actualSpecialization = toEnum(specializationString);
    EXPECT_EQ(actualSpecialization, expectedSpecialization);
}

TEST(SpecializationTest, GivenInvalidSpecializationStringWhenToEnumCalledThenReturnUnknown)
{
    const std::string specializationString = "Invalid";
    Specialization expectedSpecialization = Specialization::Unknown;
    Specialization actualSpecialization = toEnum(specializationString);
    EXPECT_EQ(actualSpecialization, expectedSpecialization);
}

} // namespace tests
} // namespace specialization
} // namespace common
