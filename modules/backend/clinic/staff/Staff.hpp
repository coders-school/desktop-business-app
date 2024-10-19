#pragma once

#include "doctors/doctor/Doctor.hpp"

#include <vector>

namespace clinic
{
namespace staff
{

class Staff
{
  public:
    void addDoctor(doctor::DoctorPtr doctor);
    doctor::iDoctor* getDoctor(const common::Name& name);
    std::vector<doctor::iDoctor*> getDoctors() const;

  private:
    template <typename Container>
    typename Container::value_type::pointer getPersonByName(const Container& person, const common::Name& name) const;

    std::vector<doctor::DoctorPtr> doctors_;
};

} // namespace staff
} // namespace clinic
