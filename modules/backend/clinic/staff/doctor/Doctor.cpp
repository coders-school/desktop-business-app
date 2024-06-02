#include "Doctor.hpp"

namespace clinic
{
namespace staff
{
namespace doctor
{

Doctor::Doctor(const common::PersonalData& personal_data, const common::Specialization specialization)
    : personal_data_{personal_data}, specialization_{specialization}
{
}

common::PersonalData Doctor::GetPersonalData() const
{
    return personal_data_;
}

common::Specialization Doctor::GetSpecialization() const
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

void Doctor::UpdateSpecialization(const common::Specialization specialization)
{
    specialization_ = specialization;
}

} // namespace doctor
} // namespace staff
} // namespace clinic
