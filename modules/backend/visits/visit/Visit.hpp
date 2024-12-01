#pragma once

#include "enumerations/treatment/Treatment.hpp"
#include "iVisit.hpp"

#include <vector>

namespace visit
{

class Visit : public iVisit
{
  public:
    // used to set informations required for visit from patient
    void setDoctorInfo(const clinic::staff::doctor::iDoctor& doctor) override;
    void setPatientInfo(const patient::iPatient& patient) override;
    void setPayment(const patient::Payments& payments) override;
    void setRoom(const clinic::room::iRoom& room) override;
    void setTreatmentsInfo(const patient::Treatments& treatments) override;
    patient::Payments getPayment() const override;

  private:
    std::vector<common::treatment::Treatment> actual_treatment_;
    //  on gui, doctor should select treatment/s for exact visit
};

// Please add who created a Visit and when it was created.

} // namespace visit
