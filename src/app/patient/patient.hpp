#pragma once

#include "../person/person.hpp"
#include "allergen.hpp"
#include <algorithm>
#include <memory>
#include <set>
#include <string>
#include <vector>

class Patient : public Person
{
    static std::vector<std::shared_ptr<Patient>> patients_;

    std::set<Allergen> allergens_;
    size_t debt_;

    Patient() = delete;
    Patient(const std::string& name, const std::string& surname, const std::string& pesel,
            const std::set<Allergen>& allergens = {});

  public:
    static std::vector<std::shared_ptr<Patient>> getPatients();
    static std::shared_ptr<Patient> getPatient(const std::string& pesel);
    static std::vector<std::shared_ptr<Patient>> getPatient(const std::string& name, const std::string& surname);
    static void createPatient(const std::string& name, const std::string& surname, const std::string& pesel,
                              const std::set<Allergen>& allergens = {});
    void removePatient();

    std::set<Allergen> getAllergens() const;
    std::string showInformationAboutPatient() const;
    size_t getDebt() const;
    void changePatientInformation();
    void setDebt(const size_t debt);
    void updateAllergens(const std::set<Allergen>& allergens);
};
