#pragma once

#include "gtest/gtest.h"

#include "treatment.hpp"

using TestParam = std::pair<const Treatment, std::string>;

struct TreatmentParameterizedFixture : public ::testing::TestWithParam<TestParam>
{
};
