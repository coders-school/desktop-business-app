#pragma once

// find better name for the interface
class iVisitPatient : public virtual iPatient
{
    // this interface shall be used within Visit context
    // it should provide methods that will allow to:
    // 1. set planned treatment
    // 2. update the treatment state (planned -> done) once Visit is fulfiled
    // 3. other..
  public:
    virtual void UpdateTreatment(const TreatmentState, const std::vector<Treatment>&) {};
    virtual ~iVisitPatient(){};
};