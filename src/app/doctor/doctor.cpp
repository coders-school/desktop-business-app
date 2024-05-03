#include "doctor.hpp"
#include "clinic_facade.hpp"
#include "visit.hpp"

Doctor::Doctor(const std::string& name, const std::string& surname, const std::string& pesel)
    : Person{name, surname, pesel}
{
}

void Doctor::appendVisit(const std::shared_ptr<Visit>& visit)
{
    visits_.emplace_back(visit);
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

std::vector<std::shared_ptr<Doctor>> Doctor::getDoctor(const std::string& name, const std::string& surname)
{
    std::vector<std::shared_ptr<Doctor>> doctors{};
    for (const auto& doctor : Clinic::getDoctors())
    {
        if ((doctor->getName() == name) && (doctor->getSurname() == surname))
        {
            doctors.emplace_back(doctor);
        }
    }
    return doctors;
}
