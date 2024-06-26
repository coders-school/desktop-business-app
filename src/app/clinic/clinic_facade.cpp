#include "clinic_facade.hpp"
#include <iostream>

void Clinic::appendDoctor(const std::shared_ptr<Doctor>& doctor)
{
    doctors_.emplace_back(doctor);
}

void Clinic::appendPatient(const std::shared_ptr<Patient>& patient)
{
    patients_.emplace_back(patient);
}

void Clinic::appendVisit()
{
    if (!temp_visit_->getDoctor().expired() && !temp_visit_->getPatient().expired() &&
        !temp_visit_->getRoom().expired())
    {
        visits_.emplace_back(temp_visit_);
        temp_visit_ = nullptr;
    }
}

void Clinic::setTempVisit(const std::shared_ptr<Visit>& visit)
{
    temp_visit_ = visit;
}

void Clinic::appendReceptionist(const std::shared_ptr<Receptionist>& receptionist)
{
    receptionists_.emplace_back(receptionist);
}

void Clinic::appendRoom(const std::shared_ptr<Room>& room)
{
    rooms_.emplace_back(room);
}

void Clinic::appendCalendar(const std::shared_ptr<Calendar>& calendar)
{
    calendar_ = calendar;
}

void Clinic::appendWarehouse(const std::shared_ptr<Warehouse>& warehouse)
{
    warehouse_ = warehouse;
}

std::vector<std::shared_ptr<Doctor>> Clinic::getDoctors()
{
    return doctors_;
}

std::vector<std::shared_ptr<Patient>> Clinic::getPatients()
{
    return patients_;
}

std::vector<std::shared_ptr<Visit>> Clinic::getVisits()
{
    return visits_;
}
std::vector<std::shared_ptr<Receptionist>> Clinic::getReceptionists()
{
    return receptionists_;
}

std::vector<std::shared_ptr<Room>> Clinic::getRooms()
{
    return rooms_;
}

std::shared_ptr<Calendar> Clinic::getCalendar()
{
    return calendar_;
}

std::shared_ptr<Warehouse> Clinic::getWarehouse()
{
    return warehouse_;
}

std::shared_ptr<Visit> Clinic::getTempVisit()
{
    return temp_visit_;
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
    if (visit_it != visits_.end())
    {
        if (!(*visit_it)->getDoctor().expired())
        {
            (*visit_it)->getDoctor().lock()->removeVisit(*visit_it);
        }
        if (!(*visit_it)->getPatient().expired())
        {
            (*visit_it)->getPatient().lock()->removeVisit(*visit_it);
        }
        if (!(*visit_it)->getRoom().expired())
        {
            (*visit_it)->getRoom().lock()->removeVisit(*visit_it);
        }
        visits_.erase(visit_it);
    }
}

void Clinic::removeReceptionist(const std::shared_ptr<Receptionist>& receptionist)
{
    receptionists_.erase(std::remove(receptionists_.begin(), receptionists_.end(), receptionist));
}

void Clinic::removeRoom(const std::shared_ptr<Room>& room)
{
    rooms_.erase(std::remove(rooms_.begin(), rooms_.end(), room));
}

void Clinic::removeCalendar()
{
    calendar_ = nullptr;
}

void Clinic::removeWarehouse()
{
    warehouse_ = nullptr;
}

bool Clinic::doctorExists(const std::string& new_doctor_pesel)
{
    return std::find_if(doctors_.begin(), doctors_.end(),
                        [&new_doctor_pesel](const std::shared_ptr<Doctor>& exist_doctors) {
                            return new_doctor_pesel == exist_doctors->getPesel();
                        }) != doctors_.end();
}

bool Clinic::receptionistExists(const std::string& new_receptionist_pesel)
{
    return std::find_if(receptionists_.begin(), receptionists_.end(),
                        [&new_receptionist_pesel](const std::shared_ptr<Receptionist>& exist_receptionists) {
                            return new_receptionist_pesel == exist_receptionists->getPesel();
                        }) != receptionists_.end();
}
