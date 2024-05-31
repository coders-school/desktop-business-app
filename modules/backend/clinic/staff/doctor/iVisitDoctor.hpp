#pragma once

#include "modules/backend/clinic/staff/doctor/iDoctor.hpp"

class iVisitDoctor : public iDoctor
{
  public:
    virtual ~iVisitDoctor() = 0;
    virtual void GetVists() const = 0;
};
