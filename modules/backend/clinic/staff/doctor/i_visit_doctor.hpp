#pragma once

#include "i_doctor.hpp"

class iVisitDoctor : public iDoctor
{
  public:
    virtual ~iVisitDoctor() = 0;
    virtual void getVists() const = 0;
};
