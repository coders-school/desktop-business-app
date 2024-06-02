#pragma once

#include "doctor/Doctor.hpp"

#include <vector>

namespace clinic
{
namespace staff
{

class Staff
{
  public:
    void addDoctor(const doctor::Doctor& doctor);
    std::vector<doctor::Doctor> getDoctors() const;

  private:
    std::vector<doctor::Doctor> doctors_;
    // TODO introduce missing staff members
};

} // namespace staff
} // namespace clinic
