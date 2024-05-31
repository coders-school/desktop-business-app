#pragma once

#include "modules/backend/staff/doctor/Doctor.hpp"
#include "modules/backend/clinic/staff/iStaff.hpp"
#include <vector>

class Staff : public iStaff
{
    std::vector<Doctor> doctors_;
    // std::vector<Receptionist> receptionists_;
  public:
};
