#include "PatientCollection.hpp"

namespace patient
{

PatientCollection::PatientCollection(std::vector<Patient> patients) : patients_{std::move(patients)}
{
}

void PatientCollection::AppendPatient(Patient patient)
{
    // patients_.emplace_back(std::make_unique<iPatient>(patient));
    patients_.emplace_back(std::move(patient));
}
// this method should be used within context of data visualization
// data visualization class should format Patient data accordingly
// to the context in which it will be used e.g. doctors view, receptionist view etc.

std::shared_ptr<Patient> PatientCollection::getPatient(common::Pesel pesel)
{
    for (auto& patient : patients_)
    {
        if (patient.getPesel() == pesel)
        {
            return std::make_shared<Patient>(patient);
        }
    }
    return nullptr;
}

void PatientCollection::removePatient(common::Pesel pesel)
{
    for (auto It = begin(patients_); It != end(patients_); It++)
    {
        if (It->getPesel() == pesel)
        {
            patients_.erase(It);
        }
    }
}

std::vector<Patient>& PatientCollection::getPatients()
{
    return patients_;
}

} // namespace patient
