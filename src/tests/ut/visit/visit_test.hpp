#pragma once

#include "clinic_facade.hpp"
#include "doctor.hpp"
#include "test_utils.hpp"
#include "visit.hpp"
#include "gtest/gtest.h"

class VisitTestFixture : public ::testing::Test
{

  protected:
    void SetUp() override
    {
        Doctor::createDoctor("Jan", "Kowalski", "87071989652", Gender::Male);
        Visit::createTempVisit(Clinic::getDoctors().front());
    }

    void TearDown() override
    {
        cleanupClinic();
    }
};
