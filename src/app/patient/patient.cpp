#include "patient.hpp"

std::vector<std::shared_ptr<Patient>> Patient::patients_;

Patient::Patient(const std::string& name, const std::string& last_name, const std::string& pesel,
                 const std::set<Allergen>& allergens)
    : Person{name, last_name, pesel}, allergens_{allergens}, debt_{}
{
}

std::vector<std::shared_ptr<Patient>> Patient::getPatients()
{
    return patients_;
}

void Patient::removePatient()
{
    patients_.erase(std::remove_if(patients_.begin(), patients_.end(),
                                   [this](const auto& patient_ptr) { return patient_ptr.get() == this; }),
                    patients_.end());
    for (auto it = patients_.begin(); it != patients_.end(); ++it)
    {
        if (*it == nullptr)
        {
            patients_.erase(it);
        }
    }
}

void Patient::createPatient(const std::string& name, const std::string& last_name, const std::string& pesel,
                            const std::set<Allergen>& allergens)
{
    patients_.emplace_back(new Patient(name, last_name, pesel, allergens));
}

std::shared_ptr<Patient> Patient::getPatient(const std::string& pesel)
{
    auto patient = std::find_if(patients_.begin(), patients_.end(),
                                [&pesel](const auto& patient) { return patient->getPesel() == pesel; });

    if (patient != patients_.end())
    {
        return *patient;
    }

    return nullptr;
}

std::vector<std::shared_ptr<Patient>> Patient::getPatient(const std::string& name, const std::string& last_name)
{
    std::vector<std::shared_ptr<Patient>> patients{};

    for (const auto& patient : patients_)
    {
        if ((patient->getFirstName() == name) && (patient->getLastName() == last_name))
        {
            patients.emplace_back(patient);
        }
    }

    return patients;
}

std::string Patient::showInformationAboutPatient() const
{
    // TODO Issue#46
    return "";
}

std::set<Allergen> Patient::getAllergens() const
{
    return allergens_;
}

size_t Patient::getDebt() const
{
    return debt_;
}

void Patient::changePatientInformation()
{
}

void Patient::setDebt(const size_t debt)
{
    debt_ = debt;
}

void Patient::updateAllergens(const std::set<Allergen>& allergens)
{
    for (const auto& allergen : allergens)
    {
        allergens_.insert(allergen);
    }
}
