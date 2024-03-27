#include "visit.hpp"
#include "../clinic/clinic_facade.hpp"
#include "../doctor/doctor.hpp"

Visit::Visit(Doctor& doctor) : doctor_{doctor}
{
    doctor_.addVisitAssociation(*this);
    Clinic::addObject(std::move(*this));
}
Visit& Visit::operator=(const Visit& other)
    {
      if(this != &other)
      {
        doctor_ = other.doctor_;
      }

    return *this;
    }
// void Visit::setDoctorAssociation(const std::shared_ptr<Doctor>& doctor)
// {
//     if (!doctor_association_)
//     {
//         doctor_association_ = {doctor};
//         doctor_association_->addVisitAssociation(shared_from_this());
//     }
// }

Doctor Visit::getDoctor() const
{
    return doctor_;
}

void Visit::setVisitInformation(const std::string& visit_information)
{
    visit_information_ = visit_information;
}

std::string Visit::getVisitInformation() const
{
    return visit_information_;
}
