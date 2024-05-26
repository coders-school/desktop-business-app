#pragma once

#include "clinic_facade.hpp"
#include "patient.hpp"
#include "test_utils.hpp"
#include "gtest/gtest.h"

class PatientTestFixture : public ::testing::Test
{
    void SetUp() override
    {
        Doctor::createDoctor("Gawel", "Pawel", "49042481257", Gender::Male);
        Doctor::createDoctor("Pawel", "Awel", "87071989652", Gender::Male);

        Visit::createTempVisit(Clinic::getDoctors().at(0));
        Visit::createTempVisit(Clinic::getDoctors().at(1));
    }

    void TearDown() override
    {
        cleanupClinic();
    }
};
