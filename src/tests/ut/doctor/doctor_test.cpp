#include "doctor_test.hpp"

namespace{

    TEST_F(DoctorTestFixture, DoctorClassExtentTestExpectValueCorrectName){
        const auto expected_value = "Janusz";
        Doctor doc1{"Janusz", "Tracz", "1234"};
        std::string value = std::any_cast<Doctor>(ObjectPlus::getExtent<Doctor>().front()).getFirstName();

        EXPECT_EQ(value, expected_value);
    }

    TEST_F(DoctorTestFixture, Test2){
        EXPECT_THROW(ObjectPlus::getExtent<Doctor>(), std::invalid_argument);
    }

    TEST_F(DoctorTestFixture, Test3){
        Doctor doc1{"Janusz", "Tracz", "1234"};
        Doctor doc2{"Łukasz", "Tracz", "12345"};
        const auto expected_value = 2;

        EXPECT_EQ(ObjectPlus::getExtent<Doctor>().size() , expected_value);
    }

} //namespace