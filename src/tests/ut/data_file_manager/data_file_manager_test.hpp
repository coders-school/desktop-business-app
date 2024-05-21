#pragma once

#include "clinic_facade.hpp"
#include "test_utils.hpp"
#include "gtest/gtest.h"

class DataFileManagerTestFixture : public ::testing::Test
{
    void TearDown() override
    {
        cleanupClinic();
    }
};
