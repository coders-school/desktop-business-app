#pragma once

#include "iDoctor.hpp"

namespace clinic
{
namespace staff
{
namespace doctor
{

class iDoctorSerde : public iDoctor
{
  public:
    virtual ~iDoctorSerde() = default;
    virtual void Serialize() = 0;
    virtual void Deserialize() = 0;
};

} // namespace doctor
} // namespace staff
} // namespace clinic
