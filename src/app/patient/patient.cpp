#include "patient.hpp"
#include "../clinic/clinic_facade.hpp"

Patient::Patient(const std::string& name, const std::string& surname, const std::string& pesel, const Gender gender,
                 const std::set<Allergen>& allergens)
    : Person{name, surname, pesel, gender}, allergens_{allergens}, debt_{}
{
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
    // TODO Issue#46
}

void Patient::addVisit(const std::shared_ptr<Visit>& visit)
{
    if (!visit)
    {
        throw std::invalid_argument(std::string("Argument points to nullptr in ") + __func__);
    }

    if (visits_.find(visit) == visits_.end())
    {
        visits_.insert(visit);
        visit->setPatient(shared_from_this());
    }
}

void Patient::setDebt(const size_t& debt)
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

void Patient::createPatient(const std::string& name, const std::string& surname, const std::string& pesel,
                            const Gender gender, const std::set<Allergen>& allergens)
{
    Patient patient{name, surname, pesel, gender, allergens};
    Clinic::appendPatient(std::make_shared<Patient>(patient));
}

std::vector<std::shared_ptr<Patient>> Patient::getPatient(const std::string& name, const std::string& surname)
{
    auto all_patients = Clinic::getPatients();
    std::vector<std::shared_ptr<Patient>> patients{};
    for (const auto& patient : Clinic::getPatients())
    {
        if ((patient->getName() == name) && (patient->getSurname() == surname))
        {
            patients.emplace_back(patient);
        }
    }
    return patients;
}

std::shared_ptr<Patient>& Patient::getPatient(const std::string& pesel)
{
    auto patients = Clinic::getPatients();
    auto exact_patient = std::find_if(patients.begin(), patients.end(),
                                      [&](const auto& patient) { return patient->getPesel() == pesel; });

    if (exact_patient != patients.end())
    {
        return *exact_patient;
    }
    else
    {
        throw std::runtime_error("patient not found.");
    }
}
