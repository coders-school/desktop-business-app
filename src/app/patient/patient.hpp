#pragma once

#include "../person/person.hpp"
#include <algorithm>
#include <memory>
#include <string>
#include <unordered_set>
#include <vector>

enum class Allergent
{
    Allergent = 0,
    AnotherAllergent = 1,
    SomeAllergent = 2,
    DifferentAllergent = 3
};

class Patient : public Person
{
    Patient() = delete;
    Patient(const std::string name, const std::string last_name, const std::string pesel,
            const std::unordered_set<Allergent> allergents);
    static std::vector<std::shared_ptr<Patient>> patients_;

    std::unordered_set<Allergent> allergents_;
    size_t debt_;

  public:
    static void createPatient(const std::string name, const std::string last_name, const std::string pesel,
                              const std::unordered_set<Allergent> allergents);
    static std::shared_ptr<Patient> getPatient(const std::string pesel);
    static std::shared_ptr<Patient> getPatient(const std::string name, const std::string last_name);
    static std::vector<std::shared_ptr<Patient>> getPatients();

    std::string showInformationAboutPatient() const;
    std::unordered_set<Allergent> getAllergents() const;
    size_t getDebt() const;
    void changePatientInformation();
    void setDebt(const size_t debt);
    void updateAllergents(const std::unordered_set<Allergent>& allergents);
};
