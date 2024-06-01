#pragma once

#include "modules/backend/clinic/room/iRoom.hpp"
#include "modules/backend/clinic/staff/doctor/iDoctor.hpp"
#include "modules/backend/patients/patient/iPatient.hpp"
#include "modules/backend/patients/patient/payments/Payments.hpp"
#include "modules/backend/patients/patient/treatments/Treatments.hpp"

namespace visit
{

// visits in future might be separated by type (completed, planned, canceled)
// thus iterface could help manage different types of visits
class iVisit
{
  public:
    virtual ~iVisit() = 0;
    virtual void setDoctorInfo(const clinic::staff::doctor::iDoctor&) = 0;
    virtual void setPatientInfo(const patient::iPatient&) = 0;
    // TODO check if payment should be extracted from patient context
    virtual void setPaymentInfo(const patient::Payments&) = 0;
    virtual void setTreatmentsInfo(const patient::Treatments&) = 0;
    virtual void setRoom(const clinic::room::iRoom&) = 0;
};

} // namespace visit
