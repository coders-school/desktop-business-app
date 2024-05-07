#include "reserve_queue_test.hpp"

#include "gmock/gmock.h"

namespace
{
using ::testing::ElementsAre;
using ::testing::UnorderedElementsAre;

class addPatientToQueueShould : public ReserveQueueFixture
{
};

TEST_F(addPatientToQueueShould, EnqueuePatientsForTreatmentInCorrectOrder)
{
    Treatment filling_treatment{Treatment::DentalFilling};
    sut_.addPatientToQueue(filling_treatment, patients_[0]);
    sut_.addPatientToQueue(filling_treatment, patients_[3]);

    Treatment tooth_extraction_treatment{Treatment::ToothExtraction};
    sut_.addPatientToQueue(tooth_extraction_treatment, patients_[3]);
    sut_.addPatientToQueue(tooth_extraction_treatment, patients_[1]);

    const auto filling_treatment_queued_patients = sut_.getQueuedPatients(filling_treatment);
    const auto tooth_extraction_queed_patients = sut_.getQueuedPatients(tooth_extraction_treatment);

    EXPECT_THAT(filling_treatment_queued_patients, ElementsAre(patients_[0], patients_[3]));
    EXPECT_THAT(tooth_extraction_queed_patients, ElementsAre(patients_[3], patients_[1]));
}

TEST_F(addPatientToQueueShould, NotEnQueuePatientsIfAlreadyEnqueuedForSpecificTreatment)
{
    Treatment tooth_extraction_treatment{Treatment::ToothExtraction};
    sut_.addPatientToQueue(tooth_extraction_treatment, patients_[3]);
    sut_.addPatientToQueue(tooth_extraction_treatment, patients_[0]);

    sut_.addPatientToQueue(tooth_extraction_treatment, patients_[3]);
    sut_.addPatientToQueue(tooth_extraction_treatment, patients_[0]);

    const auto tooth_extraction_queed_patients = sut_.getQueuedPatients(tooth_extraction_treatment);

    EXPECT_THAT(tooth_extraction_queed_patients, ElementsAre(patients_[3], patients_[0]));
}

TEST_F(addPatientToQueueShould, EnqueuePatientsForDoctorInCorrectOrder)
{
    sut_.addPatientToQueue(doctors_[0], patients_[2]);
    sut_.addPatientToQueue(doctors_[0], patients_[1]);

    sut_.addPatientToQueue(doctors_[1], patients_[2]);
    sut_.addPatientToQueue(doctors_[1], patients_[0]);

    sut_.addPatientToQueue(doctors_[2], patients_[1]);
    sut_.addPatientToQueue(doctors_[2], patients_[3]);

    const auto first_doctor_queued_patients = sut_.getQueuedPatients(doctors_[0]);
    const auto second_doctor_queued_patients = sut_.getQueuedPatients(doctors_[1]);
    const auto third_doctor_queued_patients = sut_.getQueuedPatients(doctors_[2]);

    EXPECT_THAT(first_doctor_queued_patients, ElementsAre(patients_[2], patients_[1]));
    EXPECT_THAT(second_doctor_queued_patients, ElementsAre(patients_[2], patients_[0]));
    EXPECT_THAT(third_doctor_queued_patients, ElementsAre(patients_[1], patients_[3]));
}

TEST_F(addPatientToQueueShould, NotEnQueuePatientsIfAlreadyEnqueuedForSpecificDoctor)
{
    sut_.addPatientToQueue(doctors_[1], patients_[2]);
    sut_.addPatientToQueue(doctors_[1], patients_[1]);
    sut_.addPatientToQueue(doctors_[1], patients_[0]);
    sut_.addPatientToQueue(doctors_[1], patients_[2]);
    sut_.addPatientToQueue(doctors_[1], patients_[0]);

    const auto doctor_queued_patients = sut_.getQueuedPatients(doctors_[1]);

    EXPECT_THAT(doctor_queued_patients, ElementsAre(patients_[2], patients_[1], patients_[0]));
}

class removePatientFromQueueShould : public ReserveQueueFixture
{
};

TEST_F(removePatientFromQueueShould, NotChangeTreatmentQueueIfPatientNotPresentInQueue)
{
    Treatment filling_treatment{Treatment::DentalFilling};
    sut_.addPatientToQueue(filling_treatment, patients_[1]);
    sut_.addPatientToQueue(filling_treatment, patients_[2]);

    Treatment tooth_extraction_treatment{Treatment::ToothExtraction};
    sut_.addPatientToQueue(tooth_extraction_treatment, patients_[3]);
    sut_.addPatientToQueue(tooth_extraction_treatment, patients_[0]);

    const auto filling_treatment_patients_before = sut_.getQueuedPatients(filling_treatment);
    const auto tooth_extraction_patients_before = sut_.getQueuedPatients(tooth_extraction_treatment);

    ASSERT_THAT(filling_treatment_patients_before, ElementsAre(patients_[1], patients_[2]));
    ASSERT_THAT(tooth_extraction_patients_before, ElementsAre(patients_[3], patients_[0]));

    sut_.removePatientFromQueue(filling_treatment, patients_[3]);
    sut_.removePatientFromQueue(tooth_extraction_treatment, patients_[1]);

    const auto filling_treatment_patients_after = sut_.getQueuedPatients(filling_treatment);
    const auto tooth_extraction_patients_after = sut_.getQueuedPatients(tooth_extraction_treatment);

    EXPECT_EQ(filling_treatment_patients_before, filling_treatment_patients_after);
    EXPECT_EQ(tooth_extraction_patients_before, tooth_extraction_patients_after);
}

TEST_F(removePatientFromQueueShould, NotChangeDoctorQueueIfPatientNotPresentInQueue)
{
    sut_.addPatientToQueue(doctors_[0], patients_[2]);
    sut_.addPatientToQueue(doctors_[0], patients_[1]);

    sut_.addPatientToQueue(doctors_[1], patients_[3]);
    sut_.addPatientToQueue(doctors_[1], patients_[0]);

    const auto first_doctor_patients_before = sut_.getQueuedPatients(doctors_[0]);
    const auto second_doctor_patients_before = sut_.getQueuedPatients(doctors_[1]);

    ASSERT_THAT(first_doctor_patients_before, ElementsAre(patients_[2], patients_[1]));
    ASSERT_THAT(second_doctor_patients_before, ElementsAre(patients_[3], patients_[0]));

    sut_.removePatientFromQueue(doctors_[0], patients_[3]);
    sut_.removePatientFromQueue(doctors_[1], patients_[1]);

    const auto first_doctor_patients_after = sut_.getQueuedPatients(doctors_[0]);
    const auto second_doctor_patients_after = sut_.getQueuedPatients(doctors_[1]);

    EXPECT_EQ(first_doctor_patients_before, first_doctor_patients_after);
    EXPECT_EQ(second_doctor_patients_before, second_doctor_patients_after);
}

TEST_F(removePatientFromQueueShould, NotAddTreatmentKeyIfRemovalRequestedFromEmptyList)
{
    const auto treatments_awaiting_before = sut_.getTreatmentQueues();
    ASSERT_TRUE(treatments_awaiting_before.empty());

    sut_.removePatientFromQueue(Treatment::DentalFilling, patients_[0]);
    sut_.removePatientFromQueue(Treatment::ToothExtraction, patients_[1]);

    expectTreatmentQueuesEmpty();
}

TEST_F(removePatientFromQueueShould, NotAddDoctorKeyIfRemovalRequestedFromEmptyList)
{
    const auto doctors_with_patients_awaiting_appointments_before = sut_.getDoctorQueues();
    ASSERT_TRUE(doctors_with_patients_awaiting_appointments_before.empty());

    sut_.removePatientFromQueue(doctors_[0], patients_[0]);
    sut_.removePatientFromQueue(doctors_[1], patients_[1]);

    expectDoctorQueuesEmpty();
}

TEST_F(removePatientFromQueueShould, RemovePatientFromBeginningOfSpecificTreatmentQueue)
{
    Treatment filling_treatment{Treatment::DentalFilling};
    sut_.addPatientToQueue(filling_treatment, patients_[0]);
    sut_.addPatientToQueue(filling_treatment, patients_[2]);

    const auto filling_treatment_patients_before = sut_.getQueuedPatients(filling_treatment);

    ASSERT_THAT(filling_treatment_patients_before, ElementsAre(patients_[0], patients_[2]));

    sut_.removePatientFromQueue(filling_treatment, patients_[0]);
    const auto filling_treatment_patients_after = sut_.getQueuedPatients(filling_treatment);

    EXPECT_NE(filling_treatment_patients_before, filling_treatment_patients_after);
    EXPECT_THAT(filling_treatment_patients_after, ElementsAre(patients_[2]));
}

TEST_F(removePatientFromQueueShould, RemovePatientFromTheMiddleOfSpecificTreatmentQueue)
{
    Treatment filling_treatment{Treatment::DentalFilling};
    sut_.addPatientToQueue(filling_treatment, patients_[0]);
    sut_.addPatientToQueue(filling_treatment, patients_[2]);
    sut_.addPatientToQueue(filling_treatment, patients_[3]);

    const auto filling_treatment_patients_before = sut_.getQueuedPatients(filling_treatment);
    ASSERT_THAT(filling_treatment_patients_before, ElementsAre(patients_[0], patients_[2], patients_[3]));

    sut_.removePatientFromQueue(filling_treatment, patients_[2]);
    const auto filling_treatment_patients_after = sut_.getQueuedPatients(filling_treatment);

    EXPECT_NE(filling_treatment_patients_before, filling_treatment_patients_after);
    EXPECT_THAT(filling_treatment_patients_after, ElementsAre(patients_[0], patients_[3]));
}

TEST_F(removePatientFromQueueShould, RemovePatientFromTheEndOfSpecificTreatmentQueue)
{
    Treatment filling_treatment{Treatment::DentalFilling};
    sut_.addPatientToQueue(filling_treatment, patients_[0]);
    sut_.addPatientToQueue(filling_treatment, patients_[2]);

    const auto filling_treatment_patients_before = sut_.getQueuedPatients(filling_treatment);

    ASSERT_THAT(filling_treatment_patients_before, ElementsAre(patients_[0], patients_[2]));

    sut_.removePatientFromQueue(filling_treatment, patients_[2]);
    const auto filling_treatment_patients_after = sut_.getQueuedPatients(filling_treatment);

    EXPECT_NE(filling_treatment_patients_before, filling_treatment_patients_after);
    EXPECT_THAT(filling_treatment_patients_after, ElementsAre(patients_[0]));
}

TEST_F(removePatientFromQueueShould, RemoveTreatmentKeyIfLastPatientAwaitingRemoved)
{
    Treatment filling_treatment{Treatment::DentalFilling};
    sut_.addPatientToQueue(filling_treatment, patients_[0]);
    sut_.addPatientToQueue(filling_treatment, patients_[1]);

    Treatment tooth_extraction_treatment{Treatment::ToothExtraction};
    sut_.addPatientToQueue(tooth_extraction_treatment, patients_[3]);
    sut_.addPatientToQueue(tooth_extraction_treatment, patients_[0]);

    const auto treatment_queues_before = sut_.getTreatmentQueues();
    ASSERT_EQ(treatment_queues_before.size(), 2);
    ASSERT_TRUE(treatment_queues_before.contains(Treatment::DentalFilling));
    ASSERT_TRUE(treatment_queues_before.contains(Treatment::ToothExtraction));

    sut_.removePatientFromQueue(filling_treatment, patients_[0]);
    sut_.removePatientFromQueue(filling_treatment, patients_[1]);
    const auto treatment_queues_after_removing_filling_patients = sut_.getTreatmentQueues();

    sut_.removePatientFromQueue(tooth_extraction_treatment, patients_[3]);
    sut_.removePatientFromQueue(tooth_extraction_treatment, patients_[0]);
    const auto treatment_queues_after_removing_last_patients = sut_.getTreatmentQueues();

    EXPECT_EQ(treatment_queues_after_removing_filling_patients.size(), 1);
    EXPECT_TRUE(treatment_queues_after_removing_filling_patients.contains(Treatment::ToothExtraction));
    EXPECT_FALSE(treatment_queues_after_removing_filling_patients.contains(Treatment::DentalFilling));

    expectTreatmentQueuesEmpty();
}

TEST_F(removePatientFromQueueShould, RemovePatientFromBeginningOfSpecificDoctorQueue)
{
    sut_.addPatientToQueue(doctors_[0], patients_[3]);
    sut_.addPatientToQueue(doctors_[0], patients_[2]);

    const auto doctor_queued_patients_before = sut_.getQueuedPatients(doctors_[0]);
    ASSERT_THAT(doctor_queued_patients_before, ElementsAre(patients_[3], patients_[2]));

    sut_.removePatientFromQueue(doctors_[0], patients_[3]);
    const auto doctor_queued_patients_after = sut_.getQueuedPatients(doctors_[0]);

    EXPECT_NE(doctor_queued_patients_before, doctor_queued_patients_after);
    EXPECT_THAT(doctor_queued_patients_after, ElementsAre(patients_[2]));
}

TEST_F(removePatientFromQueueShould, RemovePatientFromTheMiddleOfSpecificDoctorQueue)
{
    sut_.addPatientToQueue(doctors_[0], patients_[3]);
    sut_.addPatientToQueue(doctors_[0], patients_[2]);
    sut_.addPatientToQueue(doctors_[0], patients_[1]);

    const auto doctor_queued_patients_before = sut_.getQueuedPatients(doctors_[0]);
    ASSERT_THAT(doctor_queued_patients_before, ElementsAre(patients_[3], patients_[2], patients_[1]));

    sut_.removePatientFromQueue(doctors_[0], patients_[2]);
    const auto doctor_queued_patients_after = sut_.getQueuedPatients(doctors_[0]);

    EXPECT_NE(doctor_queued_patients_before, doctor_queued_patients_after);
    EXPECT_THAT(doctor_queued_patients_after, ElementsAre(patients_[3], patients_[1]));
}

TEST_F(removePatientFromQueueShould, RemovePatientFromTheEndOfSpecificDoctorQueue)
{
    sut_.addPatientToQueue(doctors_[0], patients_[3]);
    sut_.addPatientToQueue(doctors_[0], patients_[2]);

    const auto doctor_queued_patients_before = sut_.getQueuedPatients(doctors_[0]);
    ASSERT_THAT(doctor_queued_patients_before, ElementsAre(patients_[3], patients_[2]));

    sut_.removePatientFromQueue(doctors_[0], patients_[2]);
    const auto doctor_queued_patients_after = sut_.getQueuedPatients(doctors_[0]);

    EXPECT_NE(doctor_queued_patients_before, doctor_queued_patients_after);
    EXPECT_THAT(doctor_queued_patients_after, ElementsAre(patients_[3]));
}

TEST_F(removePatientFromQueueShould, RemoveDoctorKeyIfLastPatientAwaitingRemoved)
{
    sut_.addPatientToQueue(doctors_[0], patients_[3]);
    sut_.addPatientToQueue(doctors_[0], patients_[2]);

    sut_.addPatientToQueue(doctors_[1], patients_[2]);
    sut_.addPatientToQueue(doctors_[1], patients_[0]);

    const auto doctor_queues_before = sut_.getDoctorQueues();
    ASSERT_EQ(doctor_queues_before.size(), 2);
    ASSERT_TRUE(doctor_queues_before.contains(doctors_[0]));
    ASSERT_TRUE(doctor_queues_before.contains(doctors_[1]));

    sut_.removePatientFromQueue(doctors_[0], patients_[3]);
    sut_.removePatientFromQueue(doctors_[0], patients_[2]);
    const auto doctor_queues_after_removing_first_doctor_patients = sut_.getDoctorQueues();

    sut_.removePatientFromQueue(doctors_[1], patients_[2]);
    sut_.removePatientFromQueue(doctors_[1], patients_[0]);
    const auto doctor_queues_after_after_removing_second_doctor_patients = sut_.getDoctorQueues();

    EXPECT_EQ(doctor_queues_after_removing_first_doctor_patients.size(), 1);
    EXPECT_TRUE(doctor_queues_after_removing_first_doctor_patients.contains(doctors_[1]));
    EXPECT_FALSE(doctor_queues_after_removing_first_doctor_patients.contains(doctors_[0]));
    expectDoctorQueuesEmpty();
}

class getQueuedPatientsShould : public ReserveQueueFixture
{
};

TEST_F(getQueuedPatientsShould, ReturnEmptyQueueIfNoPatientForTreatmentQueued)
{
    sut_.addPatientToQueue(Treatment::DentalSealants, patients_[0]);
    sut_.addPatientToQueue(Treatment::GumSurgery, patients_[1]);
    ASSERT_FALSE(sut_.getQueuedPatients(Treatment::DentalSealants).empty());
    ASSERT_FALSE(sut_.getQueuedPatients(Treatment::GumSurgery).empty());

    EXPECT_TRUE(sut_.getQueuedPatients(Treatment::ToothExtraction).empty());
    EXPECT_TRUE(sut_.getQueuedPatients(Treatment::OTHER).empty());
}

TEST_F(getQueuedPatientsShould, ReturnEmptyQueueIfNoPatientForDoctorQueued)
{
    sut_.addPatientToQueue(doctors_[0], patients_[0]);
    sut_.addPatientToQueue(doctors_[1], patients_[1]);
    ASSERT_FALSE(sut_.getQueuedPatients(doctors_[0]).empty());
    ASSERT_FALSE(sut_.getQueuedPatients(doctors_[1]).empty());

    EXPECT_TRUE(sut_.getQueuedPatients(doctors_[2]).empty());
}

TEST_F(getQueuedPatientsShould, NotInsertTreatmentQueueKeyIfPatientForEmptyQueueRequested)
{
    const auto treatments_awaiting_before = sut_.getTreatmentQueues();
    expectTreatmentQueuesEmpty();

    const auto patients_awaiting_treatment = sut_.getQueuedPatients(Treatment::ToothExtraction);
    const auto treatments_awaiting_after = sut_.getTreatmentQueues();

    EXPECT_TRUE(patients_awaiting_treatment.empty());
    expectTreatmentQueuesEmpty();
}

class getTreatmentQueuesShould : public ReserveQueueFixture
{
};

TEST_F(getTreatmentQueuesShould, ReturnEmptyTreatmentQueuesCollectionAfterReserveQueueInitialisation)
{
    expectTreatmentQueuesEmpty();
}

TEST_F(getTreatmentQueuesShould, ReturnQueuesForAllTreatments)
{
    Treatment filling_treatment{Treatment::DentalFilling};
    sut_.addPatientToQueue(filling_treatment, patients_[0]);
    sut_.addPatientToQueue(filling_treatment, patients_[1]);

    Treatment tooth_extraction_treatment{Treatment::ToothExtraction};
    sut_.addPatientToQueue(tooth_extraction_treatment, patients_[3]);
    sut_.addPatientToQueue(tooth_extraction_treatment, patients_[0]);

    Treatment gum_surgery_treatment{Treatment::GumSurgery};
    sut_.addPatientToQueue(gum_surgery_treatment, patients_[2]);

    auto allTreatmentQueues = sut_.getTreatmentQueues();

    EXPECT_EQ(allTreatmentQueues.size(), 3);
    EXPECT_THAT(allTreatmentQueues[filling_treatment], ElementsAre(patients_[0], patients_[1]));
    EXPECT_THAT(allTreatmentQueues[tooth_extraction_treatment], ElementsAre(patients_[3], patients_[0]));
    EXPECT_THAT(allTreatmentQueues[gum_surgery_treatment], ElementsAre(patients_[2]));
}

class getDoctorQueuesShould : public ReserveQueueFixture
{
};

TEST_F(getDoctorQueuesShould, ReturnEmptyDoctorQueuesCollectionAfterReserveQueueInitialisation)
{
    expectDoctorQueuesEmpty();
}

TEST_F(getDoctorQueuesShould, ReturnQueuesForAllDoctors)
{
    sut_.addPatientToQueue(doctors_[0], patients_[3]);
    sut_.addPatientToQueue(doctors_[0], patients_[2]);

    sut_.addPatientToQueue(doctors_[1], patients_[1]);
    sut_.addPatientToQueue(doctors_[1], patients_[0]);

    sut_.addPatientToQueue(doctors_[2], patients_[2]);
    sut_.addPatientToQueue(doctors_[2], patients_[3]);

    auto allDoctorQueues = sut_.getDoctorQueues();

    EXPECT_EQ(allDoctorQueues.size(), 3);
    EXPECT_THAT(allDoctorQueues[doctors_[0]], ElementsAre(patients_[3], patients_[2]));
    EXPECT_THAT(allDoctorQueues[doctors_[1]], ElementsAre(patients_[1], patients_[0]));
    EXPECT_THAT(allDoctorQueues[doctors_[2]], ElementsAre(patients_[2], patients_[3]));
}

} // namespace
