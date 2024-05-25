#pragma once

#include <cstdint>
#include <string>

enum class Specialization : std::uint8_t
{
    Dentist = 0,
};

std::string toString(const Specialization& specialization)
{
    switch (specialization)
    {
    case Specialization::Dentist:
        return "Dentist";
    default:
        return "Unknown";
    }
}