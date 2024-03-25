#pragma once

#include "doctor.hpp"
#include "patient.hpp"
#include "visit.hpp"
#include "gtest/gtest.h"

class Doctor;
class Patient;

class AssociationTest : public ::testing::Test
{

  protected:
    void createPatient()
    {
        std::string name = "Jan";
        std::string last_name = "Kowalski";
        std::string pesel = "00000000000";
        Patient::createPatient(name, last_name, pesel);
    }

    void SetUp() override
    {
        createPatient();
        visit1 = Visit::createVisit(doc1);
        visit2 = Visit::createVisit(doc2);
        visit3 = Visit::createVisit(doc2);

        visit2->setVisitInformation("Tworze klub ninja!");
        visit3->setVisitInformation("I w klubie sa sami fajni ludzie");
    }

    std::shared_ptr<Doctor> doc1{std::make_shared<Doctor>("Janusz", "Tracz", "1234")};
    std::shared_ptr<Doctor> doc2{std::make_shared<Doctor>("Lukasz", "Ziobron", "123456")};

    std::shared_ptr<Visit> visit1;
    std::shared_ptr<Visit> visit2;
    std::shared_ptr<Visit> visit3;
};
