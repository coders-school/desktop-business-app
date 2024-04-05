#include "patient.hpp"
#include "../clinic/clinic_facade.hpp"

Patient::Patient(const std::string& name, const std::string& surname, const std::string& pesel,
                 const std::set<Allergen>& allergens)
    : Person{name, surname, pesel}, allergens_{allergens}, debt_{}
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
                            const std::set<Allergen>& allergens)
{
    Patient patient{name, surname, pesel, allergens};
    Clinic::appendPatient(std::make_shared<Patient>(patient));
}
