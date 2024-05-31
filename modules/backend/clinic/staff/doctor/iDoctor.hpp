#pragma once

#include "modules/backend/common/enumerations/Specialization.hpp"
#include "modules/backend/common/personal_data/PersonalData.hpp"

class iDoctor
{
  public:
    virtual ~iDoctor() = 0;
    virtual PersonalData& GetPersonalData() = 0;
    virtual Specialization GetSpecialization() const = 0;
};
