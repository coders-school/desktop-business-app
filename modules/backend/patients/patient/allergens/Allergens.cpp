#include "Allergens.hpp"
#include <algorithm>

namespace patient
{

void Allergens::addAllergen(const Allergen& allergen)
{
    allergens_.insert(allergen);
}

void Allergens::addAllergen(const std::set<Allergen>& allergens)
{
    allergens_.insert(allergens.begin(), allergens.end());
}

void Allergens::clearAllergens()
{
    allergens_.clear();
}

bool Allergens::checkAllergen(const Allergen& allergen)
{
    return std::find(allergens_.begin(), allergens_.end(), allergen) != allergens_.end();
}

std::set<Allergen> Allergens::getAllergens() const
{
    return allergens_;
}

void Allergens::removeAllergen(const Allergen& allergen)
{
    allergens_.erase(allergen);
}

} // namespace patient
