#pragma once

#include "enumerations/allergen/Allergen.hpp"

#include <set>

namespace patient
{

class Allergens
{
  using Allergen = common::allergen::Allergen;

  public:
    /*
     * @brief Add allergen to the container
     * @param allergen - allergen to be added
     */
    void addAllergen(const Allergen& allergen);

    /*
     * @brief Add set of allergens to the container
     * @param allergens - set of allergens to be added
     */
    void addAllergen(const std::set<Allergen>& allergens);

    /*
     * @brief Clear all allergens from the container
     */
    void clearAllergens();

    /*
     * @brief Check if allergen is present in the container
     * @param allergen - allergen to be checked
     * @return true if allergen is present, false otherwise
     */
    bool checkAllergen(const Allergen& allergen);

    /*
     * @brief Get all allergens from the container
     * @return set of allergens
     */
    std::set<Allergen> getAllergens() const;

    /*
     * @brief Remove allergen from the container
     * @param allergen - allergen to be removed
     */
    void removeAllergen(const Allergen& allergen);

  private:
    std::set<Allergen> allergens_;
};

} // namespace patient
