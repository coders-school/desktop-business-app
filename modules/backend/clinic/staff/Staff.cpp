#include "Staff.hpp"
#include <algorithm>
#include <memory>

namespace clinic
{
namespace staff
{

template <typename Container>
typename Container::value_type::pointer Staff::getPersonByName(const Container& container,
                                                               const common::Name& name) const
{
    const auto it = std::find_if(container.begin(), container.end(), [&name](const auto& per) {
        const auto container_name = per->GetPersonalData().getName();
        return container_name.first_name_ == name.first_name_ && container_name.last_name_ == name.last_name_;
    });

    return it == container.end() ? nullptr : it->get();
}

void Staff::addDoctor(doctor::DoctorPtr doctor)
{
    doctors_.emplace_back(std::move(doctor));
}

doctor::iDoctor* Staff::getDoctor(const common::Name& name)
{
    return getPersonByName(doctors_, name);
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
    return getPersonByName(receptionists_, name);
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
