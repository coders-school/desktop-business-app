#include "Allergen.hpp"

namespace common
{
namespace allergen
{

std::string toString(const Allergen shift)
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

Allergen toEnum(const std::string& shift)
{
    if (shift == "Allergen")
    {
        return Allergen::Allergen;
    }
    else if (shift == "AnotherAllergen")
    {
        return Allergen::AnotherAllergen;
    }
    else if (shift == "SomeAllergen")
    {
        return Allergen::SomeAllergen;
    }
    else if (shift == "DifferentAllergen")
    {
        return Allergen::DifferentAllergen;
    }
    else
    {
        return Allergen::Unknown;
    }
}

} // namespace allergen
} // namespace common
