#pragma once

#include <string>

enum class Gender
{
    Male,
    Female,
    Unknown
};

std::string toString(const Gender gender);
Gender toEnum(const std::string&);
