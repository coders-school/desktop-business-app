#include "day.hpp"

Day::Day(const std::chrono::day& day, const std::string& name) : day_{day}, day_name_{name}
{
}

std::chrono::day Day::getDayNumber(){
    return day_;
}

std::string Day::getDayName(){
    return day_name_;
}
