#include "doctor.hpp"
#include "../visit/visit.hpp"
#include <stdexcept>

Doctor::Doctor(std::string firstName, std::string lastName, std::string pesel) : Person(firstName, lastName, pesel)
{
}

void Doctor::addAssociation(std::shared_ptr<Visit> visit)
{
    if (visit == nullptr)
    {
        throw std::invalid_argument("Argument points to nullptr");
    }
    if (visitAssociation_.find(visit) == visitAssociation_.end())
    {
        visitAssociation_.insert(visit);
        visit->setAssociation(shared_from_this());
    }
}

std::set<std::shared_ptr<Visit>> Doctor::getVisitAssociations()
{
    return visitAssociation_;
}