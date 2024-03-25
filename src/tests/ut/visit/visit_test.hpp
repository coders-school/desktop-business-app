#pragma once

#include "visit.hpp"
#include "gtest/gtest.h"

class Doctor;

class VisitTestsFixture : public ::testing::Test
{
  protected:
    std::shared_ptr<Doctor> doc1{std::make_shared<Doctor>("Janusz", "Tracz", "1234")};
    std::shared_ptr<Doctor> doc2{std::make_shared<Doctor>("Lukasz", "Ziobron", "123456")};

    std::shared_ptr<Visit> visit1;
    std::shared_ptr<Visit> visit2;
    std::shared_ptr<Visit> visit3;

    VisitTestsFixture()
    {
        visit1 = Visit::createVisit(doc1);
        visit2 = Visit::createVisit(doc2, {Treatment::TeethWhitening});
        visit3 = Visit::createVisit(doc2, {Treatment::TeethCleaning, Treatment::RootCanal, Treatment::ToothExtraction});

        visit2->setVisitInformation("Tworze klub ninja!");
        visit3->setVisitInformation("I w klubie sa sami fajni ludzie");
    }

    void updateVisitTreatments(const std::vector<Treatment>& visit_1_replacing_treatments,
                               const std::vector<Treatment>& visit_2_replacing_treatments,
                               const std::vector<Treatment>& visit_3_replacing_treatments)
    {
        visit1->updateTreatments(visit_1_replacing_treatments);
        visit2->updateTreatments(visit_2_replacing_treatments);
        visit3->updateTreatments(visit_3_replacing_treatments);
    }
};
