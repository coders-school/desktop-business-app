#include "receptionist_test.hpp"

namespace
{

TEST_F(ReceptionistTestFixture, GivenReceptionistOnMorningShiftExpectCorrectShiftAssigned)
{
    const auto shift = Shift::Morning;
    const auto expected_shift = toString(shift);
    Receptionist receptionist{"John", "Smith", "123"};
    receptionist.setShift(shift);

    EXPECT_EQ(receptionist.getShift(), expected_shift);
}

TEST_F(ReceptionistTestFixture, GivenReceptionistOnAfternoonShiftExpectCorrectShiftAssigned)
{
    const auto shift = Shift::Afternoon;
    const auto expected_shift = toString(shift);
    auto receptionist{Receptionist{"John", "Smith", "123"}};
    receptionist.setShift(shift);

    EXPECT_EQ(receptionist.getShift(), expected_shift);
}

} // namespace
