#pragma once

#include "clinic_facade.hpp"
#include "gtest/gtest.h"

class DataFileManagerTestFixture : public ::testing::Test
{
    void TearDown() override
    {
        for (const auto& doctor : Clinic::getDoctors())
        {
            Clinic::removeDoctor(doctor);
        }

        for (const auto& receptionist : Clinic::getReceptionists())
        {
            Clinic::removeReceptionist(receptionist);
        }
    }
};
