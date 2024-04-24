#pragma once
#include "month.hpp"

class Day{
    std::chrono::day day_;
    std::string day_name_;

public:
    Day(const std::chrono::day& day, const std::string& name);
    std::chrono::day getDayNumber();
    std::string getDayName();
};