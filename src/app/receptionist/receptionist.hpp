#pragma once
#include "../person/person.hpp"
#include "shift.hpp"

class Receptionist : public Person
{
    Shift shift_;

    explicit Receptionist(const std::string name, const std::string surname, const std::string pesel);

  public:
    std::string getShift() const;
    void setShift(const Shift& shift);

    static void createReceptionist(std::string name, std::string surname, std::string pesel);
};
