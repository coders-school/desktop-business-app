#include "day.hpp"

Day::Day(const std::chrono::day& day, const DayName& name) : day_{day}, day_name_{name}
{
}

std::chrono::day Day::getDayNumber()
{
    return day_;
}

DayName Day::getDayName()
{
    return day_name_;
}

void Day::addMonth(const std::shared_ptr<Month>& ptr)
{
    month_ = ptr;
}
std::shared_ptr<Month> Day::getMonth()
{
    return month_;
}
