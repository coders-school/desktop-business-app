#include "doctor.hpp"

#include "visit_test.hpp"

#include <algorithm>

namespace
{
TEST_F(VisitTestsFixture, ExtentDemo)
{
    const auto content = Visit::getExtent().size();
    const auto expected = 3;
    EXPECT_EQ(content, expected);
}

TEST_F(VisitTestsFixture, AssociationDemo)
{
    const auto content = visit1->getDoctorAssociation()->getLastName();
    const auto expected = "Tracz";
    EXPECT_EQ(content, expected);
}

TEST_F(VisitTestsFixture, AssociationDemo2)
{
    const auto content = doc2->getVisitAssociations().begin()->get()->getVisitInformation();
    const auto expected = "Tworze klub ninja!";
    EXPECT_EQ(content, expected);
}

TEST_F(VisitTestsFixture, AssociationDemo3)
{
    std::string content;
    const auto associations = doc2->getVisitAssociations();

    const auto expected = "I w klubie sa sami fajni ludzie";

    bool associationsContainExpectedVisitInformation = std::ranges::any_of(
        associations, [&expected](const auto& visitSPtr) { return visitSPtr->getVisitInformation() == expected; });

    EXPECT_TRUE(associationsContainExpectedVisitInformation);
}

TEST_F(VisitTestsFixture, UpdateTreatmentsShouldReplacePreviouslyStoredTreatments)
{
    const auto visitOneTreatmentsBefore = visit1->getTreatments();
    const auto visitTwoTreatmentsBefore = visit2->getTreatments();
    const auto visitThreeTreatmentsBefore = visit3->getTreatments();
    ASSERT_TRUE(visitOneTreatmentsBefore.empty());
    ASSERT_EQ(visitTwoTreatmentsBefore, std::vector{Treatment::TeethWhitening});
    ASSERT_EQ(visitThreeTreatmentsBefore,
              (std::vector{Treatment::TeethCleaning, Treatment::RootCanal, Treatment::ToothExtraction}));

    std::vector newTreatmentsForVisit1 = {Treatment::GumSurgery};
    std::vector newTreatmentsForVisit2 = {Treatment::DentalFilling, Treatment::DentalSealants};

    updateVisitTreatments(newTreatmentsForVisit1, newTreatmentsForVisit2, {});

    EXPECT_EQ(visit1->getTreatments(), newTreatmentsForVisit1);
    EXPECT_EQ(visit2->getTreatments(), newTreatmentsForVisit2);
    EXPECT_TRUE(visit3->getTreatments().empty());
}

} // namespace
