#include "patient_test.hpp"

namespace
{

TEST_F(PatientTestFixture, GivenDefaultDebtExpectGetDebtEqualsZero)
{
    Patient::createPatient("Jan", "Kowalski", "00000000000");
    const size_t expected_output{0};

    EXPECT_EQ(Clinic::getPatients().front()->getDebt(), expected_output);
}

TEST_F(PatientTestFixture, GivenDebtSetToFiftyExpectDebtEqualsFifty)
{
    Patient::createPatient("Jan", "Kowalski", "00000000000");
    const size_t expected_output{50};
    const size_t input{50};
    auto patient = Clinic::getPatients().front();
    patient->setDebt(input);

    EXPECT_EQ(patient->getDebt(), expected_output);
}

TEST_F(PatientTestFixture, GivenPatientExpectProperInformationReturned)
{
    Patient::createPatient("Jan", "Kowalski", "00000000000");
    // TODO Issue#46
    const std::string expected_output{};

    EXPECT_EQ(Clinic::getPatients().front()->showInformationAboutPatient(), expected_output);
}

TEST_F(PatientTestFixture, GivenPatientWithUpdatedAllergensExpectExactAllergensReturned)
{
    Patient::createPatient("Jan", "Kowalski", "00000000000");
    const std::set<Allergen> expected_allergens{Allergen::Allergen, Allergen::AnotherAllergen,
                                                Allergen::DifferentAllergen, Allergen::SomeAllergen};
    const std::set<Allergen> input{Allergen::AnotherAllergen, Allergen::DifferentAllergen, Allergen::SomeAllergen,
                                   Allergen::Allergen};
    auto patient = Clinic::getPatients().front();
    patient->updateAllergens(input);

    EXPECT_EQ(patient->getAllergens(), expected_allergens);
}

TEST_F(PatientTestFixture, GivenMultiplePatientsSearchByNameAndSurnameExpectCorrectPatientReturned)
{
    Patient::createPatient("Pawel", "Awel", "999");
    Patient::createPatient("Pawel", "Gawel", "000999");

    const auto expected_patient = Clinic::getPatients().at(1);

    const auto patient = Patient::getPatient("Pawel", "Gawel");

    EXPECT_EQ(patient.front(), expected_patient);
}

TEST_F(PatientTestFixture, GivenMultiplePatientsSearchByNameAndSurnameExpectAllPatientsReturned)
{
    Patient::createPatient("Pawel", "Awel", "999");
    Patient::createPatient("Pawel", "Gawel", "000999");
    Patient::createPatient("Pawel", "Gawel", "000991");

    const auto expected_size = 2U;

    const auto patients = Patient::getPatient("Pawel", "Gawel");

    EXPECT_EQ(patients.size(), expected_size);
}

TEST_F(PatientTestFixture, GivenMultiplePatientsSearchByPeselExpectCorrectPatientReturned)
{
    Patient::createPatient("Pawel", "Awel", "00000000000");
    Patient::createPatient("Pawel", "Gawel", "95082910213");

    const auto expected_patient = Clinic::getPatients().at(1);

    const auto patient = Patient::getPatient("95082910213");

    EXPECT_EQ(patient, expected_patient);
}

} // namespace
