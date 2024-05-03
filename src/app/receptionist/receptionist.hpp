#pragma once
#include "person.hpp"
#include "shift.hpp"

class Receptionist : public Person
{
    Shift shift_;

    Receptionist(const std::string& name, const std::string& surname, const std::string& pesel);

  public:
    std::string getShift() const;
    void setShift(const Shift& shift);

    static void createReceptionist(const std::string& name, const std::string& surname, const std::string& pesel);
};
