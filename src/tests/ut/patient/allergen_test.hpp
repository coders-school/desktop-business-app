#pragma once

#include "allergen.hpp"
#include "gtest/gtest.h"

struct TestParams
{
    Allergen allergen_input_;
    std::string expected_output_;
};

class AllergenParameterizedFixture : public ::testing::TestWithParam<TestParams>
{
};
