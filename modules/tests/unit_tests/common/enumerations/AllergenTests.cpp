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
    std::string expected_output;
};

class AllergenToStringFixture : public ::testing::TestWithParam<ToStringTestParams>
{
};

TEST_F(AllergenToStringFixture, GivenAllergenEnumerationWhenConvertingToStringExpectValidConversion)
{
    const auto& expected_output = GetParam().expected_output;
    const auto& output = toString(GetParam().allergen);

    EXPECT_EQ(output, expected_output);
}

INSTANTIATE_TEST_CASE_P(AllergenParametricTests, AllergenToStringFixture,
                        ::testing::Values(ToStringTestParams{Allergen::Allergen, "Allergen"},
                                          ToStringTestParams{Allergen::AnotherAllergen, "AnotherAllergen"},
                                          ToStringTestParams{Allergen::SomeAllergen, "SomeAllergen"},
                                          ToStringTestParams{Allergen::DifferentAllergen, "DifferentAllergen"},
                                          ToStringTestParams{static_cast<Allergen>(250), "DifferentAllergen"}));

struct ToEnumTestParams
{
    std::string allergen;
    Allergen expected_output;
};

class AllergenToEnumFixture : public ::testing::TestWithParam<ToEnumTestParams>
{
};

TEST_P(AllergenToEnumFixture, GivenAllergenStringWhenConvertingToEnumExpectValidConversion)
{
    const auto& expected_output = GetParam().expected_output;
    const auto& output = toEnum(GetParam().allergen);

    EXPECT_EQ(output, expected_output);
}

INSTANTIATE_TEST_CASE_P(AllergenParametricTests, AllergenToEnumFixture,
                        ::testing::Values(ToEnumTestParams{"Allergen", Allergen::Allergen},
                                          ToEnumTestParams{"AnotherAllergen", Allergen::AnotherAllergen},
                                          ToEnumTestParams{"SomeAllergen", Allergen::SomeAllergen},
                                          ToEnumTestParams{"DifferentAllergen", Allergen::DifferentAllergen},
                                          ToEnumTestParams{"invalid", Allergen::DifferentAllergen}));

} // namespace tests
} // namespace allergen
} // namespace common
