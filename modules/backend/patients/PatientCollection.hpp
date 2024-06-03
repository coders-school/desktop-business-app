#pragma once

#include "patient/iPatient.hpp"

#include <memory>
#include <vector>

namespace patient
{
class PatientCollection
{
  public:
    PatientCollection(std::vector<std::unique_ptr<iPatient>> patients);

    void AppendPatient(std::unique_ptr<iPatient> patient);
    // this method should be used within context of data visualization
    // data visualization class should format Patient data accordingly
    // to the context in which it will be used e.g. doctors view, receptionist view etc.

  private:
    std::vector<std::unique_ptr<iPatient>> patients_;
};

} // namespace patient
