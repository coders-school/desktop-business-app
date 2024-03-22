#include "receptionist.hpp"

Receptionist::Receptionist(const std::string first_name, const std::string last_name, const std::string pesel)
    : Person{first_name, last_name, pesel}
{
}

std::string Receptionist::getShift() const
{
    return toString(shift_);
}

void Receptionist::setShift(const Shift& shift)
{
    shift_ = shift;
}
