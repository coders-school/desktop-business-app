#include "visit.hpp"
#include "clinic_facade.hpp"
#include "patient.hpp"
#include "room.hpp"
#include <stdexcept>

#include <iostream>

Visit::Visit(const std::shared_ptr<Doctor>& doctor, const std::vector<Treatment>& treatments)
    : doctor_{doctor}, patient_{}, room_{}, treatments_{std::move(treatments)}, visit_information_{}
{
    if (doctor_.expired())
    {
        throw std::runtime_error("Cannot create Visit because doctor is expired!");
    }
}

std::weak_ptr<Doctor> Visit::getDoctor() const
{
    return doctor_;
}

std::weak_ptr<Patient> Visit::getPatient() const
{
    return patient_;
}

std::weak_ptr<Room> Visit::getRoom() const
{
    return room_;
}

std::vector<Treatment> Visit::getTreatments() const
{
    return treatments_;
}

VisitStatus Visit::getStatus() const
{
    return visit_status_;
}

void Visit::setVisitInformation(const std::string& visit_information)
{
    visit_information_ = visit_information;
}

std::string Visit::getVisitInformation() const
{
    return visit_information_;
}

void Visit::updateTreatments(const std::vector<Treatment>& treatments)
{
    treatments_ = treatments;
}

void Visit::setStatus(VisitStatus visit_status)
{
    visit_status_ = visit_status;
}

void Visit::createTempVisit(const std::shared_ptr<Doctor>& doctor)
{
    Visit visit(doctor);
    auto visit_ptr = std::make_shared<Visit>(visit);
    if (visit.doctor_.expired())
    {
        throw std::runtime_error("Cannot create Visit because doctor is expired!");
    }
    else
    {
        visit.doctor_.lock()->appendVisit(visit_ptr);
        Clinic::setTempVisit(visit_ptr);
    }
}

void Visit::createVisit(const std::shared_ptr<Doctor>& doctor, const std::shared_ptr<Patient>& patient,
                        const std::shared_ptr<Room>& room, const std::vector<Treatment>& treatments,
                        const std::string& visit_information)
{
    auto visits = Clinic::getVisits();

    auto visit_it = std::find_if(visits.begin(), visits.end(), [&doctor, &patient, &room](const auto& temp_visit) {
        return temp_visit->getDoctor().lock()->getPesel() == doctor->getPesel() &&
               temp_visit->getPatient().lock()->getPesel() == patient->getPesel() &&
               temp_visit->getRoom().lock()->getRoomNumber() == room->getRoomNumber();
    });

    if (visit_it == visits.end())
    {
        Visit visit(doctor, treatments);
        auto visit_ptr = std::make_shared<Visit>(visit);
        visit_ptr->setPatient(patient);
        visit_ptr->setRoom(room);
        visit_ptr->setVisitInformation(visit_information);
        doctor->appendVisit(visit_ptr);
        patient->addVisit(visit_ptr);
        room->addVisit(visit_ptr);
        Clinic::appendTempVisit(visit_ptr);
        Clinic::appendVisit();
    }
    else
    {
        throw std::runtime_error("Cannot create Visit because it already exists!\n");
    }
}

void Visit::setPatient(const std::shared_ptr<Patient>& patient)
{
    if (!patient_.lock())
    {
        patient_ = patient;
        patient->addVisit(shared_from_this());
    }
}

void Visit::setRoom(const std::shared_ptr<Room>& room)
{
    if (!room_.lock())
    {
        room_ = room;
        room->addVisit(shared_from_this());
    }
}
