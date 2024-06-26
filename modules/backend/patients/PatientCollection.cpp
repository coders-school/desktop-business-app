#include "PatientCollection.hpp"

namespace patient
{

PatientCollection::PatientCollection(std::vector<std::unique_ptr<iPatient>> patients) : patients_{std::move(patients)}
{
}

void PatientCollection::AppendPatient(std::unique_ptr<iPatient> patient)
{
    // patients_.emplace_back(std::make_unique<iPatient>(patient));
    patients_.emplace_back(std::move(patient));
}
// this method should be used within context of data visualization
// data visualization class should format Patient data accordingly
// to the context in which it will be used e.g. doctors view, receptionist view etc.
} // namespace patient
