#include "doctor.hpp"

#include "visit_test.hpp"

#include <algorithm>

namespace
{
TEST_F(VisitTestsFixture, ExtentDemo)
{
    auto content = Visit::getExtent().size();
    auto expected = 3;
    EXPECT_EQ(content, expected);
}

TEST_F(VisitTestsFixture, AssociationDemo)
{
    auto content = visit1->getDoctorAssociation()->getLastName();
    auto expected = "Tracz";
    EXPECT_EQ(content, expected);
}

TEST_F(VisitTestsFixture, AssociationDemo2)
{
    auto content = doc2->getVisitAssociations().begin()->get()->getVisitInformation();
    auto expected = "Tworze klub ninja!";
    EXPECT_EQ(content, expected);
}

TEST_F(VisitTestsFixture, AssociationDemo3)
{
    std::string content;
    auto associations = doc2->getVisitAssociations();

    auto expected = "I w klubie sa sami fajni ludzie";

    EXPECT_TRUE(std::ranges::any_of(
        associations, [&expected](const auto& visitSPtr) { return visitSPtr->getVisitInformation() == expected; }));
}

TEST_F(VisitTestsFixture, UpdateTreatmentsShouldReplacePreviouslyStoredTreatments)
{
    auto visitOneTreatmentsBefore = visit1->getTreatments();
    auto visitTwoTreatmentsBefore = visit2->getTreatments();
    auto visitThreeTreatmentsBefore = visit3->getTreatments();
    // initial asserts
    ASSERT_TRUE(visitOneTreatmentsBefore.empty());
    ASSERT_EQ(visitTwoTreatmentsBefore, std::vector{Treatment::TeethWhitening});
    ASSERT_EQ(visitThreeTreatmentsBefore,
              (std::vector{Treatment::TeethCleaning, Treatment::RootCanal, Treatment::ToothExtraction}));

    // update treatments for visit
    std::vector newTreatmentsForVisit1 = {Treatment::GumSurgery};
    std::vector newTreatmentsForVisit2 = {Treatment::DentalFilling, Treatment::DentalSealants};
    visit1->updateTreatments(newTreatmentsForVisit1);
    visit2->updateTreatments(newTreatmentsForVisit2);
    visit3->updateTreatments({});

    EXPECT_EQ(visit1->getTreatments(), newTreatmentsForVisit1);
    EXPECT_EQ(visit2->getTreatments(), newTreatmentsForVisit2);
    EXPECT_TRUE(visit3->getTreatments().empty());
}

} // namespace
