#pragma once

#include "doctor/Doctor.hpp"
#include "receptionist/Receptionist.hpp"

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
    std::vector<doctor::iDoctor*> getDoctors();

    void addReceptionist(receptionist::ReceptionistPtr receptionist);
    receptionist::iReceptionist* getReceptionist(const common::Name& name);
    std::vector<receptionist::iReceptionist*> getReceptionists();

  private:
    template <typename Person> typename Person::iterator getPersonByName(Person& person, const common::Name& name);

    std::vector<doctor::DoctorPtr> doctors_;
    std::vector<receptionist::ReceptionistPtr> receptionists_;
};

} // namespace staff
} // namespace clinic
