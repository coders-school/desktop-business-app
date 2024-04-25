#include "year.hpp"
#include "day.hpp"
#include "month.hpp"

Year::Year(const std::chrono::year& year) : year_{year}
{
}

std::chrono::year Year::getYear()
{
    return year_;
}

void Year::generateMonths(const DayName& first_day_name_of_first_month)
{
    auto year_ptr = shared_from_this();
    for (size_t i = 1; i <= 12; ++i)
    {
        auto month_ptr = std::make_shared<Month>(std::chrono::month{static_cast<unsigned>(i)});
        month_ptr->addYear(year_ptr);
        if (static_cast<unsigned>(month_ptr->getMonth()) == 1)
        {
            month_ptr->generateDays(first_day_name_of_first_month);
        }
        else
        {
            if (!months_.empty())
            {
                month_ptr->generateDays(months_.back()->getDays().back()->getDayName());
            }
        }
        months_.push_back(month_ptr);
    }
}

std::vector<std::shared_ptr<Month>>& Year::getMonths()
{
    return months_;
}
