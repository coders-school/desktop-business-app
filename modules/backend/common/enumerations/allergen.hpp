#pragma once

#include <cstdint>
#include <string>

enum class Allergen : std::uint8_t
{
    Allergen = 0,
    AnotherAllergen = 1,
    SomeAllergen = 2,
    DifferentAllergen = 3
};

std::string toString(const Allergen& shift);
