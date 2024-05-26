#include "visit_test.hpp"

#include <algorithm>

namespace
{

TEST_F(VisitTestFixture, GivenVisitExpectDoctorValidData)
{
    const auto visit = Clinic::getTempVisit();

    const auto assigned_doctor = visit->getDoctor();
    const auto expected_name = "Jan";
    const auto expected_surname = "Kowalski";

    EXPECT_EQ(assigned_doctor.lock()->getName(), expected_name);
    EXPECT_EQ(assigned_doctor.lock()->getSurname(), expected_surname);
}

TEST_F(VisitTestFixture, GivenVisitInformationExpectInformationReturned)
{
    const auto visit = Clinic::getTempVisit();
    const std::string visit_information{"Patient absent"};
    visit->setVisitInformation(visit_information);
    const auto visit_info = visit->getVisitInformation();

    EXPECT_EQ(visit_info, visit_information);
}

TEST_F(VisitTestFixture, GivenDefaultTreatmentExpectTreatmentsEmpty)
{
    const auto visit = Clinic::getTempVisit();
    const auto visit_treatments = visit->getTreatments();
    const auto expected_treatments{std::vector<Treatment>{}};

    EXPECT_EQ(visit_treatments, expected_treatments);
}

TEST_F(VisitTestFixture, GivenTreatmentSetExpectTreatmentsUpdated)
{
    const auto visit = Clinic::getTempVisit();

    const std::vector expected_treatments = {Treatment::DentalFilling, Treatment::DentalSealants};

    visit->updateTreatments(expected_treatments);
    const auto visit_treatments = visit->getTreatments();

    EXPECT_EQ(visit_treatments, expected_treatments);
}

TEST_F(VisitTestFixture, GivenVisitAddedViaPatientExpectCorrectConnectionBetweenObjects)
{
    const auto visit = Clinic::getTempVisit();
    Patient::createPatient("Dawid", "Goliat", "72080357978", Gender::Male);
    const auto patient = Clinic::getPatients().front();

    patient->addVisit(visit);

    EXPECT_EQ(visit->getPatient().lock()->getName(), "Dawid");
    EXPECT_EQ(*(visit->getPatient().lock()->getVisits().begin()), visit);
    EXPECT_EQ((*(patient->getVisits().begin()))->getPatient().lock(), patient);
}

TEST_F(VisitTestFixture, GivenPatientAddedViaVisitExpectCorrectConnectionBetweenObjects)
{
    const auto visit = Clinic::getTempVisit();
    Patient::createPatient("Dawid", "Goliat", "99053033817", Gender::Male);
    const auto patient = Clinic::getPatients().front();

    visit->setPatient(patient);

    EXPECT_EQ(visit->getPatient().lock()->getName(), "Dawid");
    EXPECT_EQ(*(visit->getPatient().lock()->getVisits().begin()), visit);
    EXPECT_EQ((*(patient->getVisits().begin()))->getPatient().lock(), patient);
}

TEST_F(VisitTestFixture, GivenVisitAddedViaRoomExpectCorrectConnectionBetweenObjects)
{
    const auto visit = Clinic::getTempVisit();
    Room::createRoom(1, Clinic::getWarehouse());
    const auto room = Clinic::getRooms().front();

    room->addVisit(visit);

    EXPECT_EQ(visit->getRoom().lock()->getRoomNumber(), 1);
    EXPECT_EQ(*(visit->getRoom().lock()->getVisits().begin()), visit);
    EXPECT_EQ((*(room->getVisits().begin()))->getRoom().lock(), room);
}

} // namespace
