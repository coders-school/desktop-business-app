#pragma once

#include "../person/person.hpp"

#include <set>

class Visit;

class Doctor : public Person, public std::enable_shared_from_this<Doctor>
{
    std::set<std::shared_ptr<Visit>> visitAssociation_;

  public:
    Doctor(std::string firstName, std::string lastName, std::string pesel);

    void addAssociation(std::shared_ptr<Visit> visit);
    std::set<std::shared_ptr<Visit>> getVisitAssociations();
};