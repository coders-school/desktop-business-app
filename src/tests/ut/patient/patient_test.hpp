#pragma once

#include "patient.hpp"
#include "gtest/gtest.h"
#include <memory>
#include <type_traits>

class PatientTestFixture : public ::testing::Test
{
    void SetUp() override
    {
        createPatient();
    }

    void TearDown() override
    {
        for (const auto& patient : Patient::getPatients())
        {
            patient->removePatient();
        }
    }

  protected:
    void createPatient(std::set<Allergen> allergens = std::set<Allergen>{}, std::string name = "Jan",
                       std::string surname = "Kowalski", std::string pesel = "00000000000")
    {
        Patient::createPatient(name, surname, pesel, allergens);
    }
};
