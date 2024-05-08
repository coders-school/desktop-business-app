#pragma once

#include "clinic_facade.hpp"
#include "reserve_queue.hpp"
#include "test_utils.hpp"
#include "gtest/gtest.h"

class ReserveQueueFixture : public ::testing::Test
{
  protected:
    ReserveQueue sut_;
    std::vector<std::shared_ptr<Patient>> patients_;
    std::vector<std::shared_ptr<Doctor>> doctors_;
    constexpr static size_t predicted_number_of_patients{4};
    constexpr static size_t predicted_number_of_dotors{3};

    void expectTreatmentQueuesEmpty() const
    {
        const auto treatments_awaiting_after_removal_attempts = sut_.getTreatmentQueues();
        EXPECT_TRUE(treatments_awaiting_after_removal_attempts.empty());
    }

    void expectDoctorQueuesEmpty() const
    {
        const auto doctors_with_patients_awaiting_appointments_after_removal_attempts = sut_.getDoctorQueues();
        EXPECT_TRUE(doctors_with_patients_awaiting_appointments_after_removal_attempts.empty());
    }

  public:
    void SetUp() override
    {
        Doctor::createDoctor("Tomasz", "Zutek", "87071989652", Gender::Male);
        Doctor::createDoctor("Joanna", "Iksińska", "56020625965", Gender::Female);
        Doctor::createDoctor("Zuzanna", "Misiowa", "78031165346", Gender::Female);

        Patient::createPatient("Jakub", "Wąsaty", "72080357978", Gender::Male, {Allergen::SomeAllergen});
        Patient::createPatient("Jan", "Nowak", "99053033817", Gender::Male, {Allergen::DifferentAllergen});
        Patient::createPatient("Maria", "Maria", "49121347966", Gender::Female, {Allergen::DifferentAllergen});
        Patient::createPatient("Piotr", "Lewandowski", "55110335191", Gender::Male);

        patients_ = Clinic::getPatients();
        doctors_ = Clinic::getDoctors();

        assertPatientsAndDoctorsPresent();
    }

    void TearDown() override
    {
        cleanupClinic();
    }

    void assertPatientsAndDoctorsPresent()
    {
        ASSERT_EQ(doctors_.size(), predicted_number_of_dotors);
        ASSERT_EQ(patients_.size(), predicted_number_of_patients);
    }
};
