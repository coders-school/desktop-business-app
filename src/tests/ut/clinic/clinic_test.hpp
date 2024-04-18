#pragma once

#include "clinic_facade.hpp"
#include "test_utils.hpp"
#include "gtest/gtest.h"

class ClinicTestFixture : public ::testing::Test
{
    void TearDown() override
    {
        cleanupClinic();
    }
};
