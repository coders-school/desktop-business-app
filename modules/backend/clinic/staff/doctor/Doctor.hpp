#pragma once

#include "iDoctorSerde.hpp"
#include "personal_data/PersonalData.hpp"

namespace clinic
{
namespace staff
{
namespace doctor
{

class Doctor : public iDoctorSerde
{
    using PersonalData = common::PersonalData;
    using Specialization = common::specialization::Specialization;

  public:
    Doctor(const PersonalData& personal_data, const Specialization specialization);

    void Deserialize() override;
    PersonalData GetPersonalData() const override;
    Specialization GetSpecialization() const override;

    void Serialize() override;
    void UpdateSpecialization(const Specialization specialization) override;

  private:
    PersonalData personal_data_;
    Specialization specialization_;
};

} // namespace doctor
} // namespace staff
} // namespace clinic
