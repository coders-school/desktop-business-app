#pragma once

#include "modules/backend/patients/patient/i_patient.hpp"
#include <vector>

class Visit
{

    // std::vector<Treatment> actual_treatment_;
    // on gui, doctor should select treatment/s for exact visit
  public:
  // used to set informations required for visit from patient
  void SetPatientInfo(const iPatient& patient) 
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
