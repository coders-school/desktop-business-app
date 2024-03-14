#include "doctor.hpp"
#include "../visit/visit.hpp"
#include <stdexcept>

Doctor::Doctor(std::string first_name, std::string last_name, std::string pesel) : Person{first_name, last_name, pesel}
{
}

void Doctor::addVisitAssociation(const std::shared_ptr<Visit>& visit)
{
    if (!visit)
    {
        throw std::invalid_argument(std::string("Argument points to nullptr in ") + __func__);
    }
    if (visit_associations_.find(visit) == visit_associations_.end())
    {
        visit_associations_.insert(visit);
        visit->setDoctorAssociation(shared_from_this());
    }
}

std::set<std::shared_ptr<Visit>> Doctor::getVisitAssociations() const
{
    return visit_associations_;
}
