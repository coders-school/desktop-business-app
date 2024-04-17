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

    void expectTreatmentsHavingQueueEmpty() const
    {
        const auto treatments_awaiting_after_removal_attempts = sut_.treatmentsHavingQueue();
        EXPECT_TRUE(treatments_awaiting_after_removal_attempts.empty());
    }

    void expectDoctorsHavingQueueEmpty() const
    {
        const auto doctors_with_patients_awaiting_appointments_after_removal_attempts = sut_.doctorsHavingQueue();
        EXPECT_TRUE(doctors_with_patients_awaiting_appointments_after_removal_attempts.empty());
    }

  public:
    void SetUp() override
    {
        Doctor::createDoctor("Tomasz", "Zutek", "98041000079");
        Doctor::createDoctor("Joanna", "Iksińska", "98041000079");
        Doctor::createDoctor("Zuzanna", "Misiowa", "28032507069");

        Patient::createPatient("Jakub", "Wąsaty", "98041000079", {Allergen::SomeAllergen});
        Patient::createPatient("Jan", "Nowak", "39032302226", {Allergen::DifferentAllergen});
        Patient::createPatient("Maria", "Maria", "33121907675", {Allergen::DifferentAllergen});
        Patient::createPatient("Piotr", "Lewandowski", "54091904398");

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
