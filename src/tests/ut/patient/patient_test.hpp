#pragma once

#include "patient.hpp"
#include "gtest/gtest.h"
#include <memory>
#include <type_traits>

class PatientTestFixture : public ::testing::Test
{
    void SetUp() override
    {
        unit_ = std::make_shared<Patient>(createPatient());
    }

  protected:
    Patient createPatient(std::unordered_set<Allergent> allergents = std::unordered_set<Allergent>{},
                          std::string name = "Jan", std::string last_name = "Kowalski",
                          std::string pesel = "00000000000")
    {
        Patient patient{name, last_name, pesel, allergents};

        return patient;
    }

    std::shared_ptr<Patient> unit_;
};

TEST_F(PatientTestFixture, GivenDefaultConstructorExpectNotConstructible)
{
    ASSERT_FALSE(std::is_constructible<Patient>());
}

TEST_F(PatientTestFixture, GivenDefaultDebtExpectGetDebtEqualsZero)
{
    const size_t expected_output{0};

    EXPECT_EQ(unit_->getDebt(), expected_output);
}

TEST_F(PatientTestFixture, GivenDebtSetToFiftyExpectDebtEqualsFifty)
{
    const size_t expected_output{50};
    const size_t input{50};

    unit_->setDebt(input);

    EXPECT_EQ(unit_->getDebt(), expected_output);
}

TEST_F(PatientTestFixture, GivenPatientExpectProperInformationReturned)
{
    // TODO Issue#46
    const std::string expected_output{};

    EXPECT_EQ(unit_->showInformationAboutPatient(), expected_output);
}

TEST_F(PatientTestFixture, GivenPatientWithAlergentExpectOtherAllergentsNotIncluded)
{
    unit_.reset();
    const std::unordered_set<Allergent> expected_allergents{Allergent::Allergent};
    const std::unordered_set<Allergent> input{Allergent::AnotherAllergent};
    unit_ = std::make_shared<Patient>(createPatient(input));

    EXPECT_NE(unit_->getAllergents(), expected_allergents);
}

TEST_F(PatientTestFixture, GivenPatientWithUpdatedAlergentsExpectExactAllergentsReturned)
{
    const std::unordered_set<Allergent> expected_allergents{Allergent::Allergent, Allergent::AnotherAllergent,
                                                            Allergent::DifferentAllergent, Allergent::SomeAllergent};
    const std::unordered_set<Allergent> input{Allergent::AnotherAllergent, Allergent::DifferentAllergent,
                                              Allergent::SomeAllergent, Allergent::Allergent};

    unit_->updateAllergents(input);

    EXPECT_EQ(unit_->getAllergents(), expected_allergents);
}