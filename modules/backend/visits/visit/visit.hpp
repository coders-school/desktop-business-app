#pragma once

class Visit
{
    iVisitPatient patient_;
    std::vector<Treatment> actual_treatment_;
    // on gui, doctor should select treatment/s for exact visit
  public:
    Visit(const Patient& patient) : patient_{patient}
    {
    }

    void FinishVisit()
    {
        const TreatmentState treatment_state = TreatmentState::Done;
        patient_.UpdateTreatment(treatment_state, actual_treatment_);
    }
};