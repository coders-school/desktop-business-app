#pragma once

#include "shift.hpp"
#include "gtest/gtest.h"

struct TestParams
{
    Shift shift_input_;
    std::string expected_output_;
};

class ShiftParameterizedFixture : public ::testing::TestWithParam<TestParams>
{
};
