#pragma once
#include "calendar.hpp"

class Month;

class Year {
    std::chrono::year year_;

public:
    Year(const std::chrono::year& year);
    std::chrono::year getYear();
};