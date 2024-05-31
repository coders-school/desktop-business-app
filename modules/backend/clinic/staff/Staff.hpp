#pragma once

#include "modules/backend/clinic/staff/doctor/Doctor.hpp"
#include <vector>

class Staff
{
    std::vector<Doctor> doctors_;
    // TODO introduce missing staff members
  public:
    void addDoctor(const Doctor& doctor);
    std::vector<Doctor> getDoctors() const;
};
