#include "Staff.hpp"

void Staff::addDoctor(const Doctor& doctor)
{
    doctors_.emplace_back(doctor);
}

std::vector<Doctor> Staff::getDoctors() const
{
    return doctors_;
}
