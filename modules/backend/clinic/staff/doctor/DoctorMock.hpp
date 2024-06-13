#pragma once

#include "iDoctor.hpp"
#include <gmock/gmock.h>

namespace clinic
{
namespace staff
{
namespace doctor
{

class DoctorMock : public iDoctor
{
  public:
    MOCK_METHOD(common::PersonalData, GetPersonalData, (), (const, override));
    MOCK_METHOD(common::Specialization, GetSpecialization, (), (const, override));
    MOCK_METHOD(void, UpdateSpecialization, (const common::Specialization specialization), (override));
};

} // namespace doctor
} // namespace staff
} // namespace clinic
