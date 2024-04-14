#pragma once

#include "clinic_facade.hpp"
#include "doctor.hpp"
#include "visit.hpp"
#include "gtest/gtest.h"

class VisitTestFixture : public ::testing::Test
{

  protected:
    void SetUp() override
    {
        Doctor::createDoctor("Jan", "Kowalski", "00000000000");
        Visit::createVisit(Clinic::getDoctors().front());
    }

    void TearDown() override
    {
        for (const auto& visit : Clinic::getVisits())
        {
            Clinic::removeVisit(visit);
        }

        for (const auto& doctor : Clinic::getDoctors())
        {
            Clinic::removeDoctor(doctor);
        }
        for (const auto& receptionist : Clinic::getReceptionists())
        {
            Clinic::removeReceptionist(receptionist);
        }

        for (const auto& patient : Clinic::getPatients())
        {
            Clinic::removePatient(patient);
        }
    }
};
