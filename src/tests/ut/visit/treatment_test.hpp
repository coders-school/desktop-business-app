#pragma once

#include "gtest/gtest.h"

#include "treatment.hpp"

using TreatmentWithStringRepresentation = std::pair<const Treatment, std::string>;

struct TreatmentParameterizedFixture : public ::testing::TestWithParam<TreatmentWithStringRepresentation>
{
};
