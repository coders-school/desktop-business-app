#pragma once

#include "modules/backend/common/enumerations/specialization.hpp"
#include "modules/backend/common/personal_data/personal_data.hpp"

class iDoctor
{
  public:
    virtual ~iDoctor() = 0;
    virtual PersonalData& GetPersonalData() = 0;
    virtual Specialization GetSpecialization() const = 0;
};
