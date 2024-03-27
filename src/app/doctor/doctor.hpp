#pragma once

#include "../person/person.hpp"
// #include <set>
#include <vector>
#include <iostream>
class Visit;

class Doctor : public Person, public std::enable_shared_from_this<Doctor>
{
    std::vector<Visit> visits_; // could it be Visit(with copy) or it has to be pointer? (const Visit& ) seems to be impossible 

  public:
    explicit Doctor(std::string first_name, std::string last_name, std::string pesel);
    void addVisitAssociation(const Visit& visit);
    std::vector<Visit> getVisitAssociations() const;
};
