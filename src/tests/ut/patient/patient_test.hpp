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
            Patient::removePatient(patient.getPesel());
        }
    }

  protected:
    void createPatient(std::string name = "Jan", std::string last_name = "Kowalski", std::string pesel = "00000000000",
                       std::set<Allergen> allergens = {})
    {
        Patient::createPatient(name, last_name, pesel, allergens);
    }
};
