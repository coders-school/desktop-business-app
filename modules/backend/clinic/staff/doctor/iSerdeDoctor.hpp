#pragma once

#include "modules/backend/clinic/staff/doctor/iDoctor.hpp"

class iSerdeDoctor : public iDoctor
{
  public:
    virtual ~iSerdeDoctor() = 0;
    virtual void Serialize() const = 0;
    virtual void Deserialize() = 0;
};
