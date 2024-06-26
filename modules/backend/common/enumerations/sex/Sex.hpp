#pragma once

#include <cstdint>
#include <string>

namespace common
{

namespace sex
{

enum class Sex : uint8_t
{
    Female = 0,
    Male = 1,
};

std::string toString(const Sex& sex);
Sex toEnum(const std::string& sex);

} // namespace sex
} // namespace common
