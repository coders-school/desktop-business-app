#include "clinic_facade.hpp"

void Clinic::appendDoctor(std::shared_ptr<Doctor> doctor)
{
    doctors_.push_back(doctor);
}
void Clinic::appendVisit(std::shared_ptr<Visit> visit)
{
    visits_.push_back(visit);
}
void Clinic::appendReceptionist(std::shared_ptr<Receptionist> receptionist)
{
    receptionists_.push_back(receptionist);
}

std::vector<std::shared_ptr<Doctor>>& Clinic::getDoctors()
{
    return doctors_;
}
std::vector<std::shared_ptr<Visit>>& Clinic::getVisits()
{
    return visits_;
}
std::vector<std::shared_ptr<Receptionist>>& Clinic::getReceptionists()
{
    return receptionists_;
}

void Clinic::removeDoctor(std::shared_ptr<Doctor> doctor)
{
    doctors_.erase(std::remove(doctors_.begin(), doctors_.end(), doctor));
}
void Clinic::removeVisit(std::shared_ptr<Visit> visit)
{
    auto visit_it = std::find(visits_.begin(), visits_.end(), visit);
    (*visit_it)->getDoctor()->removeVisit(*visit_it);
    if (visit_it != visits_.end())
    {
        visits_.erase(visit_it);
    }
}
void Clinic::removeReceptionist(std::shared_ptr<Receptionist> receptionist)
{
    receptionists_.erase(std::remove(receptionists_.begin(), receptionists_.end(), receptionist));
}
