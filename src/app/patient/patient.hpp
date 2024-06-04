#pragma once

#include "allergen.hpp"
#include "person.hpp"
#include "visit.hpp"
#include <memory>
#include <set>
#include <string>

class Patient : public Person, public std::enable_shared_from_this<Patient>
{
    std::set<std::shared_ptr<Visit>> visits_;
    std::set<Allergen> allergens_;
    size_t debt_;

    Patient(const std::string& name, const std::string& surname, const std::string& pesel, const Gender gender,
            const std::set<Allergen>& allergens = {});

  public:
    std::set<std::shared_ptr<Visit>> getVisits() const;
    std::set<Allergen> getAllergens() const;
    std::string showInformationAboutPatient() const;
    size_t getDebt() const;
    void changePatientInformation();

    void addVisit(const std::shared_ptr<Visit>& visit);
    void removeVisit(const std::shared_ptr<Visit>& visit);
    void setDebt(const size_t& debt);
    void updateAllergens(const std::set<Allergen>& allergens);

    static void createPatient(const std::string& name, const std::string& surname, const std::string& pesel,
                              const Gender gender, const std::set<Allergen>& allergens = {});
    static std::vector<std::shared_ptr<Patient>> getPatient(const std::string& name, const std::string& surname);
    static std::shared_ptr<Patient>& getPatient(const std::string& pesel);
};
