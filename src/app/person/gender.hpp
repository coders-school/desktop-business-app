#pragma once

#include <string>

enum class Gender : uint8_t
{
    Male = 0,
    Female = 1,
    Unknown = 255
};

std::string toString(const Gender gender);
Gender toEnum(const std::string&);
