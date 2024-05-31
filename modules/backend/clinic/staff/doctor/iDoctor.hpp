#pragma once

#include "modules/backend/common/enumerations/Specialization.hpp"
#include "modules/backend/common/personal_data/PersonalData.hpp"

namespace clinic
{
namespace staff
{
namespace doctor
{

class iDoctor
{
  public:
    virtual ~iDoctor() = 0;
    virtual PersonalData GetPersonalData() const = 0;
    virtual Specialization GetSpecialization() const = 0;
    virtual void UpdateSpecialization(const Specialization specialization) = 0;
};

} // namespace doctor
} // namespace staff
} // namespace clinic
