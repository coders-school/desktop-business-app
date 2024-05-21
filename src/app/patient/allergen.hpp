#pragma once

#include <string>
#include <cstdint>

enum class Allergen : uint8_t
{
    Allergen = 0,
    AnotherAllergen = 1,
    SomeAllergen = 2,
    DifferentAllergen = 3
};

std::string toString(const Allergen& shift);
