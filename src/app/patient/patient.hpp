#pragma once

#include "../person/person.hpp"
#include "../visit/visit.hpp"
#include "allergen.hpp"
#include <algorithm>
#include <memory>
#include <optional>
#include <set>
#include <string>
#include <vector>

class Patient : public Person
{
    std::set<std::shared_ptr<Visit>> visits_;
    std::set<Allergen> allergens_;
    size_t debt_;

    Patient(const std::string& name, const std::string& surname, const std::string& pesel,
            const std::set<Allergen>& allergens = {});

  public:
    std::set<std::shared_ptr<Visit>> getVisits() const;
    std::set<Allergen> getAllergens() const;
    std::string showInformationAboutPatient() const;
    size_t getDebt() const;
    void changePatientInformation();
    void addVisit(std::shared_ptr<Visit> visit);
    void setDebt(const size_t debt);
    void updateAllergens(const std::set<Allergen>& allergens);

    static void createPatient(const std::string& name, const std::string& surname, const std::string& pesel,
                              const std::set<Allergen>& allergens = {});
};
