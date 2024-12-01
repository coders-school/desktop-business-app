#include "Visit.hpp"

namespace visit
{

void Visit::setDoctorInfo([[maybe_unused]] const clinic::staff::doctor::iDoctor& doctor)
{
}

void Visit::setPatientInfo([[maybe_unused]] const patient::iPatient& patient)
{
}

void Visit::setPayment([[maybe_unused]] const patient::Payments& payments)
{
}

void Visit::setRoom([[maybe_unused]] const clinic::room::iRoom& room)
{
}

void Visit::setTreatmentsInfo([[maybe_unused]] const patient::Treatments& treatments)
{
}

patient::Payments Visit::getPayment() const
{
    return patient::Payments{};
}

} // namespace visit
