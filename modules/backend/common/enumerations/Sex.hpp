#pragma once

#include <cstdint>
#include <string>

namespace common
{
    
enum class Sex : uint8_t
{
    Female = 0,
    Male = 1,
};

std::string toString(const Sex& sex)
{
    switch (sex)
    {
    case Sex::Male:
        return "Male";
    case Sex::Female:
        return "Female";
    default:
        return;
    }
}

} // namespace common
