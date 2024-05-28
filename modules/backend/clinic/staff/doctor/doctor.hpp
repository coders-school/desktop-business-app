#pragma once

#include "modules/backend/common/person/personal_data.hpp"
#include "modules/backend/common/enumerations/specialization.hpp"
#include "i_visit_doctor.hpp"

class Doctor : public iDoctor
{
    PersonalData personal_data_;
    Specialization specialization_;

  public:
    Doctor(const PersonalData& personal_data, const Specialization specialization) : personal_data_{personal_data}, specialization_{specialization}
    {
    }
    PersonalData& getPersonalData()
    {
      return personal_data_;
    }
    Specialization getSpecialization() const override
    {
      return specialization_;
    }
};
