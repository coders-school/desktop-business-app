#include "DoctorMock/DoctorMock.hpp"
#include "staff/Staff.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <memory>

namespace clinic
{
namespace staff
{

class StaffFixture : public ::testing::Test
{
  protected:
    common::PersonalData createTestPersonalData(const common::Name name = {"Joe", "", ""})
    {
        return common::PersonalData{name, common::Address{}, common::Pesel{"80062378532"}, common::PhoneNumber{}};
    }

    std::unique_ptr<::testing::NiceMock<doctor::DoctorMock>> CreateDoctorMock()
    {
        return std::make_unique<::testing::NiceMock<doctor::DoctorMock>>();
    }

    Staff unit_{};
};
} // namespace staff
} // namespace clinic