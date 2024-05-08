#include "calendar_test.hpp"

namespace
{

TEST_F(CalendarTestFixture, CreateNewCalendarCheckIfItGivesAnException)
{
    EXPECT_NO_THROW(Calendar::createCalendar());
}

TEST_F(CalendarTestFixture, RemoveCalendarAndCreateTwoCalendarsCheckIfThrowsException)
{
    Clinic::removeCalendar();
    Calendar::createCalendar();
    EXPECT_ANY_THROW(Calendar::createCalendar());
}

} // namespace
