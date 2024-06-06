#include "enumerations/treatment_state/TreatmentState.hpp"
#include <gtest/gtest.h>

namespace common
{
namespace treatment_state
{
namespace tests
{
struct TreatmentStateToStringTestParams
{
    TreatmentState state;
    std::string expected_output;
};

class ToStringTest : public ::testing::TestWithParam<TreatmentStateToStringTestParams>
{
};

TEST_P(ToStringTest, GivenTreatmentStateWhenToStringCalledThenReturnCorrectString)
{
    const auto& output = toString(GetParam().state);
    const auto& expected_output = GetParam().expected_output;

    EXPECT_EQ(output, expected_output);
}

INSTANTIATE_TEST_SUITE_P(TreatmentState, ToStringTest,
                         ::testing::Values(TreatmentStateToStringTestParams{TreatmentState::Done, "Done"},
                                           TreatmentStateToStringTestParams{TreatmentState::Planned, "Planned"},
                                           TreatmentStateToStringTestParams{TreatmentState::Unknown, "Unknown"}));

struct TreatmentStateToEnumTestParams
{
    std::string treatment_state;
    TreatmentState expected_state;
};

class ToEnumTest : public ::testing::TestWithParam<TreatmentStateToEnumTestParams>
{
};

TEST_P(ToEnumTest, GivenTreatmentStateStringWhenToEnumCalledThenReturnCorrectTreatment)
{
    const auto& output = toEnum(GetParam().treatment_state);
    const auto& expected_state = GetParam().expected_state;
    EXPECT_EQ(output, expected_state);
}

INSTANTIATE_TEST_SUITE_P(TreatmentState, ToEnumTest,
                         ::testing::Values(TreatmentStateToEnumTestParams{"Done", TreatmentState::Done},
                                           TreatmentStateToEnumTestParams{"Planned", TreatmentState::Planned},
                                           TreatmentStateToEnumTestParams{"Unknown", TreatmentState::Unknown},
                                           TreatmentStateToEnumTestParams{"123babyjagapaczy",
                                                                          TreatmentState::Unknown}));
} // namespace tests
} // namespace treatment_state
} // namespace common
