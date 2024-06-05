#include "enumerations/allergen/Allergen.hpp"
#include <gtest/gtest.h>

namespace common
{
namespace allergen
{
namespace tests
{

struct ToStringTestParams
{
    Allergen allergen;
    std::string expectedString;
};

class AllergenToStringFixture : public ::testing::TestWithParam<ToStringTestParams>
{
};

TEST_F(AllergenToStringFixture, GivenAllergenEnumerationWhenConvertingToStringExpectValidConversion)
{
    ToStringTestParams testData = GetParam();
    std::string actualString = toString(testData.allergen);
    EXPECT_EQ(actualString, testData.expectedString);
}

INSTANTIATE_TEST_CASE_P(AllergenParametricTests, AllergenToStringFixture,
                        ::testing::Values(ToStringTestParams{Allergen::Allergen, "Allergen"},
                                          ToStringTestParams{Allergen::AnotherAllergen, "AnotherAllergen"},
                                          ToStringTestParams{Allergen::SomeAllergen, "SomeAllergen"},
                                          ToStringTestParams{Allergen::DifferentAllergen, "DifferentAllergen"}));

struct ToEnumTestParams
{
    std::string allergenString;
    Allergen expectedAllergen;
};

class AllergenToEnumFixture : public ::testing::TestWithParam<ToEnumTestParams>
{
};

TEST_P(AllergenToEnumFixture, GivenAllergenStringWhenConvertingToEnumExpectValidConversion)
{
    ToEnumTestParams testData = GetParam();
    Allergen actualAllergen = toEnum(testData.allergenString);
    EXPECT_EQ(actualAllergen, testData.expectedAllergen);
}

INSTANTIATE_TEST_CASE_P(AllergenParametricTests, AllergenToEnumFixture,
                        ::testing::Values(ToEnumTestParams{"Allergen", Allergen::Allergen},
                                          ToEnumTestParams{"AnotherAllergen", Allergen::AnotherAllergen},
                                          ToEnumTestParams{"SomeAllergen", Allergen::SomeAllergen},
                                          ToEnumTestParams{"DifferentAllergen", Allergen::DifferentAllergen}));

} // namespace tests
} // namespace allergen
} // namespace common
