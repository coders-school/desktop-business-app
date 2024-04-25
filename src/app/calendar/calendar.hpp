#pragma once
#include <chrono>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include "day_name.hpp"

class Year;

class Calendar
{
    std::vector<std::shared_ptr<Year>> years_;
    Calendar() = default;

  public:
    static void createCalendar();
    void createYear(const int& year_number,const DayName& first_day_name_of_first_month);
    std::vector<std::shared_ptr<Year>>& getYears();
};