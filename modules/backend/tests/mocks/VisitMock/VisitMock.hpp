#pragma once

#include "visit/iVisit.hpp"
#include <gmock/gmock.h>

namespace visit
{
class MockVisit : public iVisit
{
  public:
    MOCK_METHOD(void, setDoctorInfo, (const clinic::staff::doctor::iDoctor&), (override));
    MOCK_METHOD(void, setPatientInfo, (const patient::iPatient&), (override));
    MOCK_METHOD(void, setPayment, (const patient::Payments&), (override));
    MOCK_METHOD(void, setTreatmentsInfo, (const patient::Treatments&), (override));
    MOCK_METHOD(void, setRoom, (const clinic::room::iRoom&), (override));
    MOCK_METHOD(patient::Payments, getPayment, (), (const, override));
};

} // namespace visit

using StrictMockVisit = ::testing::StrictMock<visit::MockVisit>;
