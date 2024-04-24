#include "calendar_test.hpp"

namespace
{

TEST_F(CalendarTestFixture, GivenChronoYearCheckIfReturnsCorrectYear)
{
    Year yr{std::chrono::year{2024}};
    EXPECT_EQ(static_cast<int>(yr.getYear()), 2024);
}

} // namespace
