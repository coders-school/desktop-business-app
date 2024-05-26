#pragma once

#include "clinic_facade.hpp"
#include "doctor.hpp"
#include "test_utils.hpp"
#include "gtest/gtest.h"

class DoctorTestFixture : public ::testing::Test
{
  protected:
    void TearDown() override
    {
        cleanupClinic();
    }

    void checkIfDoctorHasVisits(const std::shared_ptr<Doctor>& doctor,
                                const std::vector<std::string>& visitInformationsList) const
    {
        const auto& all_visits_for_doctor = doctor->getVisits();
        const std::size_t expected_size = visitInformationsList.size();
        ASSERT_EQ(all_visits_for_doctor.size(), expected_size);

        for (std::size_t i = 0; i < expected_size; ++i)
        {
            EXPECT_EQ(all_visits_for_doctor.at(i)->getVisitInformation(), visitInformationsList[i]);
        }
    }

    void createThreeSimpleVisits(const std::shared_ptr<Doctor>& doctor) const
    {
        createVisitWithInformation(doctor, "first visit");
        createVisitWithInformation(doctor, "second visit");
        createVisitWithInformation(doctor, "third visit");
    }

    void createVisitWithInformation(const std::shared_ptr<Doctor>& doctor, const std::string& visitInformation) const
    {
        Visit::createTempVisit(doctor);
        Clinic::getTempVisit()->setVisitInformation(visitInformation);
    }
};
