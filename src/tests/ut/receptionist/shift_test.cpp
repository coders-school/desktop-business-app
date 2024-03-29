#include "shift_test.hpp"

namespace
{

TEST_P(ShiftParameterizedFixture, GivenShiftEnumerationExpectValidConversionToString)
{
    const auto output = toString(GetParam().shift_input_);

    EXPECT_EQ(output, GetParam().expected_output_);
}

INSTANTIATE_TEST_SUITE_P(ShiftConversionTest, ShiftParameterizedFixture,
                         ::testing::Values(TestParams{Shift::Morning, "morning shift"},
                                           TestParams{Shift::Afternoon, "afternoon shift"}));

} // namespace
