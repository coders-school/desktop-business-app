#include "Staff.hpp"
#include <algorithm>
#include <memory>

namespace clinic
{
namespace staff
{

template <typename Person> typename Person::iterator Staff::getPersonByName(Person& person, const common::Name& name)
{
    return std::find_if(person.begin(), person.end(), [&name](const auto& per) {
        return per->GetPersonalData().getName().first_name_ == name.first_name_ &&
               per->GetPersonalData().getName().last_name_ == name.last_name_;
    });
}

void Staff::addDoctor(doctor::DoctorPtr doctor)
{
    doctors_.emplace_back(std::move(doctor));
}

doctor::iDoctor* Staff::getDoctor(const common::Name& name)
{
    const auto doctor = getPersonByName<std::vector<doctor::DoctorPtr>>(doctors_, name);

    return doctor == doctors_.end() ? nullptr : doctor->get();
}

std::vector<doctor::iDoctor*> Staff::getDoctors()
{
    std::vector<doctor::iDoctor*> doctors;
    std::transform(doctors_.begin(), doctors_.end(), std::back_inserter(doctors),
                   [](const auto& doctor) { return doctor.get(); });

    return doctors;
}

void Staff::addReceptionist(receptionist::ReceptionistPtr receptionist)
{
    receptionists_.emplace_back(std::move(receptionist));
}

receptionist::iReceptionist* Staff::getReceptionist(const common::Name& name)
{
    const auto receptionist = getPersonByName<std::vector<receptionist::ReceptionistPtr>>(receptionists_, name);

    return receptionist == receptionists_.end() ? nullptr : receptionist->get();
}

std::vector<receptionist::iReceptionist*> Staff::getReceptionists()
{
    std::vector<receptionist::iReceptionist*> receptionists;
    std::transform(receptionists_.begin(), receptionists_.end(), std::back_inserter(receptionists),
                   [](const auto& receptionist) { return receptionist.get(); });

    return receptionists;
}

} // namespace staff
} // namespace clinic
