#pragma once

#include "modules/backend/common/enumerations/specialization.hpp"
class iDoctor
{
  public:
    virtual ~iDoctor() = 0;
    virtual Specialization getSpecialization() const = 0;
};
