#include "doctor.hpp"
#include "../clinic/clinic_facade.hpp"
#include "../visit/visit.hpp"
#include <stdexcept>

Doctor::Doctor(std::string name, std::string surname, std::string pesel) : Person{name, surname, pesel}
{
}

void Doctor::appendVisit(const std::shared_ptr<Visit>& visit)
{
    visits_.push_back(visit);
}

void Doctor::removeVisit(const std::shared_ptr<Visit>& visit)
{
    visits_.erase(std::remove(visits_.begin(), visits_.end(), visit));
}

std::vector<std::shared_ptr<Visit>> Doctor::getVisits() const
{
    return visits_;
}

void Doctor::createDoctor(std::string name, std::string surname, std::string pesel)
{
    Doctor doctor{name, surname, pesel};
    Clinic::appendDoctor(std::make_shared<Doctor>(doctor));
}
