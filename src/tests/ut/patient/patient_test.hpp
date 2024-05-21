#pragma once

#include "clinic_facade.hpp"
#include "patient.hpp"
#include "test_utils.hpp"
#include "gtest/gtest.h"

class PatientTestFixture : public ::testing::Test
{
    void TearDown() override
    {
        cleanupClinic();
    }

  protected:
};
