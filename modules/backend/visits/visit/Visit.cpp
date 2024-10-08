#include "Visit.hpp"

namespace visit
{

void Visit::setDoctorInfo([[maybe_unused]] const clinic::staff::doctor::iDoctor& doctor)
{
}

void Visit::setPatientInfo([[maybe_unused]] const patient::iPatient& patient)
{
}

void Visit::setPaymentInfo([[maybe_unused]] const patient::Payments& payments)
{
}

void Visit::setRoom([[maybe_unused]] const clinic::room::iRoom& room)
{
}

void Visit::setTreatmentsInfo([[maybe_unused]] const patient::Treatments& treatments)
{
}

} // namespace visit
