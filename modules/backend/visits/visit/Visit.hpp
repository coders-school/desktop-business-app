#pragma once

#include "modules/backend/visits/visit/iVisit.hpp"
#include <vector>

namespace visit
{

class Visit
{

    // std::vector<Treatment> actual_treatment_;
    // on gui, doctor should select treatment/s for exact visit
  public:
    // used to set informations required for visit from patient
    void setDoctorInfo(const clinic::staff::doctor::iDoctor& doctor);
    void setPatientInfo(const patient::iPatient& patient);
    void setPaymentInfo(const patient::Payments& payments);
    void setRoom(const clinic::room::iRoom& room);
    void setTreatmentsInfo(const patient::Treatments& treatments);
};

// Please add who created a Visit and when it was created.

} // namespace visit
