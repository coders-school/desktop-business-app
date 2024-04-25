#include "clinic_test.hpp"

namespace
{

TEST_F(ClinicTestFixture, GivenStaticContainerWhenDoctorCreatedExpectContainerSizeIncreased)
{
    ASSERT_TRUE(Clinic::getDoctors().empty());

    Doctor::createDoctor("Jan", "Pawel", "00000000000", Gender::Male);

    EXPECT_EQ(Clinic::getDoctors().size(), 1U);
}

TEST_F(ClinicTestFixture, GivenStaticContainerWithDoctorWhenDoctorRemovedExpectContainerEmpty)
{
    ASSERT_TRUE(Clinic::getDoctors().empty());

    Doctor::createDoctor("Jan", "Pawel", "00000000000", Gender::Male);
    Clinic::removeDoctor(Clinic::getDoctors().front());

    EXPECT_TRUE(Clinic::getDoctors().empty());
}

TEST_F(ClinicTestFixture, GivenStaticContainersWhenDoctorAndVisitCreatedExpectContainersSizeIncreased)
{
    ASSERT_TRUE(Clinic::getDoctors().empty());

    Doctor::createDoctor("Jan", "Pawel", "00000000000", Gender::Male);
    Visit::createVisit(Clinic::getDoctors().front());

    EXPECT_EQ(Clinic::getDoctors().size(), 1U);
    EXPECT_EQ(Clinic::getVisits().size(), 1U);
}

TEST_F(ClinicTestFixture,
       GivenStaticConatinersWithDoctorAndVisitWhenVisitRemovedExpectAssociationRemovedAndVisitsContainerEmpty)
{
    ASSERT_TRUE(Clinic::getDoctors().empty());

    Doctor::createDoctor("Jan", "Pawel", "00000000000", Gender::Male);
    Visit::createVisit(Clinic::getDoctors().front());
    Clinic::removeVisit(Clinic::getVisits().front());

    EXPECT_TRUE(Clinic::getVisits().empty());
    EXPECT_TRUE(Clinic::getDoctors().front()->getVisits().empty());
}

TEST_F(ClinicTestFixture, GivenStaticContainerWhenReceptionistCreatedThenRemovedExpectContainerSizeIncreaseAndDecrease)
{
    ASSERT_TRUE(Clinic::getReceptionists().empty());

    Receptionist::createReceptionist("Jan", "Kowalski", "00000000000", Gender::Male);
    EXPECT_EQ(Clinic::getReceptionists().size(), 1U);

    Clinic::removeReceptionist(Clinic::getReceptionists().front());
    EXPECT_TRUE(Clinic::getReceptionists().empty());
}

TEST_F(ClinicTestFixture, GivenMultiplePatientsExpectCorrectNumberOfPatientsCreated)
{
    ASSERT_TRUE(Clinic::getPatients().empty());

    Patient::createPatient("Jan", "Kowalski", "00000000000", Gender::Male);
    Patient::createPatient("Pawel", "Awel", "999", Gender::Male);
    const size_t extected_size{2};

    EXPECT_EQ(Clinic::getPatients().size(), extected_size);
}

} // namespace
