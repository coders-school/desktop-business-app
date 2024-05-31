#pragma once

#include "modules/backend/clinic/staff/doctor/iDoctorSerde.hpp"

namespace clinic
{
namespace staff
{
namespace doctor
{

class Doctor : public iDoctorSerde
{
    PersonalData personal_data_;
    Specialization specialization_;

  public:
    Doctor(const PersonalData& personal_data, const Specialization specialization)
        : personal_data_{personal_data}, specialization_{specialization}
    {
    }

    void Deserialize() override;
    PersonalData GetPersonalData() const override;
    Specialization GetSpecialization() const override;

    void Serialize() override;
    void UpdateSpecialization(const Specialization specialization) override;
};

} // namespace doctor
} // namespace staff
} // namespace clinic