#include "doctor.hpp"
#include "../clinic/clinic_facade.hpp"
#include "../visit/visit.hpp"
#include <stdexcept>

Doctor::Doctor(const std::string& name, const std::string& surname, const std::string& pesel)
    : Person{name, surname, pesel}
{
}

void Doctor::appendVisit(const std::shared_ptr<Visit>& visit)
{
    visits_.push_back(visit);
}

void Doctor::removeVisit(const std::shared_ptr<Visit>& visit)
{
    visits_.erase(std::remove(visits_.begin(), visits_.end(), visit));
}

std::vector<std::shared_ptr<Visit>> Doctor::getVisits() const
{
    return visits_;
}

void Doctor::createDoctor(const std::string& name, const std::string& surname, const std::string& pesel)
{
    Doctor doctor{name, surname, pesel};
    Clinic::appendDoctor(std::make_shared<Doctor>(doctor));
}

std::shared_ptr<Doctor>& Doctor::getDoctor(const std::string& name, const std::string& surname)
{
    auto doctors = Clinic::getDoctors();
    auto exact_doctor = std::find_if(doctors.begin(), doctors.end(), [&](const std::shared_ptr<Doctor>& doctor) {
        return (doctor->getName() == name) && (doctor->getSurname() == surname);
    });

    if (exact_doctor != doctors.end())
    {
        return *exact_doctor;
    }
    else
    {
        throw std::runtime_error("Doctor not found.");
    }
}
