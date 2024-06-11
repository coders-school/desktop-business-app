#pragma once

#include "../common/personal_data/pesel/Pesel.hpp"
#include "patient/Patient.hpp"
#include "patient/iPatient.hpp"

#include <memory>
#include <vector>

namespace patient
{
class PatientCollection
{
  public:
    PatientCollection(std::vector<Patient> patients);

    void AppendPatient(Patient patient);
    // this method should be used within context of data visualization
    // data visualization class should format Patient data accordingly
    // to the context in which it will be used e.g. doctors view, receptionist view etc.

    std::shared_ptr<Patient> getPatient(common::Pesel pesel);
    void removePatient(common::Pesel pesel);
    std::vector<Patient>& getPatients();

  private:
    std::vector<Patient> patients_;
};

} // namespace patient
