#include "patient.hpp"

std::vector<std::shared_ptr<Patient>> Patient::patients_;

Patient::Patient(const std::string name, const std::string last_name, const std::string pesel,
                 const std::unordered_set<Allergent> allergents)
    : Person(name, last_name, pesel), allergents_{allergents}, debt_{}
{
}

void Patient::createPatient(const std::string name, const std::string last_name, const std::string pesel,
                            const std::unordered_set<Allergent> allergents)
{
    auto patient = std::shared_ptr<Patient>(new Patient(name, last_name, pesel, allergents));
    patients_.push_back(patient);
}

std::shared_ptr<Patient> Patient::getPatient(const std::string pesel)
{
    const auto patient =
        std::find_if(patients_.begin(), patients_.end(),
                     [&pesel](const std::shared_ptr<Patient> patient) { return patient->getPesel() == pesel; });

    if (patient != patients_.end())
    {
        return *patient;
    }

    return nullptr;
}

std::shared_ptr<Patient> Patient::getPatient(const std::string name, const std::string last_name)
{
    const auto patient =
        std::find_if(patients_.begin(), patients_.end(), [&name, &last_name](const std::shared_ptr<Patient> patient) {
            return patient->getFirstName() == name && patient->getLastName() == last_name;
        });

    if (patient != patients_.end())
    {
        return *patient;
    }

    return nullptr;
}

std::vector<std::shared_ptr<Patient>> Patient::getPatients()
{
    return patients_;
}

std::string Patient::showInformationAboutPatient() const
{
    // TODO Issue#46
    return "";
}

std::unordered_set<Allergent> Patient::getAllergents() const
{
    return allergents_;
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

void Patient::updateAllergents(const std::unordered_set<Allergent>& allergents)
{
    for (const auto& allergent : allergents)
    {
        allergents_.insert(allergent);
    }
}
