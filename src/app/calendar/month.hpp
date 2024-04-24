#pragma once
#include "year.hpp"

class Day;

class Month
{
    std::chrono::month month_;

  public:
    Month(const std::chrono::month& month);
    std::chrono::month getMonth();
};