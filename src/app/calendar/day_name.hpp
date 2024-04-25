#pragma once
#include <string>
#include <cstdint> 

enum class DayName : uint32_t{
    Monday = 1,
    Tuesday = 2,
    Wednesday = 3,
    Thursday = 4,
    Friday = 5,
    Saturday = 6,
    Sunday = 7
};

std::string toString(const DayName& day_name);
DayName& operator++(DayName& d);