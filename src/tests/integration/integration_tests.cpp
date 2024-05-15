#include "integration_tests.hpp"

// TODO: make nice integration test name after completed
TEST_F(IntegratonFixture, IntegrationTest)
{
    prepareClinic();
    expectClinicWellPrepared();
    ASSERT_EQ(Clinic::getPatients().size(), 0);
    Patient::createPatient("Jan", "Kowalski", "87071989652", Gender::Male,
                           {Allergen::SomeAllergen, Allergen::DifferentAllergen});
    ASSERT_EQ(Clinic::getPatients().size(), 1);
    auto patient = Clinic::getPatients().front();
    checkIfPatientCreatedAsExpected(patient);

    checkIfInitialAddressEmpty(patient);
    Address expectedAddress{"Suwałki", "Poland", "Warmińsko-Mazurskie", "Wroblewskiego 10/44", "50-370"};
    patient->setAddress(expectedAddress);
    checkIfPatientHasExpectedAddress(patient, expectedAddress);

    EXPECT_TRUE(patient->getPhoneNumber().empty());
    patient->setPhoneNumber("700 112 112");
    EXPECT_EQ(patient->getPhoneNumber(), "700 112 112");

    // new visit for patient
    // check if visit data is correctly assigned
    // perform visit

    // check if visit status has been updated
    // check if visit info has been updated
    // check if debt has been assigned to patient
    // check if used materials have been removed correctly
    // check if visit was removed from doctor
    // patient pays
    // check if debt and status has been updated
}
