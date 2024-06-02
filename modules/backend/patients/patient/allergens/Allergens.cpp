#include "Allergens.hpp"

#include <algorithm>

namespace patient
{

void Allergens::addAllergen(const common::Allergen& allergen)
{
    allergens_.insert(allergen);
}

void Allergens::addAllergen(const std::set<common::Allergen>& allergens)
{
    allergens_.insert(allergens.begin(), allergens.end());
}

void Allergens::clearAllergens()
{
    allergens_.clear();
}

bool Allergens::checkAllergen(const common::Allergen& allergen)
{
    return std::find(allergens_.begin(), allergens_.end(), allergen) != allergens_.end();
}

std::set<common::Allergen> Allergens::getAllergens() const
{
    return allergens_;
}

void Allergens::removeAllergen(const common::Allergen& allergen)
{
    allergens_.erase(allergen);
}

} // namespace patient
