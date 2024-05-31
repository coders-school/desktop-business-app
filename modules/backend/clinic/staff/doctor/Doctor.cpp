#include "Doctor.hpp"

namespace clinic
{
namespace staff
{
namespace doctor
{

PersonalData Doctor::GetPersonalData() const
{
    return personal_data_;
}

Specialization Doctor::GetSpecialization() const
{
    return specialization_;
}

void Doctor::Serialize()
{
    // TODO Serialization logic
}

void Doctor::Deserialize()
{
    // TODO Deserialization logic
}

void Doctor::UpdateSpecialization(const Specialization specialization)
{
    specialization_ = specialization;
}

} // namespace doctor
} // namespace staff
} // namespace clinic