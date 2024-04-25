#pragma once
#include "year.hpp"

class Day;

class Month : public std::enable_shared_from_this<Month>
{
    std::chrono::month month_;
    std::shared_ptr<Year> year_;
    std::vector<std::shared_ptr<Day>> days_;
    size_t getNumberOfDays();

  public:
    Month(const std::chrono::month& month);
    std::chrono::month getMonth();
    void addYear(const std::shared_ptr<Year>& year);
    void generateDays(const DayName& day_name);
    std::vector<std::shared_ptr<Day>>& getDays();
};