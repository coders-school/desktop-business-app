#pragma once

#include "modules/backend/clinic/staff/doctor/Doctor.hpp"
#include <vector>

namespace clinic
{
namespace staff
{

class Staff
{
    std::vector<doctor::Doctor> doctors_;
    // TODO introduce missing staff members
  public:
    void addDoctor(const doctor::Doctor& doctor);
    std::vector<doctor::Doctor> getDoctors() const;
};

} // namespace staff
} // namespace clinic
