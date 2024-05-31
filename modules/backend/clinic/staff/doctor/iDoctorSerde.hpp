#pragma once

#include "modules/backend/clinic/staff/doctor/iDoctor.hpp"

namespace clinic
{
namespace staff
{
namespace doctor
{

class iDoctorSerde : public iDoctor
{
  public:
    virtual ~iDoctorSerde() = 0;
    virtual void Serialize() = 0;
    virtual void Deserialize() = 0;
};

} // namespace doctor
} // namespace staff
} // namespace clinic
