#include "patient_test.hpp"

namespace
{

TEST_F(PatientTestFixture, GivenDefaultConstructorExpectNotConstructible)
{
    ASSERT_FALSE(std::is_constructible<Patient>());
}

TEST_F(PatientTestFixture, GivenDefaultDebtExpectGetDebtEqualsZero)
{
    const size_t expected_output{0};

    EXPECT_EQ(Patient::getPatients().front()->getDebt(), expected_output);
}

TEST_F(PatientTestFixture, GivenDebtSetToFiftyExpectDebtEqualsFifty)
{
    const size_t expected_output{50};
    const size_t input{50};
    Patient::getPatients().front()->setDebt(input);

    EXPECT_EQ(Patient::getPatients().front()->getDebt(), expected_output);
}

TEST_F(PatientTestFixture, GivenPatientExpectProperInformationReturned)
{
    // TODO Issue#46
    const std::string expected_output{};

    EXPECT_EQ(Patient::getPatients().front()->showInformationAboutPatient(), expected_output);
}

TEST_F(PatientTestFixture, GivenPatientWithAllergenExpectOtherAllergensNotIncluded)
{
    const std::set<Allergen> expected_allergens{Allergen::Allergen};
    const std::set<Allergen> input{Allergen::AnotherAllergen};
    createPatient(input, "Alex");

    EXPECT_NE(Patient::getPatient("Alex", "Kowalski").front()->getAllergens(), expected_allergens);
}

TEST_F(PatientTestFixture, GivenPatientWithUpdatedAllergensExpectExactAllergensReturned)
{
    const std::set<Allergen> expected_allergens{Allergen::Allergen, Allergen::AnotherAllergen,
                                                Allergen::DifferentAllergen, Allergen::SomeAllergen};
    const std::set<Allergen> input{Allergen::AnotherAllergen, Allergen::DifferentAllergen, Allergen::SomeAllergen,
                                   Allergen::Allergen};
    Patient::getPatients().front()->updateAllergens(input);

    EXPECT_EQ(Patient::getPatients().front()->getAllergens(), expected_allergens);
}

TEST_F(PatientTestFixture, GivenMultiplePatientsExpectCorrectNumberOfPatientsCreated)
{
    const size_t extected_size{2};
    Patient::createPatient("Pawel", "Awel", "999");

    EXPECT_EQ(Patient::getPatients().size(), extected_size);
}

TEST_F(PatientTestFixture, GivenMutliplePatientsWithDifferentPeselExpectCorrectPatientReturned)
{
    const std::string expected_first_name{"Pan"};
    const std::string input_pesel{"00000000002"};

    Patient::createPatient("Man", "Kowalski", "00000000001");
    Patient::createPatient(expected_first_name, "Kowalski", input_pesel);
    Patient::createPatient("Wan", "Kowalski", "00000000003");

    EXPECT_EQ(Patient::getPatient(input_pesel)->getName(), expected_first_name);
}

TEST_F(PatientTestFixture, GivenMutliplePatientsWithSameNamesExpectCorrectNumberOfPatientsReturned)
{
    const auto expected_size{4U};
    const auto input_first_name{"Jan"};
    const auto input_last_name{"Kowalski"};

    Patient::createPatient("Janusz", input_last_name, "00000000001");
    Patient::createPatient(input_first_name, input_last_name, "00000000002");
    Patient::createPatient(input_first_name, input_last_name, "00000000003");
    Patient::createPatient(input_first_name, input_last_name, "00000000004");

    EXPECT_EQ(Patient::getPatient(input_first_name, input_last_name).size(), expected_size);
}

} // namespace
