#pragma once

#include "clinic_facade.hpp"
#include "room.hpp"
#include "test_utils.hpp"
#include "gtest/gtest.h"

class RoomTestFixture : public ::testing::Test
{

    void SetUp() override
    {
        Doctor::createDoctor("Jan", "Kowalski", "80062378532", Gender::Male);
        Doctor::createDoctor("Gawel", "Pawel", "49042481257", Gender::Male);

        Visit::createTempVisit(Clinic::getDoctors().at(0));
        Visit::createTempVisit(Clinic::getDoctors().at(1));
    }

    void TearDown() override
    {
        cleanupClinic();
    }
};
