#include "receptionist.hpp"
#include "../clinic/clinic_facade.hpp"

Receptionist::Receptionist(const std::string& name, const std::string& surname, const std::string& pesel,
                           const Gender gender)
    : Person{name, surname, pesel, gender}
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

void Receptionist::createReceptionist(const std::string& name, const std::string& surname, const std::string& pesel,
                                      const Gender gender)
{
    Receptionist receptionist{name, surname, pesel, gender};
    Clinic::appendReceptionist(std::make_shared<Receptionist>(receptionist));
}
