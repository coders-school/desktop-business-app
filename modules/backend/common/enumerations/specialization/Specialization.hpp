#pragma once

#include <cstdint>
#include <string>

namespace common
{
namespace specialization
{

enum class Specialization : uint8_t
{
    Dentist = 0,
    Unknown = 255
};

std::string toString(const Specialization& specialization);
Specialization toEnum(const std::string& specialization);

} // namespace specialization
} // namespace common
