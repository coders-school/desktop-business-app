#include "clinic_facade.hpp"
#include "gtest/gtest.h"

class ClinicTestFixture : public ::testing::Test
{

  protected:
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
    }
};
