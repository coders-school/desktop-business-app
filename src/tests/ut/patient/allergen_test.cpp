#include "allergen_test.hpp"

namespace
{

TEST_P(AllergenParameterizedFixture, GivenAllergenEnumerationExpectValidConversionToString)
{
    const auto output = toString(GetParam().allergen_input_);

    EXPECT_EQ(output, GetParam().expected_output_);
}

INSTANTIATE_TEST_SUITE_P(AllergenConversionTest, AllergenParameterizedFixture,
                         ::testing::Values(TestParams{Allergen::Allergen, "allergen"},
                                           TestParams{Allergen::AnotherAllergen, "another allergen"},
                                           TestParams{Allergen::DifferentAllergen, "different allergen"},
                                           TestParams{Allergen::SomeAllergen, "some allergen"}));

} // namespace
