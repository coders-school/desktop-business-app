#pragma once

#include "doctors/doctor/Doctor.hpp"
#include "receptionists/receptionist/Receptionist.hpp"
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

    void addReceptionist(receptionist::ReceptionistPtr receptionist);
    receptionist::iReceptionist* getReceptionist(const common::Name& name);
    std::vector<receptionist::iReceptionist*> getReceptionists();

  private:
    template <typename Container>
    typename Container::value_type::pointer getPersonByName(const Container& person, const common::Name& name) const;

    std::vector<doctor::DoctorPtr> doctors_;
    std::vector<receptionist::ReceptionistPtr> receptionists_;
};

} // namespace staff
} // namespace clinic
