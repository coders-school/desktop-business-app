#pragma once

#include "../person/person.hpp"
#include <vector>

class Visit;

class Doctor : public Person
{
    std::vector<std::shared_ptr<Visit>> visits_;
    Doctor(const std::string& name, const std::string& surname, const std::string& pesel, const Gender gender);

  public:
    void appendVisit(const std::shared_ptr<Visit>& visit);
    void removeVisit(const std::shared_ptr<Visit>& visit);
    std::vector<std::shared_ptr<Visit>> getVisits() const;

    static void createDoctor(const std::string& name, const std::string& surname, const std::string& pesel,
                             const Gender gender);
    static std::vector<std::shared_ptr<Doctor>> getDoctor(const std::string& name, const std::string& surname);
};
