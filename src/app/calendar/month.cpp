#include "month.hpp"
#include "day.hpp"

Month::Month(const std::chrono::month& month) : month_{month}
{
}

std::chrono::month Month::getMonth()
{
    return month_;
}

size_t Month::getNumberOfDays(){
    if((static_cast<unsigned>(month_) % 2) == 0){
        if(static_cast<unsigned>(month_) == 2){
            if(year_->getYear().is_leap()){
                return 29;
            }else{
                return 28;
            }
        }else{
            return 30;
        }
    }else{
        return 31;
    }
}

void Month::addYear(const std::shared_ptr<Year>& year){
    year_ = year;
}

void Month::generateDays(const DayName& day_name){
    size_t days_in_month = getNumberOfDays();
    auto month_ptr = shared_from_this();

    DayName next_day_name;
    if(static_cast<unsigned>(getMonth()) == 1){
        next_day_name = day_name;
    }else{
        next_day_name = day_name;
        ++next_day_name;
    }

    for(size_t i = 1; i <= days_in_month; ++i){
        auto day = std::make_shared<Day>(std::chrono::day{static_cast<unsigned>(i)}, next_day_name);
        day->addMonth(month_ptr);
        days_.push_back(day);
    }
}

std::vector<std::shared_ptr<Day>>& Month::getDays(){
    return days_;
}
