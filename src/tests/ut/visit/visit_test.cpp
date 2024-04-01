
#include "visit_test.hpp"

#include <algorithm>

namespace
{

TEST_F(VisitTestFixture, GivenVisitExpectDoctorValidData)
{
    const auto visit = Clinic::getVisits().front();

    const auto assigned_doctor = visit->getDoctor();
    const auto expected_name = "Jan";
    const auto expected_surname = "Kowalski";

    EXPECT_EQ(assigned_doctor->getName(), expected_name);
    EXPECT_EQ(assigned_doctor->getSurname(), expected_surname);
}

TEST_F(VisitTestFixture, GivenVisitInformationExpectInformationReturned)
{
    const auto visit = Clinic::getVisits().front();
    const std::string visit_information{"Patient absent"};
    visit->setVisitInformation(visit_information);
    const auto visit_info = visit->getVisitInformation();

    EXPECT_EQ(visit_info, visit_information);
}

TEST_F(VisitTestFixture, GivenDefaultTreatmentExpectTreatmentsEmpty)
{
    const auto visit = Clinic::getVisits().front();
    const auto visit_treatments = visit->getTreatments();
    const auto expected_treatments{std::vector<Treatment>{}};

    EXPECT_EQ(visit_treatments, expected_treatments);
}

TEST_F(VisitTestFixture, GivenTreatmentSetExpectTreatmentsUpdated)
{
    const auto visit = Clinic::getVisits().front();

    const std::vector expected_treatments = {Treatment::DentalFilling, Treatment::DentalSealants};

    visit->updateTreatments(expected_treatments);
    const auto visit_treatments = visit->getTreatments();

    EXPECT_EQ(visit_treatments, expected_treatments);
}

} // namespace
