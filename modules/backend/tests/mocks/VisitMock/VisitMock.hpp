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
    MOCK_METHOD(void, setPaymentInfo, (const patient::Payments&), (override));
    MOCK_METHOD(void, setTreatmentsInfo, (const patient::Treatments&), (override));
    MOCK_METHOD(void, setRoom, (const clinic::room::iRoom&), (override));
};
} // namespace visit
