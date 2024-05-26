#pragma once
#include <cstdint>
#include <string>

enum class VisitStatus : uint8_t
{
    Canceled = 0,
    Relocated = 1,
    Confirmed = 2,
    Visited = 3
};

std::string toString(VisitStatus status);
