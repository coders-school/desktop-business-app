#include "visit.hpp"
#include "clinic_facade.hpp"
#include "patient.hpp"
#include "room.hpp"
#include <stdexcept>

Visit::Visit(const std::shared_ptr<Doctor>& doctor, const std::vector<Treatment>& treatments)
    : doctor_{doctor}, patient_{}, room_{}, treatments_{std::move(treatments)}, visit_information_{}
{
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

void Visit::createVisit(const std::shared_ptr<Doctor>& doctor)
{
    Visit visit(doctor);
    auto visit_ptr = std::make_shared<Visit>(visit);
    if (visit.doctor_.expired())
    {
        throw std::runtime_error("Cannot create Visit because doctor is expired!");
    }
    else
    {
        visit.doctor_.lock()->appendVisit(visit_ptr); // does it need to checkced by expired()?
        Clinic::appendVisit(visit_ptr);
    }
}

void Visit::setPatient(const std::shared_ptr<Patient>& patient)
{
    if (patient_.lock() == nullptr)
    {
        patient_ = patient;
        patient->addVisit(shared_from_this());
    }
}

void Visit::setRoom(const std::shared_ptr<Room>& room)
{
    if (room_.expired() == false)
    {
        if (room_.lock() == nullptr)
        {
            room_ = room;
            room->addVisit(shared_from_this());
        }
    }
}
