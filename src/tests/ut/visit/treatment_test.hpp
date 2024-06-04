#pragma once

#include "gtest/gtest.h"

#include "treatment.hpp"

using TestParam = std::pair<const Treatment, std::string>;

struct TreatmentToStringParameterizedFixture : public ::testing::TestWithParam<TestParam>
{
};

struct TreatmentToEnumParameterizedFixture : public ::testing::TestWithParam<TestParam>
{
};
