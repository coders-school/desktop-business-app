#include "clinic_facade.hpp"

void Clinic::appendDoctor(const std::shared_ptr<Doctor>& doctor)
{
    doctors_.push_back(doctor);
}

void Clinic::appendPatient(const std::shared_ptr<Patient>& patient)
{
    patients_.push_back(patient);
}

void Clinic::appendVisit(const std::shared_ptr<Visit>& visit)
{
    visits_.push_back(visit);
}

void Clinic::appendReceptionist(const std::shared_ptr<Receptionist>& receptionist)
{
    receptionists_.push_back(receptionist);
}

std::vector<std::shared_ptr<Doctor>>& Clinic::getDoctors()
{
    return doctors_;
}

std::vector<std::shared_ptr<Patient>>& Clinic::getPatients()
{
    return patients_;
}

std::vector<std::shared_ptr<Visit>>& Clinic::getVisits()
{
    return visits_;
}
std::vector<std::shared_ptr<Receptionist>>& Clinic::getReceptionists()
{
    return receptionists_;
}

void Clinic::removeDoctor(const std::shared_ptr<Doctor>& doctor)
{
    doctors_.erase(std::remove(doctors_.begin(), doctors_.end(), doctor));
}

void Clinic::removePatient(const std::shared_ptr<Patient>& patient)
{
    patients_.erase(std::remove(patients_.begin(), patients_.end(), patient));
}

void Clinic::removeVisit(const std::shared_ptr<Visit>& visit)
{
    auto visit_it = std::find(visits_.begin(), visits_.end(), visit);
    (*visit_it)->getDoctor()->removeVisit(*visit_it);
    if (visit_it != visits_.end())
    {
        visits_.erase(visit_it);
    }
}

void Clinic::removeReceptionist(const std::shared_ptr<Receptionist>& receptionist)
{
    receptionists_.erase(std::remove(receptionists_.begin(), receptionists_.end(), receptionist));
}
