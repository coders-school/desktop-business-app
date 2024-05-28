#pragma once

#include <cstdint>
#include <string>

enum class Gender : uint8_t
{
    Male = 0,
    Female = 1,
    Unknown = 255
};

std::string toString(const Gender& gender)
{
    switch(gender)
    {
        case Gender::Male:
            return "Male";
        case Gender::Female:
            return "Female";
        default:
            return "Unknown";
    }
}