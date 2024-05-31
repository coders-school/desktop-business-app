#pragma once

#include "modules/backend/clinic/staff/doctor/iVisitDoctor.hpp"
#include "modules/backend/clinic/staff/doctor/iSerdeDoctor.hpp"

class Doctor : public iVisitDoctor, public iSerdeDoctor
{
    PersonalData personal_data_;
    Specialization specialization_;

  public:
    Doctor(const PersonalData& personal_data, const Specialization specialization) : personal_data_{personal_data}, specialization_{specialization}
    {
    }
    PersonalData& GetPersonalData() override
    {
      return personal_data_;
    }
    Specialization GetSpecialization() const override
    {
      return specialization_;
    }
};
