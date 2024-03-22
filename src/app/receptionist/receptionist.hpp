#pragma once
#include "../person/person.hpp"
#include "shift.hpp"

class Receptionist : public Person
{
    Shift shift_;

  public:
    explicit Receptionist(const std::string first_name, const std::string last_name, const std::string pesel);

    std::string getShift() const;
    void setShift(const Shift& shift);
};
