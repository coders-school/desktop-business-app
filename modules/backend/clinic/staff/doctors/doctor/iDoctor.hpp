#pragma once

#include "enumerations/specialization/Specialization.hpp"
#include "personal_data/PersonalData.hpp"
#include <memory>

namespace clinic
{
namespace staff
{
namespace doctor
{

class iDoctor
{
  public:
    virtual ~iDoctor() = default;
    virtual common::PersonalData GetPersonalData() const = 0;
    virtual common::specialization::Specialization GetSpecialization() const = 0;
    virtual void UpdateSpecialization(const common::specialization::Specialization specialization) = 0;
};
  using DoctorPtr = std::unique_ptr<iDoctor>;
} // namespace doctor
} // namespace staff
} // namespace clinic
