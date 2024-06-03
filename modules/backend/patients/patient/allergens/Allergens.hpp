#pragma once

#include "enumerations/allergen/Allergen.hpp"

#include <set>

namespace patient
{

class Allergens
{
  public:
    /*
     * @brief Add allergen to the container
     * @param allergen - allergen to be added
     */
    void addAllergen(const common::Allergen& allergen);

    /*
     * @brief Add set of allergens to the container
     * @param allergens - set of allergens to be added
     */
    void addAllergen(const std::set<common::Allergen>& allergens);

    /*
     * @brief Clear all allergens from the container
     */
    void clearAllergens();

    /*
     * @brief Check if allergen is present in the container
     * @param allergen - allergen to be checked
     * @return true if allergen is present, false otherwise
     */
    bool checkAllergen(const common::Allergen& allergen);

    /*
     * @brief Get all allergens from the container
     * @return set of allergens
     */
    std::set<common::Allergen> getAllergens() const;

    /*
     * @brief Remove allergen from the container
     * @param allergen - allergen to be removed
     */
    void removeAllergen(const common::Allergen& allergen);

  private:
    std::set<common::Allergen> allergens_;
};

} // namespace patient
