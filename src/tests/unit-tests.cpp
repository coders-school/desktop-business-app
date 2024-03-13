#include "gtest/gtest.h"
#include "../app/doctor/doctor.hpp"
#include "../app/visit/visit.hpp"

struct AssociationTest : ::testing::Test{
    std::shared_ptr<Doctor> doc1{std::make_shared<Doctor>("Janusz", "Tracz", "1234")};
    std::shared_ptr<Doctor> doc2{std::make_shared<Doctor>("Łukasz", "Ziobroń", "123456")};

    std::shared_ptr<Visit> visit1;
    std::shared_ptr<Visit> visit2;
    std::shared_ptr<Visit> visit3;
    
    AssociationTest(){
        visit1 = Visit::createVisit(doc1);
        visit2 = Visit::createVisit(doc2);
        visit3 = Visit::createVisit(doc2);

        visit2->setVisitInfo("Tworzę klub ninja!");
        visit3->setVisitInfo("I w klubie są sami fajni ludzie");
    }
};

TEST_F(AssociationTest, ExtentDemo){
    auto content = Visit::getExtent().size();
    auto expected = 3;
    EXPECT_EQ(content, expected);
}

TEST_F(AssociationTest, AssociationDemo) {
    auto content = visit1->getDocAssociation()->getLastName();
    auto expected = "Tracz";
    EXPECT_EQ(content, expected);
}

TEST_F(AssociationTest, AssociationDemo2){
    auto content = doc2->getVisitAssociations().begin()->get()->getVisitInfo();
    auto expected = "Tworzę klub ninja!";
    EXPECT_EQ(content, expected);
}

TEST_F(AssociationTest, AssociationDemo3){
    std::string content;
    auto associations = doc2->getVisitAssociations();
    if (auto it = associations.begin(); it != associations.end()) {
        std::advance(it, 1);
        if(it != doc2->getVisitAssociations().end()){
            content = it->get()->getVisitInfo();
        }else{
            content = "null";
        }
    }
    auto expected = "I w klubie są sami fajni ludzie";
    EXPECT_EQ(content, expected);
}
