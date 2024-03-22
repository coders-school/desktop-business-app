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

  protected:
    void createPatient(std::unordered_set<Allergent> allergents = std::unordered_set<Allergent>{},
                       std::string name = "Jan", std::string last_name = "Kowalski", std::string pesel = "00000000000")
    {
        Patient::createPatient(name, last_name, pesel, allergents);
    }

    std::vector<std::shared_ptr<Patient>> unit_{Patient::getPatients()};
};

TEST_F(PatientTestFixture, GivenMultiplePatientsExpectCorrectNumberOfPatientsCreated)
{
    const size_t extected_size{2};

    createPatient({}, "Pawel");

    EXPECT_EQ(Patient::getPatients().size(), extected_size);
}

TEST_F(PatientTestFixture, GivenDefaultConstructorExpectNotConstructible)
{
    ASSERT_FALSE(std::is_constructible<Patient>());
}

TEST_F(PatientTestFixture, GivenDefaultDebtExpectGetDebtEqualsZero)
{
    const size_t expected_output{0};

    EXPECT_EQ(unit_.front()->getDebt(), expected_output);
}

TEST_F(PatientTestFixture, GivenDebtSetToFiftyExpectDebtEqualsFifty)
{
    const size_t expected_output{50};
    const size_t input{50};

    unit_.front()->setDebt(input);

    EXPECT_EQ(unit_.front()->getDebt(), expected_output);
}

TEST_F(PatientTestFixture, GivenPatientExpectProperInformationReturned)
{
    // TODO Issue#46
    const std::string expected_output{};

    EXPECT_EQ(unit_.front()->showInformationAboutPatient(), expected_output);
}

TEST_F(PatientTestFixture, GivenPatientWithAlergentExpectOtherAllergentsNotIncluded)
{
    unit_.clear();
    const std::unordered_set<Allergent> expected_allergents{Allergent::Allergent};
    const std::unordered_set<Allergent> input{Allergent::AnotherAllergent};
    createPatient(input);

    EXPECT_NE(unit_.front()->getAllergents(), expected_allergents);
}

TEST_F(PatientTestFixture, GivenPatientWithUpdatedAlergentsExpectExactAllergentsReturned)
{
    const std::unordered_set<Allergent> expected_allergents{Allergent::Allergent, Allergent::AnotherAllergent,
                                                            Allergent::DifferentAllergent, Allergent::SomeAllergent};
    const std::unordered_set<Allergent> input{Allergent::AnotherAllergent, Allergent::DifferentAllergent,
                                              Allergent::SomeAllergent, Allergent::Allergent};

    unit_.front()->updateAllergents(input);

    EXPECT_EQ(unit_.front()->getAllergents(), expected_allergents);
}
