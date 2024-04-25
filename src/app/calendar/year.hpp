#pragma once
#include "calendar.hpp"

class Month;

class Year : public std::enable_shared_from_this<Year>
{
    std::chrono::year year_;
    std::vector<std::shared_ptr<Month>> months_;

  public:
    Year(const std::chrono::year& year);
    std::chrono::year getYear();
    void generateMonths(const DayName& first_day_name_of_first_month);
    std::vector<std::shared_ptr<Month>>& getMonths();
};