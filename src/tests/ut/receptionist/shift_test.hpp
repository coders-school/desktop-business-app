#pragma once

#include "shift.hpp"
#include "gtest/gtest.h"

namespace unit_test::receptionist
{

struct TestParams
{
    Shift shift_input_;
    std::string expected_output_;
};

class ShiftParameterizedFixture : public ::testing::TestWithParam<TestParams>
{
};

} // namespace unit_test::receptionist
