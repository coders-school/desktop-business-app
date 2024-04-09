#include "reserve_queue_test.hpp"

#include "gmock/gmock.h"

namespace
{
using ::testing::ElementsAre;
using ::testing::UnorderedElementsAre;

class AddAwaitingPatientShould : public ReserveQueueFixture
{
};

TEST_F(AddAwaitingPatientShould, EnqueuePatientsForTreatmentInCorrectOrder)
{
    Treatment filling_treatment{Treatment::DentalFilling};
    sut_.addAwaitingPatient(filling_treatment, patients_[0]);
    sut_.addAwaitingPatient(filling_treatment, patients_[1]);
    sut_.addAwaitingPatient(filling_treatment, patients_[2]);
    sut_.addAwaitingPatient(filling_treatment, patients_[3]);

    Treatment tooth_extraction_treatment{Treatment::ToothExtraction};
    sut_.addAwaitingPatient(tooth_extraction_treatment, patients_[3]);
    sut_.addAwaitingPatient(tooth_extraction_treatment, patients_[0]);
    sut_.addAwaitingPatient(tooth_extraction_treatment, patients_[1]);

    const auto filling_treatment_queued_patients = sut_.awaitingPatients(filling_treatment);
    const auto tooth_extraction_queed_patients = sut_.awaitingPatients(tooth_extraction_treatment);

    EXPECT_THAT(filling_treatment_queued_patients, ElementsAre(patients_[0], patients_[1], patients_[2], patients_[3]));
    EXPECT_THAT(tooth_extraction_queed_patients, ElementsAre(patients_[3], patients_[0], patients_[1]));
}

TEST_F(AddAwaitingPatientShould, NotEnQueuePatientsIfAlreadyEnqueuedForSpecificTreatment)
{
    Treatment tooth_extraction_treatment{Treatment::ToothExtraction};
    sut_.addAwaitingPatient(tooth_extraction_treatment, patients_[3]);
    sut_.addAwaitingPatient(tooth_extraction_treatment, patients_[0]);

    sut_.addAwaitingPatient(tooth_extraction_treatment, patients_[3]);
    sut_.addAwaitingPatient(tooth_extraction_treatment, patients_[0]);

    const auto tooth_extraction_queed_patients = sut_.awaitingPatients(tooth_extraction_treatment);

    EXPECT_THAT(tooth_extraction_queed_patients, ElementsAre(patients_[3], patients_[0]));
}

TEST_F(AddAwaitingPatientShould, EnqueuePatientsForDoctorInCorrectOrder)
{
    // first doctor queue
    sut_.addAwaitingPatient(doctors_[0], patients_[3]);
    sut_.addAwaitingPatient(doctors_[0], patients_[2]);
    sut_.addAwaitingPatient(doctors_[0], patients_[1]);
    sut_.addAwaitingPatient(doctors_[0], patients_[0]);
    // second doctor queue
    sut_.addAwaitingPatient(doctors_[1], patients_[2]);
    sut_.addAwaitingPatient(doctors_[1], patients_[0]);
    // third doctor queue
    sut_.addAwaitingPatient(doctors_[2], patients_[1]);
    sut_.addAwaitingPatient(doctors_[2], patients_[0]);
    sut_.addAwaitingPatient(doctors_[2], patients_[3]);
    sut_.addAwaitingPatient(doctors_[2], patients_[2]);

    const auto first_doctor_queued_patients = sut_.awaitingPatients(doctors_[0]);
    const auto second_doctor_queued_patients = sut_.awaitingPatients(doctors_[1]);
    const auto third_doctor_queued_patients = sut_.awaitingPatients(doctors_[2]);

    EXPECT_THAT(first_doctor_queued_patients, ElementsAre(patients_[3], patients_[2], patients_[1], patients_[0]));
    EXPECT_THAT(second_doctor_queued_patients, ElementsAre(patients_[2], patients_[0]));
    EXPECT_THAT(third_doctor_queued_patients, ElementsAre(patients_[1], patients_[0], patients_[3], patients_[2]));
}

TEST_F(AddAwaitingPatientShould, NotEnQueuePatientsIfAlreadyEnqueuedForSpecificDoctor)
{
    sut_.addAwaitingPatient(doctors_[1], patients_[2]);
    sut_.addAwaitingPatient(doctors_[1], patients_[1]);
    sut_.addAwaitingPatient(doctors_[1], patients_[0]);
    sut_.addAwaitingPatient(doctors_[1], patients_[2]);
    sut_.addAwaitingPatient(doctors_[1], patients_[0]);

    const auto doctor_queued_patients = sut_.awaitingPatients(doctors_[1]);

    EXPECT_THAT(doctor_queued_patients, ElementsAre(patients_[2], patients_[1], patients_[0]));
}

class RemoveAwaitingPatientShould : public ReserveQueueFixture
{
};

TEST_F(RemoveAwaitingPatientShould, NotChangeTreatmentQueueIfPatientNotPresentInQueue)
{
    Treatment filling_treatment{Treatment::DentalFilling};
    sut_.addAwaitingPatient(filling_treatment, patients_[0]);
    sut_.addAwaitingPatient(filling_treatment, patients_[1]);
    sut_.addAwaitingPatient(filling_treatment, patients_[2]);

    Treatment tooth_extraction_treatment{Treatment::ToothExtraction};
    sut_.addAwaitingPatient(tooth_extraction_treatment, patients_[3]);
    sut_.addAwaitingPatient(tooth_extraction_treatment, patients_[0]);

    const auto filling_treatment_patients_before = sut_.awaitingPatients(filling_treatment);
    const auto tooth_extraction_patients_before = sut_.awaitingPatients(tooth_extraction_treatment);

    ASSERT_THAT(filling_treatment_patients_before, ElementsAre(patients_[0], patients_[1], patients_[2]));
    ASSERT_THAT(tooth_extraction_patients_before, ElementsAre(patients_[3], patients_[0]));

    sut_.removeAwaitingPatient(filling_treatment, patients_[3]);
    sut_.removeAwaitingPatient(tooth_extraction_treatment, patients_[1]);

    const auto filling_treatment_patients_after = sut_.awaitingPatients(filling_treatment);
    const auto tooth_extraction_patients_after = sut_.awaitingPatients(tooth_extraction_treatment);

    EXPECT_EQ(filling_treatment_patients_before, filling_treatment_patients_after);
    EXPECT_EQ(tooth_extraction_patients_before, tooth_extraction_patients_after);
}

TEST_F(RemoveAwaitingPatientShould, NotChangeDoctorQueueIfPatientNotPresentInQueue)
{
    // first doctor queue
    sut_.addAwaitingPatient(doctors_[0], patients_[2]);
    sut_.addAwaitingPatient(doctors_[0], patients_[1]);
    // second doctor queue
    sut_.addAwaitingPatient(doctors_[1], patients_[3]);
    sut_.addAwaitingPatient(doctors_[1], patients_[0]);

    const auto first_doctor_patients_before = sut_.awaitingPatients(doctors_[0]);
    const auto second_doctor_patients_before = sut_.awaitingPatients(doctors_[1]);

    ASSERT_THAT(first_doctor_patients_before, ElementsAre(patients_[2], patients_[1]));
    ASSERT_THAT(second_doctor_patients_before, ElementsAre(patients_[3], patients_[0]));

    sut_.removeAwaitingPatient(doctors_[0], patients_[3]);
    sut_.removeAwaitingPatient(doctors_[1], patients_[1]);

    const auto first_doctor_patients_after = sut_.awaitingPatients(doctors_[0]);
    const auto second_doctor_patients_after = sut_.awaitingPatients(doctors_[1]);

    EXPECT_EQ(first_doctor_patients_before, first_doctor_patients_after);
    EXPECT_EQ(second_doctor_patients_before, second_doctor_patients_after);
}

TEST_F(RemoveAwaitingPatientShould, NotAddTreatmentKeyIfRemovalRequestedFromEmptyList)
{
    const auto treatments_awaiting_before = sut_.treatmentsHavingQueue();
    ASSERT_TRUE(treatments_awaiting_before.empty());

    sut_.removeAwaitingPatient(Treatment::DentalFilling, patients_[0]);
    sut_.removeAwaitingPatient(Treatment::ToothExtraction, patients_[1]);
    const auto treatments_awaiting_after_removal_attempts = sut_.treatmentsHavingQueue();

    EXPECT_TRUE(treatments_awaiting_after_removal_attempts.empty());
}

TEST_F(RemoveAwaitingPatientShould, NotAddDoctorKeyIfRemovalRequestedFromEmptyList)
{
    const auto doctors_with_patients_awaiting_appointments_before = sut_.doctorsHavingQueue();
    ASSERT_TRUE(doctors_with_patients_awaiting_appointments_before.empty());

    sut_.removeAwaitingPatient(doctors_[0], patients_[0]);
    sut_.removeAwaitingPatient(doctors_[1], patients_[1]);
    const auto doctors_with_patients_awaiting_appointments_after_removal_attempts = sut_.doctorsHavingQueue();

    EXPECT_TRUE(doctors_with_patients_awaiting_appointments_after_removal_attempts.empty());
}

TEST_F(RemoveAwaitingPatientShould, RemovePatientFromBeginningOfSpecificTreatmentQueue)
{
    Treatment filling_treatment{Treatment::DentalFilling};
    sut_.addAwaitingPatient(filling_treatment, patients_[0]);
    sut_.addAwaitingPatient(filling_treatment, patients_[1]);
    sut_.addAwaitingPatient(filling_treatment, patients_[2]);
    sut_.addAwaitingPatient(filling_treatment, patients_[3]);

    const auto filling_treatment_patients_before = sut_.awaitingPatients(filling_treatment);

    ASSERT_THAT(filling_treatment_patients_before, ElementsAre(patients_[0], patients_[1], patients_[2], patients_[3]));

    sut_.removeAwaitingPatient(filling_treatment, patients_[0]);
    const auto filling_treatment_patients_after = sut_.awaitingPatients(filling_treatment);

    EXPECT_NE(filling_treatment_patients_before, filling_treatment_patients_after);
    EXPECT_THAT(filling_treatment_patients_after, ElementsAre(patients_[1], patients_[2], patients_[3]));
}

TEST_F(RemoveAwaitingPatientShould, RemovePatientFromTheMiddleOfSpecificTreatmentQueue)
{
    Treatment filling_treatment{Treatment::DentalFilling};
    sut_.addAwaitingPatient(filling_treatment, patients_[0]);
    sut_.addAwaitingPatient(filling_treatment, patients_[1]);
    sut_.addAwaitingPatient(filling_treatment, patients_[2]);
    sut_.addAwaitingPatient(filling_treatment, patients_[3]);

    const auto filling_treatment_patients_before = sut_.awaitingPatients(filling_treatment);

    ASSERT_THAT(filling_treatment_patients_before, ElementsAre(patients_[0], patients_[1], patients_[2], patients_[3]));

    sut_.removeAwaitingPatient(filling_treatment, patients_[1]);
    sut_.removeAwaitingPatient(filling_treatment, patients_[2]);
    const auto filling_treatment_patients_after = sut_.awaitingPatients(filling_treatment);

    EXPECT_NE(filling_treatment_patients_before, filling_treatment_patients_after);
    EXPECT_THAT(filling_treatment_patients_after, ElementsAre(patients_[0], patients_[3]));
}

TEST_F(RemoveAwaitingPatientShould, RemovePatientFromTheEndOfSpecificTreatmentQueue)
{
    Treatment filling_treatment{Treatment::DentalFilling};
    sut_.addAwaitingPatient(filling_treatment, patients_[0]);
    sut_.addAwaitingPatient(filling_treatment, patients_[1]);
    sut_.addAwaitingPatient(filling_treatment, patients_[2]);
    sut_.addAwaitingPatient(filling_treatment, patients_[3]);

    const auto filling_treatment_patients_before = sut_.awaitingPatients(filling_treatment);

    ASSERT_THAT(filling_treatment_patients_before, ElementsAre(patients_[0], patients_[1], patients_[2], patients_[3]));

    sut_.removeAwaitingPatient(filling_treatment, patients_[3]);
    const auto filling_treatment_patients_after = sut_.awaitingPatients(filling_treatment);

    EXPECT_NE(filling_treatment_patients_before, filling_treatment_patients_after);
    EXPECT_THAT(filling_treatment_patients_after, ElementsAre(patients_[0], patients_[1], patients_[2]));
}

TEST_F(RemoveAwaitingPatientShould, RemoveTreatmentKeyIfLastPatientAwaitingRemoved)
{
    Treatment filling_treatment{Treatment::DentalFilling};
    sut_.addAwaitingPatient(filling_treatment, patients_[0]);
    sut_.addAwaitingPatient(filling_treatment, patients_[1]);

    Treatment tooth_extraction_treatment{Treatment::ToothExtraction};
    sut_.addAwaitingPatient(tooth_extraction_treatment, patients_[3]);
    sut_.addAwaitingPatient(tooth_extraction_treatment, patients_[0]);

    const auto treatments_awaiting_before = sut_.treatmentsHavingQueue();
    ASSERT_THAT(treatments_awaiting_before, UnorderedElementsAre(Treatment::DentalFilling, Treatment::ToothExtraction));

    sut_.removeAwaitingPatient(filling_treatment, patients_[0]);
    sut_.removeAwaitingPatient(filling_treatment, patients_[1]);
    const auto treatments_after_removing_filling_patients = sut_.treatmentsHavingQueue();

    sut_.removeAwaitingPatient(tooth_extraction_treatment, patients_[3]);
    sut_.removeAwaitingPatient(tooth_extraction_treatment, patients_[0]);
    const auto treatments_after_removing_extraction_patients = sut_.treatmentsHavingQueue();

    EXPECT_THAT(treatments_after_removing_filling_patients, ElementsAre(Treatment::ToothExtraction));
    EXPECT_TRUE(treatments_after_removing_extraction_patients.empty());
}

TEST_F(RemoveAwaitingPatientShould, RemovePatientFromBeginningOfSpecificDoctorQueue)
{
    sut_.addAwaitingPatient(doctors_[0], patients_[3]);
    sut_.addAwaitingPatient(doctors_[0], patients_[2]);
    sut_.addAwaitingPatient(doctors_[0], patients_[1]);
    sut_.addAwaitingPatient(doctors_[0], patients_[0]);

    const auto doctor_queued_patients_before = sut_.awaitingPatients(doctors_[0]);
    ASSERT_THAT(doctor_queued_patients_before, ElementsAre(patients_[3], patients_[2], patients_[1], patients_[0]));

    sut_.removeAwaitingPatient(doctors_[0], patients_[3]);
    const auto doctor_queued_patients_after = sut_.awaitingPatients(doctors_[0]);

    EXPECT_NE(doctor_queued_patients_before, doctor_queued_patients_after);
    EXPECT_THAT(doctor_queued_patients_after, ElementsAre(patients_[2], patients_[1], patients_[0]));
}

TEST_F(RemoveAwaitingPatientShould, RemovePatientFromTheMiddleOfSpecificDoctorQueue)
{
    sut_.addAwaitingPatient(doctors_[0], patients_[3]);
    sut_.addAwaitingPatient(doctors_[0], patients_[2]);
    sut_.addAwaitingPatient(doctors_[0], patients_[1]);
    sut_.addAwaitingPatient(doctors_[0], patients_[0]);

    const auto doctor_queued_patients_before = sut_.awaitingPatients(doctors_[0]);
    ASSERT_THAT(doctor_queued_patients_before, ElementsAre(patients_[3], patients_[2], patients_[1], patients_[0]));

    sut_.removeAwaitingPatient(doctors_[0], patients_[2]);
    sut_.removeAwaitingPatient(doctors_[0], patients_[1]);
    const auto doctor_queued_patients_after = sut_.awaitingPatients(doctors_[0]);

    EXPECT_NE(doctor_queued_patients_before, doctor_queued_patients_after);
    EXPECT_THAT(doctor_queued_patients_after, ElementsAre(patients_[3], patients_[0]));
}

TEST_F(RemoveAwaitingPatientShould, RemovePatientFromTheEndOfSpecificDoctorQueue)
{
    sut_.addAwaitingPatient(doctors_[0], patients_[3]);
    sut_.addAwaitingPatient(doctors_[0], patients_[2]);
    sut_.addAwaitingPatient(doctors_[0], patients_[1]);
    sut_.addAwaitingPatient(doctors_[0], patients_[0]);

    const auto doctor_queued_patients_before = sut_.awaitingPatients(doctors_[0]);
    ASSERT_THAT(doctor_queued_patients_before, ElementsAre(patients_[3], patients_[2], patients_[1], patients_[0]));

    sut_.removeAwaitingPatient(doctors_[0], patients_[0]);
    const auto doctor_queued_patients_after = sut_.awaitingPatients(doctors_[0]);

    EXPECT_NE(doctor_queued_patients_before, doctor_queued_patients_after);
    EXPECT_THAT(doctor_queued_patients_after, ElementsAre(patients_[3], patients_[2], patients_[1]));
}

TEST_F(RemoveAwaitingPatientShould, RemoveDoctorKeyIfLastPatientAwaitingRemoved)
{
    // first doctor queue
    sut_.addAwaitingPatient(doctors_[0], patients_[3]);
    sut_.addAwaitingPatient(doctors_[0], patients_[2]);
    // second doctor queue
    sut_.addAwaitingPatient(doctors_[1], patients_[2]);
    sut_.addAwaitingPatient(doctors_[1], patients_[0]);

    const auto doctors_awaiting_appointments_before = sut_.doctorsHavingQueue();
    ASSERT_THAT(doctors_awaiting_appointments_before, UnorderedElementsAre(doctors_[0], doctors_[1]));

    sut_.removeAwaitingPatient(doctors_[0], patients_[3]);
    sut_.removeAwaitingPatient(doctors_[0], patients_[2]);
    const auto doctors_awaiting_appointments_after_removing_first_doctor_patients = sut_.doctorsHavingQueue();

    sut_.removeAwaitingPatient(doctors_[1], patients_[2]);
    sut_.removeAwaitingPatient(doctors_[1], patients_[0]);
    const auto doctors_awaiting_appointments_after_removing_second_doctor_patients = sut_.doctorsHavingQueue();

    EXPECT_THAT(doctors_awaiting_appointments_after_removing_first_doctor_patients, ElementsAre(doctors_[1]));
    EXPECT_TRUE(doctors_awaiting_appointments_after_removing_second_doctor_patients.empty());
}

class AwaitingPatientsShould : public ReserveQueueFixture
{
};

TEST_F(AwaitingPatientsShould, ReturnEmptyQueueIfNoPatientForTreatmentQueued)
{
    sut_.addAwaitingPatient(Treatment::DentalSealants, patients_[0]);
    sut_.addAwaitingPatient(Treatment::GumSurgery, patients_[1]);
    ASSERT_FALSE(sut_.awaitingPatients(Treatment::DentalSealants).empty());
    ASSERT_FALSE(sut_.awaitingPatients(Treatment::GumSurgery).empty());

    EXPECT_TRUE(sut_.awaitingPatients(Treatment::ToothExtraction).empty());
    EXPECT_TRUE(sut_.awaitingPatients(Treatment::OTHER).empty());
}

TEST_F(AwaitingPatientsShould, ReturnEmptyQueueIfNoPatientForDoctorQueued)
{
    sut_.addAwaitingPatient(doctors_[0], patients_[0]);
    sut_.addAwaitingPatient(doctors_[1], patients_[1]);
    ASSERT_FALSE(sut_.awaitingPatients(doctors_[0]).empty());
    ASSERT_FALSE(sut_.awaitingPatients(doctors_[1]).empty());

    EXPECT_TRUE(sut_.awaitingPatients(doctors_[2]).empty());
}

TEST_F(AwaitingPatientsShould, NotInsertTreatmentQueueKeyIfPatientForEmptyQueueRequested)
{
    const auto treatments_awaiting_before = sut_.treatmentsHavingQueue();

    const auto patients_awaiting_treatment = sut_.awaitingPatients(Treatment::ToothExtraction);
    const auto treatments_awaiting_after = sut_.treatmentsHavingQueue();

    EXPECT_TRUE(patients_awaiting_treatment.empty());
    EXPECT_TRUE(treatments_awaiting_before.empty());
    EXPECT_TRUE(treatments_awaiting_after.empty());
}

class TreatmentsHavingQueueShould : public ReserveQueueFixture
{
};

TEST_F(TreatmentsHavingQueueShould, ReturnEmptyTreatmentsListAfterReserveQueueInitialisation)
{
    const auto treatments_with_awaiting_patients{sut_.treatmentsHavingQueue()};
    EXPECT_EQ(treatments_with_awaiting_patients.size(), 0);
}

TEST_F(TreatmentsHavingQueueShould, ReturnListOfAllTreatmentsWithAtLeastOnePatientAwaiting)
{
    Treatment filling_treatment{Treatment::DentalFilling};
    sut_.addAwaitingPatient(filling_treatment, patients_[0]);
    sut_.addAwaitingPatient(filling_treatment, patients_[1]);

    Treatment tooth_extraction_treatment{Treatment::ToothExtraction};
    sut_.addAwaitingPatient(tooth_extraction_treatment, patients_[3]);
    sut_.addAwaitingPatient(tooth_extraction_treatment, patients_[0]);

    Treatment gum_surgery_treatment{Treatment::GumSurgery};
    sut_.addAwaitingPatient(gum_surgery_treatment, patients_[2]);

    EXPECT_THAT(sut_.treatmentsHavingQueue(),
                UnorderedElementsAre(filling_treatment, tooth_extraction_treatment, gum_surgery_treatment));
}

class DoctorsHavingQueueShould : public ReserveQueueFixture
{
};

TEST_F(DoctorsHavingQueueShould, ReturnEmptyDoctorListAfterReserveQueueInitialisation)
{
    const auto doctors_awaited_for_appointment{sut_.doctorsHavingQueue()};
    EXPECT_EQ(doctors_awaited_for_appointment.size(), 0);
}

TEST_F(DoctorsHavingQueueShould, ReturnListOfAllDoctorsWithAtLeastOnePatientAwaiting)
{
    // first doctor queue
    sut_.addAwaitingPatient(doctors_[0], patients_[3]);
    sut_.addAwaitingPatient(doctors_[0], patients_[2]);
    sut_.addAwaitingPatient(doctors_[0], patients_[1]);
    sut_.addAwaitingPatient(doctors_[0], patients_[0]);
    // second doctor queue
    sut_.addAwaitingPatient(doctors_[1], patients_[2]);

    EXPECT_THAT(sut_.doctorsHavingQueue(), UnorderedElementsAre(doctors_[0], doctors_[1]));
}

} // anonymous namespace
