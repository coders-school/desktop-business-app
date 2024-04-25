#pragma once
#include "../person/person.hpp"
#include "shift.hpp"

class Receptionist : public Person
{
    Shift shift_;

    Receptionist(const std::string& name, const std::string& surname, const std::string& pesel, const Gender& gender);

  public:
    std::string getShift() const;
    void setShift(const Shift& shift);

    static void createReceptionist(const std::string& name, const std::string& surname, const std::string& pesel,
                                   const Gender& gender);
};
