#include "Staff.hpp"

namespace clinic
{
namespace staff
{

void Staff::addDoctor(const doctor::Doctor& doctor)
{
    doctors_.emplace_back(doctor);
}

std::vector<doctor::Doctor> Staff::getDoctors() const
{
    return doctors_;
}

} // namespace staff
} // namespace clinic
