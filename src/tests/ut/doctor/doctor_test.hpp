#pragma once
#include "../../../app/doctor/doctor.hpp"
#include "gtest/gtest.h"

class DoctorTestFixture : public ::testing::Test{
    protected:

    void TearDown() override{
        for(auto& doc : ObjectPlus::getExtent<Doctor>()){
            ObjectPlus::removeFromExtent<Doctor>(std::any_cast<Doctor&>(doc));
        }
    }
};