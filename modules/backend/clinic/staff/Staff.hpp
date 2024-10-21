#pragma once

#include "doctors/Doctor.hpp"
#include "receptionists/Receptionist.hpp"
#include <vector>

namespace clinic
{
namespace staff
{
using DoctorPtr = doctor::DoctorPtr;
using iDoctor = doctor::iDoctor;
using ReceptionistPtr = receptionist::ReceptionistPtr;
using iReceptionist = receptionist::iReceptionist;

class Staff
{
  public:
    void addDoctor(DoctorPtr doctor);
    iDoctor* getDoctor(const common::Name& name);
    std::vector<iDoctor*> getDoctors() const;

    void addReceptionist(ReceptionistPtr receptionist);
    iReceptionist* getReceptionist(const common::Name& name);
    std::vector<iReceptionist*> getReceptionists() const;

  private:
    template <typename Container>
    typename Container::value_type::pointer getPersonByName(const Container& container, const common::Name& name) const;

    std::vector<DoctorPtr> doctors_;
    std::vector<ReceptionistPtr> receptionists_;
};

} // namespace staff
} // namespace clinic
