#include "patient_test.hpp"

namespace
{

TEST_F(PatientTestFixture, GivenDefaultDebtExpectGetDebtEqualsZero)
{
    const size_t expected_output{0};

    EXPECT_EQ(Clinic::getPatients().front()->getDebt(), expected_output);
}

TEST_F(PatientTestFixture, GivenDebtSetToFiftyExpectDebtEqualsFifty)
{
    const size_t expected_output{50};
    const size_t input{50};
    auto patient = Clinic::getPatients().front();
    patient->setDebt(input);

    EXPECT_EQ(patient->getDebt(), expected_output);
}

TEST_F(PatientTestFixture, GivenPatientExpectProperInformationReturned)
{
    // TODO Issue#46
    const std::string expected_output{};

    EXPECT_EQ(Clinic::getPatients().front()->showInformationAboutPatient(), expected_output);
}

TEST_F(PatientTestFixture, GivenPatientWithUpdatedAllergensExpectExactAllergensReturned)
{
    const std::set<Allergen> expected_allergens{Allergen::Allergen, Allergen::AnotherAllergen,
                                                Allergen::DifferentAllergen, Allergen::SomeAllergen};
    const std::set<Allergen> input{Allergen::AnotherAllergen, Allergen::DifferentAllergen, Allergen::SomeAllergen,
                                   Allergen::Allergen};
    auto patient = Clinic::getPatients().front();
    patient->updateAllergens(input);

    EXPECT_EQ(patient->getAllergens(), expected_allergens);
}

TEST_F(PatientTestFixture, GivenMultiplePatientsExpectCorrectNumberOfPatientsCreated)
{
    const size_t extected_size{2};
    Patient::createPatient("Pawel", "Awel", "999");

    EXPECT_EQ(Clinic::getPatients().size(), extected_size);
}

} // namespace
