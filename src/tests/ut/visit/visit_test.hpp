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
        Doctor::createDoctor("Jan", "Kowalski", "00000000000", Gender::Male);
        Visit::createVisit(Clinic::getDoctors().front());
    }

    void TearDown() override
    {
        cleanupClinic();
    }
};
