#pragma once

#include <cstdint>
#include <string>

namespace common
{

enum class Allergen : uint8_t
{
    Allergen = 0,
    AnotherAllergen = 1,
    SomeAllergen = 2,
    DifferentAllergen = 3,
    Unknown = 255
};

std::string toString(const Allergen& shift)
{
    switch (shift)
    {
    case Allergen::Allergen:
        return "Allergen";
    case Allergen::AnotherAllergen:
        return "AnotherAllergen";
    case Allergen::SomeAllergen:
        return "SomeAllergen";
    case Allergen::DifferentAllergen:
        return "DifferentAllergen";
    default:
        return "Unknown";
    }
}

} // namespace common
