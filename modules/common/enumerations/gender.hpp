#pragma once

#include <cstdint>

enum class Gender : std::uint8_t
{
    Male = 0,
    Female = 1,
    Unknown = 255
};