#include "Allergen.hpp"

namespace common
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
} // namespace common
