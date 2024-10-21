#pragma once

#include "iDoctor.hpp"

namespace clinic
{
namespace staff
{
namespace doctor
{

class Doctor : public iDoctor
{
    using PersonalData = common::PersonalData;
    using Specialization = common::specialization::Specialization;

  public:
    Doctor(const PersonalData& personal_data, const Specialization specialization);

    PersonalData GetPersonalData() const override;
    Specialization GetSpecialization() const override;

    void UpdateSpecialization(const Specialization specialization) override;

  private:
    PersonalData personal_data_;
    Specialization specialization_;
};

} // namespace doctor
} // namespace staff
} // namespace clinic
