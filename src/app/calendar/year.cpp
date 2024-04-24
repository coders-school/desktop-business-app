#include "year.hpp"
#include "month.hpp"

Year::Year(const std::chrono::year& year) : year_{year}
{
}

std::chrono::year Year::getYear(){
    return year_;
}