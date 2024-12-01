#include "TimeSlot.hpp"
#include "VisitMock/VisitMock.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace calendar
{
namespace tests
{

constexpr auto date20240101time12oclock = 1704062400;
constexpr auto test_duration = 30;

using TimeSlot = calendar::TimeSlot;

class TimeSlotTestsFixture : public ::testing::Test
{
  public:
    std::chrono::time_point<std::chrono::system_clock> time_point_;
    std::chrono::minutes duration_;
    StrictMockVisit visit_mock_;

    void SetUp() override
    {
        time_point_ = std::chrono::system_clock::from_time_t(date20240101time12oclock);
        duration_ = std::chrono::minutes{test_duration};
    }
};

TEST_F(TimeSlotTestsFixture, GivenTimeSlotDefaultConstructedExpectgetDurationEqualTestDuration)
{
    TimeSlot time_slot(time_point_, duration_);
    const auto expected_duration = std::chrono::minutes{test_duration};

    EXPECT_EQ(time_slot.getDuration(), expected_duration);
}

TEST_F(TimeSlotTestsFixture, GivenTimeSlotDefaultConstructedWhenAssignedVisitExpectVisitCalled)
{
    EXPECT_CALL(visit_mock_, getPayment()).Times(1);

    TimeSlot time_slot(time_point_, duration_);
    time_slot.assignVisit(&visit_mock_);
    time_slot.getVisit()->getPayment();
}

TEST_F(TimeSlotTestsFixture, GivenTimeSlotConstructedWithVisitWhenAssignedVisitExpectVisitCalled)
{
    EXPECT_CALL(visit_mock_, getPayment()).Times(1);

    TimeSlot time_slot(time_point_, duration_, &visit_mock_);
    time_slot.getVisit()->getPayment();
}

TEST_F(TimeSlotTestsFixture, GiveTimeSlotWhenDurationChangeExpectCorrectDuration)
{
    const auto expected_duration = std::chrono::minutes{test_duration * 2};
    TimeSlot time_slot(time_point_, duration_);

    time_slot.changeDuration(expected_duration);

    EXPECT_EQ(time_slot.getDuration(), expected_duration);
}

TEST_F(TimeSlotTestsFixture, GivenTimeSlotsWithDifferentTimePointsExpectValidComparison)
{
    const auto expected_duration = std::chrono::minutes{test_duration * 2};
    TimeSlot time_slot1(time_point_, duration_);
    TimeSlot time_slot2(time_point_ + expected_duration, expected_duration);

    EXPECT_TRUE(time_slot1 < time_slot2);
}

TEST_F(TimeSlotTestsFixture, GivenTimeSlotsWithDifferentTimePointsExpectNotValidComparison)
{
    const auto expected_duration = std::chrono::minutes{test_duration * 2};
    TimeSlot time_slot1(time_point_, duration_);
    TimeSlot time_slot2(time_point_ + expected_duration, expected_duration);

    EXPECT_FALSE(time_slot1 > time_slot2);
}

TEST_F(TimeSlotTestsFixture, GivenTimeSlotsWithDifferentTimePointsExpectNotEqual)
{
    const auto expected_duration = std::chrono::minutes{test_duration * 2};
    TimeSlot time_slot1(time_point_, duration_);
    TimeSlot time_slot2(time_point_ + expected_duration, expected_duration);

    EXPECT_FALSE(time_slot1 == time_slot2);
}

TEST_F(TimeSlotTestsFixture, GivenTimeSlotsWithTheSameTimePointsExpectEqual)
{
    const auto expected_duration = std::chrono::minutes{test_duration * 2};
    TimeSlot time_slot1(time_point_, duration_);
    TimeSlot time_slot2(time_point_, expected_duration);

    EXPECT_TRUE(time_slot1 == time_slot2);
}

} // namespace tests
} // namespace calendar
