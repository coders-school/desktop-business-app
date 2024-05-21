#pragma once

#include <string>
#include <cstdint>

<<<<<<< HEAD
=======

>>>>>>> 4c95576 (Besides minor corrections:)
enum class Gender : uint8_t
{
    Male = 0,
    Female = 1,
    Unknown = 255
};

std::string toString(const Gender gender);
Gender toEnum(const std::string&);
