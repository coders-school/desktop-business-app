#pragma once

#include "../person/person.hpp"
#include <vector>

class Visit;

class Doctor : public Person
{
    std::vector<std::shared_ptr<Visit>> visits_;
    explicit Doctor(std::string name, std::string surname, std::string pesel);

  public:
    void appendVisit(const std::shared_ptr<Visit>& visit);
    void removeVisit(const std::shared_ptr<Visit>& visit);
    std::vector<std::shared_ptr<Visit>> getVisits() const;

    static void createDoctor(std::string name, std::string surname, std::string pesel);
};
