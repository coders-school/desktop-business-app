#pragma once

#include "clinic_facade.hpp"
#include "test_utils.hpp"
#include "gtest/gtest.h"

class ReceptionistTestFixture : public ::testing::Test
{
  protected:
    void TearDown() override
    {
        cleanupClinic();
    }
};
