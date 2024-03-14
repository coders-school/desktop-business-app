#pragma once

#include "../person/person.hpp"
#include <set>

class Visit;

class Doctor : public Person, public std::enable_shared_from_this<Doctor>
{
    std::set<std::shared_ptr<Visit>> visit_associations_;

  public:
    Doctor(std::string first_name, std::string last_name, std::string pesel);
    void addVisitAssociation(const std::shared_ptr<Visit>& visit);
    std::set<std::shared_ptr<Visit>> getVisitAssociations() const;
};
