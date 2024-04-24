#include "calendar_test.hpp"

namespace
{

TEST_F(CalendarTestFixture, GivenChronoYearCheckIfReturnsCorrectYear)
{
    Year yr{std::chrono::year{2024}};
    EXPECT_EQ(static_cast<int>(yr.getYear()), 2024);
}

TEST_F(CalendarTestFixture, GivenChronoMonthCheckIfReturnsCorrectMonth)
{
    Month mth{std::chrono::month{12}};
    EXPECT_EQ(static_cast<unsigned>(mth.getMonth()), 12);
}

TEST_F(CalendarTestFixture, GivenChronoDayCheckIfReturnsCorrectDay)
{
    Day day{std::chrono::day{30}, ""};
    EXPECT_EQ(static_cast<unsigned>(day.getDayNumber()), 30);
}

TEST_F(CalendarTestFixture, GivenStringDayNameCheckIfReturnsCorrectDayName)
{
    Day day{std::chrono::day{10}, "Thursday"};
    EXPECT_EQ(day.getDayName(), "Thursday");
}

} // namespace
