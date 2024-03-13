#pragma once

#include "../person/person.hpp"

#include <unordered_set>

class Visit;

class Doctor : public Person, public std::enable_shared_from_this<Doctor>
{
    std::unordered_set<std::shared_ptr<Visit>> visitAssociation_;

  public:
    Doctor(std::string firstName, std::string lastName, std::string pesel);

    void addAssociation(std::shared_ptr<Visit> visit);
    std::unordered_set<std::shared_ptr<Visit>> getVisitAssociations();
};