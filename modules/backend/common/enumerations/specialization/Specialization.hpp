#pragma once

#include <cstdint>
#include <string>

namespace common
{

enum class Specialization : uint8_t
{
    Dentist = 0,
    Unknown = 255
};

std::string toString(const Specialization& specialization);

} // namespace common
