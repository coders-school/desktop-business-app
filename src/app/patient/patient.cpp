#include "patient.hpp"

std::vector<Patient> Patient::patients_{};

Patient::Patient(const std::string& name, const std::string& last_name, const std::string& pesel,
                 const std::set<Allergen>& allergens)
    : Person{name, last_name, pesel}, allergens_{allergens}, debt_{}
{
}

void Patient::removePatient(const std::string& pesel)
{
    auto it = std::remove_if(patients_.begin(), patients_.end(),
                             [&pesel](const Patient& patient) { return patient.getPesel() == pesel; });

    if (it != patients_.end())
    {
        patients_.erase(it, patients_.end());
    }
}

void Patient::createPatient(std::string& name, const std::string& last_name, std::string& pesel,
                            const std::set<Allergen>& allergens)
{
    patients_.emplace_back(Patient(name, last_name, pesel, allergens));
}

std::vector<Patient>& Patient::getPatients()
{
    return patients_;
}

std::optional<Patient> Patient::getPatient(const std::string& pesel)
{
    auto patient = std::find_if(patients_.begin(), patients_.end(),
                                [&pesel](const auto& patient) { return patient.getPesel() == pesel; });

    if (patient != patients_.end())
    {
        return *patient;
    }

    return {};
}

std::vector<Patient> Patient::getPatient(const std::string& name, const std::string& last_name)
{
    std::vector<Patient> patients{};

    for (const auto& patient : patients_)
    {
        if ((patient.getFirstName() == name) && (patient.getLastName() == last_name))
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

std::set<std::shared_ptr<Visit>> Patient::getVisits() const
{
    return visits_;
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

void Patient::addVisit(std::shared_ptr<Visit> visit)
{

    if (!visit)
    {
        throw std::invalid_argument(std::string("Argument points to nullptr in ") + __func__);
    }

    if (visits_.find(visit) == visits_.end())
    {
        visits_.insert(visit);
    }
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
