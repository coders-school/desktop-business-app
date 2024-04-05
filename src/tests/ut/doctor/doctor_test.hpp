#pragma once

#include "clinic_facade.hpp"
#include "doctor.hpp"
#include "gtest/gtest.h"

class DoctorTestFixture : public ::testing::Test
{
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

  protected:
};
