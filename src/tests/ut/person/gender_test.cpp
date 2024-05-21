#include "gender_test.hpp"

namespace
{

TEST_P(GenderEnumToStringTest, GivenGenderEnumExpectValidConversionToString)
{
    const auto output = toString(GetParam().input_);

    EXPECT_EQ(output, GetParam().expected_output_);
}

TEST_P(GenderStringToEnumTest, GivenGenderStringExpectValidConversionToEnum)
{
    const auto output = toEnum(GetParam().input_);

    EXPECT_EQ(output, GetParam().expected_output_);
}

INSTANTIATE_TEST_SUITE_P(GenderEnumToStringConversionTest, GenderEnumToStringTest,
                         ::testing::Values(TestParamsEnumInput{Gender::Male, "male"},
                                           TestParamsEnumInput{Gender::Female, "female"},
                                           TestParamsEnumInput{Gender::Unknown, "unknown"}));

INSTANTIATE_TEST_SUITE_P(GenderStringToEnumConversionTest, GenderStringToEnumTest,
                         ::testing::Values(TestParamsStringInput{"male", Gender::Male},
                                           TestParamsStringInput{"female", Gender::Female},
                                           TestParamsStringInput{"unknown", Gender::Unknown}));

} // namespace
