#include "doctor.hpp"
#include "../clinic/clinic_facade.hpp"
#include "../visit/visit.hpp"
#include <stdexcept>

Doctor::Doctor(std::string first_name, std::string last_name, std::string pesel) : Person{first_name, last_name, pesel}
{
    Clinic::addObject<Doctor>(std::move(*this));

}


void Doctor::addVisitAssociation(const Visit& visit)
{
    visits_.push_back(visit);
}

std::vector<Visit> Doctor::getVisitAssociations() const
{
    return visits_;
}
