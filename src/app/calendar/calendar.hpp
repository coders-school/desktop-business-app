#pragma once
#include <chrono>
#include <memory>
#include <string>
#include <vector>

class Year;

class Calendar
{
    std::vector<std::shared_ptr<Year>> years_;
    Calendar() = default;

  public:
    static void createCalendar();
    //void createYear(int year_number, int month_begin, int month_end, std::string first_day_name_of_first_month);
};