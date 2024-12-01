#pragma once

#include "patient/iPatient.hpp"
#include "patient/payments/Payments.hpp"
#include "patient/treatments/Treatments.hpp"
#include "room/iRoom.hpp"
#include "staff/doctors/iDoctor.hpp"

namespace visit
{

// visits in future might be separated by type (completed, planned, canceled)
// thus iterface could help manage different types of visits
class iVisit
{
  public:
    virtual ~iVisit() = default;
    virtual void setDoctorInfo(const clinic::staff::doctor::iDoctor&) = 0;
    virtual void setPatientInfo(const patient::iPatient&) = 0;
    // // TODO check if payment should be extracted from patient context
    virtual void setPayment(const patient::Payments&) = 0;
    virtual void setTreatmentsInfo(const patient::Treatments&) = 0;
    virtual void setRoom(const clinic::room::iRoom&) = 0;
    virtual patient::Payments getPayment() const = 0;
};

} // namespace visit
