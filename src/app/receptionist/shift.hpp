#pragma once

#include <map>
#include <string>

enum class Shift
{
    Morning = 0,
    Afternoon = 1
};

std::string toString(const Shift& shift);
