#include "receptionist_test.hpp"
#include "clinic_facade.hpp"

namespace
{

TEST_F(ReceptionistTestFixture, GivenReceptionistOnMorningShiftExpectCorrectShiftAssigned)
{
    const auto shift = Shift::Morning;
    const auto expected_shift = toString(shift);
    Receptionist::createReceptionist("John", "Smith", "123", Gender::Male);
    auto receptionist{Clinic::getReceptionists().front()};
    receptionist->setShift(shift);

    EXPECT_EQ(receptionist->getShift(), expected_shift);
}

TEST_F(ReceptionistTestFixture, GivenReceptionistOnAfternoonShiftExpectCorrectShiftAssigned)
{
    const auto shift = Shift::Afternoon;
    const auto expected_shift = toString(shift);
    Receptionist::createReceptionist("John", "Smith", "123", Gender::Male);
    auto receptionist{Clinic::getReceptionists().front()};
    receptionist->setShift(shift);

    EXPECT_EQ(receptionist->getShift(), expected_shift);
}

} // namespace
