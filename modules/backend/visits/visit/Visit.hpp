#pragma once

#include "modules/backend/patients/patient/iPatient.hpp"
#include <vector>

namespace visit
{

class Visit
{

    // std::vector<Treatment> actual_treatment_;
    // on gui, doctor should select treatment/s for exact visit
  public:
    // used to set informations required for visit from patient
    void SetPatientInfo(const patient::iPatient& patient)
    {
        // patient.GetPatientInfo();
    }
    void FinishVisit()
    {
        // const TreatmentState treatment_state = TreatmentState::Done;
        // patient_.UpdateTreatment(treatment_state, actual_treatment_);
    }
};

// Please add who created a Visit and when it was created.

} // namespace visit