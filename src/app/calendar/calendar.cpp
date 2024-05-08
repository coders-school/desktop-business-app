#include "calendar.hpp"
#include "clinic_facade.hpp"
#include <iostream>

void Calendar::createCalendar()
{
    if (!Clinic::getCalendar())
    {
        Clinic::appendCalendar(std::make_shared<Calendar>());
    }
    else
    {
        throw std::length_error("There cannot be more than one calendar");
    }
}
void Calendar::addConnector(const std::chrono::year_month_day& ymd, const std::shared_ptr<Room>& room,
                            const std::shared_ptr<Doctor>& doctor)
{
    if (!room || !doctor)
    {
        throw std::invalid_argument("Invalid room or doctor provided");
    }
    map_calendar_.emplace(ymd, Connector{ymd, room, doctor});
}
