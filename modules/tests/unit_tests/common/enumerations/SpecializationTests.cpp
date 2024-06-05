#include "enumerations/specialization/Specialization.hpp"
#include <gtest/gtest.h>
namespace common
{
namespace specialization
{
namespace tests
{
TEST(SpecializationToStringTest, checkIfToStringReturnsCorrectString)
{
    Specialization specialization = Specialization::Dentist;
    std::string expectedString = "Dentist";
    std::string actualString = toString(specialization);
    EXPECT_EQ(actualString, expectedString);
}

TEST(SpecializationToStringTest, checkIfToStringReturnsUnknownForInvalidSpecialization)
{
    Specialization specialization = static_cast<Specialization>(999);
    std::string expectedString = "Unknown";
    std::string actualString = toString(specialization);
    EXPECT_EQ(actualString, expectedString);
}

} // namespace tests
} // namespace specialization
} // namespace common
