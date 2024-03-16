#pragma once
#include "../material.hpp"
#include "gtest/gtest.h"

struct TestParams
{
    Material material_input;
    std::string expected_output;
};

class MaterialParameterizedFixture : public ::testing::TestWithParam<TestParams>
{
};
