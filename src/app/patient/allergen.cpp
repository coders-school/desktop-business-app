#include "allergen.hpp"

std::string toString(const Allergen& allergen)
{
    std::string allergen_text{};

    switch (allergen)
    {
    case Allergen::Allergen:
        allergen_text = "allergen";
        break;
    case Allergen::AnotherAllergen:
        allergen_text = "another allergen";
        break;
    case Allergen::DifferentAllergen:
        allergen_text = "different allergen";
        break;
    case Allergen::SomeAllergen:
        allergen_text = "some allergen";
        break;
    default:
        break;
    }

    return allergen_text;
}
