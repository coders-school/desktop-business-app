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
  private:
    common::PersonalData personal_data_;
    common::Specialization specialization_;

  public:
    Doctor(const common::PersonalData& personal_data, const common::Specialization specialization);

    void Deserialize() override;
    common::PersonalData GetPersonalData() const override;
    common::Specialization GetSpecialization() const override;

    void Serialize() override;
    void UpdateSpecialization(const common::Specialization specialization) override;
};

} // namespace doctor
} // namespace staff
} // namespace clinic
