#pragma once

#include "clinic_facade.hpp"
#include "patient.hpp"
#include "gtest/gtest.h"
#include <memory>

class PatientTestFixture : public ::testing::Test
{
    void SetUp() override
    {
        createPatient();
    }

    class PatientTestFixture : public ::testing::Test
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
        void createPatient(std::string name = "Jan", std::string surname = "Kowalski",
                           std::string pesel = "00000000000", std::set<Allergen> allergens = {})
        {
            Patient::createPatient(name, surname, pesel, allergens);
        }
    };
