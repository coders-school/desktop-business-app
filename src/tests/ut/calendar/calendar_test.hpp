#pragma once

#include "calendar.hpp"
#include "clinic_facade.hpp"
#include "day.hpp"
#include "day_name.hpp"
#include "month.hpp"
#include "year.hpp"
#include "gtest/gtest.h"
#include <chrono>

class CalendarTestFixture : public ::testing::Test
{
  public:
    std::shared_ptr<Calendar> cal;

  protected:
    void SetUp() override
    {
        Calendar::createCalendar();
        cal = Clinic::getCalendar();
        cal->createYear(2024, DayName::Monday);
    }
    void Add2025()
    {
        cal->createYear(2025, DayName::Wednesday);
    }
};