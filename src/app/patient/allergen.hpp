#pragma once
#include <string>

enum class Allergen
{
    Allergen = 0,
    AnotherAllergen = 1,
    SomeAllergen = 2,
    DifferentAllergen = 3
};

std::string toString(const Allergen& shift);
