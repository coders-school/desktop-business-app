#pragma once

#include <vector>

class Allergens
{
    // this class should contain allergens container
    // allow to add and remove allergen/s
    // return list of allergens
    // inform (true/false) if queried allergen is present
    std::vector<Allergen> allergens_;

  public:
    // expected methods
    // addAllergen(singular -> Allergen)
    // addAllergen(plural -> set, vector?<Allergen>)
    // checkAllergen(Allergen)
};