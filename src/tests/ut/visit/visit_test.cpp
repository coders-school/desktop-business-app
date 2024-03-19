#include "doctor.hpp"

#include "visit_test.hpp"

namespace
{
TEST_F(AssociationTest, ExtentDemo)
{
    auto content = Visit::getExtent().size();
    auto expected = 3;
    EXPECT_EQ(content, expected);
}

TEST_F(AssociationTest, AssociationDemo)
{
    auto content = visit1->getDoctorAssociation()->getLastName();
    auto expected = "Tracz";
    EXPECT_EQ(content, expected);
}

TEST_F(AssociationTest, AssociationDemo2)
{
    auto content = doc2->getVisitAssociations().begin()->get()->getVisitInformation();
    auto expected = "Tworze klub ninja!";
    EXPECT_EQ(content, expected);
}

TEST_F(AssociationTest, AssociationDemo3)
{
    std::string content;
    auto associations = doc2->getVisitAssociations();
    if (auto it = associations.begin(); it != associations.end())
    {
        std::advance(it, 1);
        if (it != doc2->getVisitAssociations().end())
        {
            content = it->get()->getVisitInformation();
        }
        else
        {
            content = "null";
        }
    }
    auto expected = "I w klubie sa sami fajni ludzie";
    EXPECT_EQ(content, expected);
}

} // namespace
