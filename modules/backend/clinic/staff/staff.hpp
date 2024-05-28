#pragma once

#include "staff/doctor/doctor.hpp"
#include "i_staff.hpp"
#include <vector>

class Staff : public iStaff
{
    std::vector<Doctor> doctors_;
    // std::vector<Receptionist> receptionists_;
  public:
};
