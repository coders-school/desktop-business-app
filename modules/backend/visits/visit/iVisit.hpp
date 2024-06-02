#pragma once

namespace clinic
{
namespace room
{
class iRoom;
} // namespace room
namespace staff
{
namespace doctor
{
class iDoctor;
}
} // namespace staff
} // namespace clinic

namespace patient
{
class iPatient;
class Payments;
class Treatments;
} // namespace patient

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
    virtual void setPaymentInfo(const patient::Payments&) = 0;
    virtual void setTreatmentsInfo(const patient::Treatments&) = 0;
    virtual void setRoom(const clinic::room::iRoom&) = 0;
};

} // namespace visit
