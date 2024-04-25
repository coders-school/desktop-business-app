#pragma once
#include "month.hpp"

class Day
{
    std::chrono::day day_;
    DayName day_name_;
    std::shared_ptr<Month> month_;

  public:
    Day(const std::chrono::day& day, const DayName& name);
    std::chrono::day getDayNumber();
    DayName getDayName();
    void addMonth(const std::shared_ptr<Month>& ptr);
    std::shared_ptr<Month> getMonth();
};