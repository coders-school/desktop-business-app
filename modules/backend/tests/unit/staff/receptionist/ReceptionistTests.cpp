#include "StaffFixture.hpp"

namespace clinic
{
namespace staff
{
TEST_F(StaffFixture, GivenStaffWhenReceptionistAddedExpectCorrectSize)
{
    unit_.addReceptionist(CreateReceptionistMock());

    EXPECT_EQ(unit_.getReceptionists().size(), 1U);
}

TEST_F(StaffFixture, GivenStaffWhenMultipleReceptionistAddedExpectCorrectSize)
{
    unit_.addReceptionist(CreateReceptionistMock());
    unit_.addReceptionist(CreateReceptionistMock());

    EXPECT_EQ(unit_.getReceptionists().size(), 2U);
}

TEST_F(StaffFixture, GivenStaffWhenExactReceptionistQueriedExpectReceptionistFoundAndReturned)
{
    auto receptionist = CreateReceptionistMock();
    EXPECT_CALL(*receptionist, GetPersonalData()).WillOnce(::testing::Return(createTestPersonalData()));
    unit_.addReceptionist(std::move(receptionist));

    EXPECT_NE(unit_.getReceptionist({"Joe", "", ""}), nullptr);
}

TEST_F(StaffFixture, GivenStaffWhenExactReceptionistQueriedExpectReceptionistNotFound)
{
    auto receptionist = CreateReceptionistMock();
    EXPECT_CALL(*receptionist, GetPersonalData()).WillOnce(::testing::Return(createTestPersonalData()));
    unit_.addReceptionist(std::move(receptionist));

    EXPECT_EQ(unit_.getReceptionist({"John", "", ""}), nullptr);
}

TEST_F(StaffFixture, GivenStaffWithMultipleReceptionistsWhenExactReceptionistQueriedExpectReceptionistFoundAndReturned)
{
    auto receptionist = CreateReceptionistMock();
    auto Receptionist2 = CreateReceptionistMock();
    EXPECT_CALL(*receptionist, GetPersonalData()).WillOnce(::testing::Return(createTestPersonalData()));
    EXPECT_CALL(*Receptionist2, GetPersonalData())
        .WillOnce(::testing::Return(createTestPersonalData(common::Name{"John", "", ""})));
    unit_.addReceptionist(std::move(receptionist));
    unit_.addReceptionist(std::move(Receptionist2));

    EXPECT_NE(unit_.getReceptionist({"John", "", ""}), nullptr);
}

} // namespace staff
} // namespace clinic