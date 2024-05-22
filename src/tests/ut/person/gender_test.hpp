#pragma once

#include "gender.hpp"
#include "gtest/gtest.h"

struct TestParamsEnumInput
{
    Gender input_;
    std::string expected_output_;
};

struct TestParamsStringInput
{
    std::string input_;
    Gender expected_output_;
};

class GenderEnumToStringTest : public ::testing::TestWithParam<TestParamsEnumInput>
{
};

class GenderStringToEnumTest : public ::testing::TestWithParam<TestParamsStringInput>
{
};
