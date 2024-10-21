#pragma once

#include "staff/receptionists/iReceptionist.hpp"
#include <gmock/gmock.h>

namespace clinic
{
namespace staff
{
namespace receptionist
{

class ReceptionistMock : public iReceptionist
{
  public:
    MOCK_METHOD(common::PersonalData, GetPersonalData, (), (const, override));
};

} // namespace receptionist
} // namespace staff
} // namespace clinic