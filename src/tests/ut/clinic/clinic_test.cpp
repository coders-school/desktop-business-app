#include "clinic_test.hpp"

namespace
{

TEST_F(ClinicTestFixture, GivenStaticContainerWhenDoctorCreatedExpectContainerSizeIncreased)
{
    EXPECT_TRUE(Clinic::getDoctors().empty());
    Doctor::createDoctor("Jan", "Pawel", "00000000000");

    EXPECT_EQ(Clinic::getDoctors().size(), 1U);
}

TEST_F(ClinicTestFixture, GivenStaticContainerWithDoctorWhenDoctorRemovedExpectContainerEmpty)
{
    Doctor::createDoctor("Jan", "Pawel", "00000000000");

    Clinic::removeDoctor(Clinic::getDoctors().front());
    EXPECT_TRUE(Clinic::getDoctors().empty());
}

TEST_F(ClinicTestFixture, GivenStaticContainersWhenDoctorAndVisitCreatedExpectContainersSizeIncreased)
{
    Doctor::createDoctor("Jan", "Pawel", "00000000000");
    Visit::createVisit(Clinic::getDoctors().front());

    EXPECT_EQ(Clinic::getDoctors().size(), 1U);
    EXPECT_EQ(Clinic::getVisits().size(), 1U);
}

TEST_F(ClinicTestFixture,
       GivenStaticConatinersWithDoctorAndVisitWhenVisitRemovedExpectAssociationRemovedAndVisitsContainerEmpty)
{
    Doctor::createDoctor("Jan", "Pawel", "00000000000");
    Visit::createVisit(Clinic::getDoctors().front());

    Clinic::removeVisit(Clinic::getVisits().front());
    EXPECT_TRUE(Clinic::getVisits().empty());
    EXPECT_TRUE(Clinic::getDoctors().front()->getVisits().empty());
}

TEST_F(ClinicTestFixture, GivenStaticContainerWhenReceptionistCreatedThenRemovedExpectContainerSizeIncreaseAndDecrease)
{
    EXPECT_TRUE(Clinic::getReceptionists().empty());

    Receptionist::createReceptionist("Jan", "Kowalski", "00000000000");
    EXPECT_EQ(Clinic::getReceptionists().size(), 1U);

    Clinic::removeReceptionist(Clinic::getReceptionists().front());
    EXPECT_TRUE(Clinic::getReceptionists().empty());
}
} // namespace
