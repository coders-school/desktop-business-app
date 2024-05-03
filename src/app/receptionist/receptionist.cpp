#include "receptionist.hpp"
#include "clinic_facade.hpp"

Receptionist::Receptionist(const std::string& name, const std::string& surname, const std::string& pesel)
    : Person{name, surname, pesel}
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

void Receptionist::createReceptionist(const std::string& name, const std::string& surname, const std::string& pesel)
{
    Receptionist receptionist{name, surname, pesel};
    Clinic::appendReceptionist(std::make_shared<Receptionist>(receptionist));
}
