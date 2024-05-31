#pragma once

#include "modules/backend/patients/patient/iPatient.hpp"
#include <memory>
#include <vector>

class PatientCollection
{
    std::vector<std::unique_ptr<iPatient>> patients_;

  public:
    PatientCollection(std::vector<std::unique_ptr<iPatient>> patients) : patients_{std::move(patients)}
    {
    }
    void AppendPatient(const iPatient& patient)
    {
        patients_.emplace_back(std::make_unique<iPatient>(patient));
    }
    // this method should be used within context of data visualization
    // data visualization class should format Patient data accordingly
    // to the context in which it will be used e.g. doctors view, receptionist view etc.
};
