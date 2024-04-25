#include "calendar_test.hpp"

namespace
{
TEST_F(CalendarTestFixture, CheckIfGenerateCorrectAmountOfMonths)
{
    EXPECT_EQ(cal->getYears().at(0)->getMonths().size(), 12);
}

TEST_F(CalendarTestFixture, GivenNewYearIntCheckIfHasCorrectAmountOfYears)
{
    Add2025();
    EXPECT_EQ(cal->getYears().size(), 2);
}

TEST_F(CalendarTestFixture, CheckIfGeneratedCalendarHasCorrectDay)
{
    EXPECT_EQ(cal->getYears().at(0)->getMonths().at(3)->getDays().at(24)->getDayName(), DayName::Thursday);
    EXPECT_EQ(static_cast<unsigned>(cal->getYears().at(0)->getMonths().at(3)->getDays().at(24)->getDayNumber()), 25);
}

TEST_F(CalendarTestFixture, CheckIfGeneratedCalendarHasCorrectAmountOfDaysInJune)
{
    EXPECT_EQ(static_cast<unsigned>(cal->getYears().at(0)->getMonths().at(5)->getDays().size()), 30);
}

TEST_F(CalendarTestFixture, CheckIfGeneratedCalendarFebruaryHasCorrectAmountOfDays)
{
    EXPECT_EQ(static_cast<unsigned>(cal->getYears().at(0)->getMonths().at(1)->getDays().size()), 29);
}

TEST_F(CalendarTestFixture, CheckIfGeneratedCalendarFebruaryHasCorrectAmountOfDays2)
{
    Add2025();
    EXPECT_EQ(static_cast<unsigned>(cal->getYears().at(1)->getMonths().at(1)->getDays().size()), 28);
}

} // namespace
