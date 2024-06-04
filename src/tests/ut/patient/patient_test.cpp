#include "patient_test.hpp"

namespace
{

TEST_F(PatientTestFixture, GivenDefaultDebtExpectGetDebtEqualsZero)
{
    Patient::createPatient("Jan", "Kowalski", "87071989652", Gender::Male);
    const size_t expected_output{0};

    EXPECT_EQ(Clinic::getPatients().front()->getDebt(), expected_output);
}

TEST_F(PatientTestFixture, GivenDebtSetToFiftyExpectDebtEqualsFifty)
{
    Patient::createPatient("Jan", "Kowalski", "87071989652", Gender::Male);
    const size_t expected_output{50};
    const size_t input{50};
    auto patient = Clinic::getPatients().front();
    patient->setDebt(input);

    EXPECT_EQ(patient->getDebt(), expected_output);
}

TEST_F(PatientTestFixture, GivenPatientExpectProperInformationReturned)
{
    Patient::createPatient("Jan", "Kowalski", "87071989652", Gender::Male);
    // TODO Issue#46
    const std::string expected_output{};

    EXPECT_EQ(Clinic::getPatients().front()->showInformationAboutPatient(), expected_output);
}

TEST_F(PatientTestFixture, GivenPatientWithUpdatedAllergensExpectExactAllergensReturned)
{
    Patient::createPatient("Jan", "Kowalski", "87071989652", Gender::Male);
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
    Patient::createPatient("Pawel", "Awel", "87071989652", Gender::Male);
    Patient::createPatient("Pawel", "Gawel", "72080357978", Gender::Male);

    const auto expected_patient = Clinic::getPatients().at(1);

    const auto patient = Patient::getPatient("Pawel", "Gawel");

    EXPECT_EQ(patient.front(), expected_patient);
}

TEST_F(PatientTestFixture, GivenMultiplePatientsSearchByNameAndSurnameExpectAllPatientsReturned)
{
    Patient::createPatient("Pawel", "Awel", "87071989652", Gender::Male);
    Patient::createPatient("Pawel", "Gawel", "72080357978", Gender::Male);
    Patient::createPatient("Pawel", "Gawel", "99053033817", Gender::Male);

    const auto expected_size = 2U;

    const auto patients = Patient::getPatient("Pawel", "Gawel");

    EXPECT_EQ(patients.size(), expected_size);
}

TEST_F(PatientTestFixture, GivenMultiplePatientsSearchByPeselExpectCorrectPatientReturned)
{
    Patient::createPatient("Pawel", "Awel", "87071989652", Gender::Male);
    Patient::createPatient("Pawel", "Gawel", "72080357978", Gender::Male);

    const auto expected_patient = Clinic::getPatients().at(1);

    const auto patient = Patient::getPatient("72080357978");

    EXPECT_EQ(patient, expected_patient);
}

TEST_F(PatientTestFixture, GivenVisitCheckIfPatientHasCorrectAmountOfVisits)
{
    Patient::createPatient("Pawel", "Awel", "87071989652", Gender::Male);
    std::shared_ptr<Patient> patient = Clinic::getPatients().front();
    patient->addVisit(Clinic::getTempVisit());
    const size_t expected_output{1};
    EXPECT_EQ(Clinic::getPatients().front()->getVisits().size(), expected_output);
}

} // namespace
