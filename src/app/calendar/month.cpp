#include "month.hpp"

Month::Month(const std::chrono::month& month) : month_{month}
{
}
std::chrono::month Month::getMonth()
{
    return month_;
}