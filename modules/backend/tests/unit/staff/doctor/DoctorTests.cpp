#include "../StaffFixture.hpp"

namespace clinic
{
namespace staff
{
TEST_F(StaffFixture, GivenStaffWhenDoctorAddedExpectCorrectSize)
{
    unit_.addDoctor(CreateDoctorMock());

    EXPECT_EQ(unit_.getDoctors().size(), 1U);
}

TEST_F(StaffFixture, GivenStaffWhenMultipleDoctorAddedExpectCorrectSize)
{
    unit_.addDoctor(CreateDoctorMock());
    unit_.addDoctor(CreateDoctorMock());

    EXPECT_EQ(unit_.getDoctors().size(), 2U);
}

TEST_F(StaffFixture, GivenStaffWhenExactDoctorQueriedExpectDoctorFoundAndReturned)
{
    auto doctor = CreateDoctorMock();
    EXPECT_CALL(*doctor, GetPersonalData()).WillOnce(::testing::Return(createTestPersonalData()));
    unit_.addDoctor(std::move(doctor));

    EXPECT_NE(unit_.getDoctor({"Joe", "", ""}), nullptr);
}

TEST_F(StaffFixture, GivenStaffWhenExactDoctorQueriedExpectDoctorNotFound)
{
    auto doctor = CreateDoctorMock();
    EXPECT_CALL(*doctor, GetPersonalData()).WillOnce(::testing::Return(createTestPersonalData()));
    unit_.addDoctor(std::move(doctor));

    EXPECT_EQ(unit_.getDoctor({"John", "", ""}), nullptr);
}

TEST_F(StaffFixture, GivenStaffWithMultipleDoctorsWhenExactDoctorQueriedExpectDoctorFoundAndReturned)
{
    auto doctor = CreateDoctorMock();
    auto doctor2 = CreateDoctorMock();
    EXPECT_CALL(*doctor, GetPersonalData()).WillOnce(::testing::Return(createTestPersonalData()));
    EXPECT_CALL(*doctor2, GetPersonalData())
        .WillOnce(::testing::Return(createTestPersonalData(common::Name{"John", "", ""})));
    unit_.addDoctor(std::move(doctor));
    unit_.addDoctor(std::move(doctor2));

    EXPECT_NE(unit_.getDoctor({"John", "", ""}), nullptr);
}
} // namespace staff
} // namespace clinic