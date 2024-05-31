#pragma once

#include "modules/backend/patients/patient/iPatient.hpp"
#include "modules/backend/serializer/Serializer.hpp"
#include <memory>
#include <vector>

namespace patient
{

/*
 * initializes Patients from serialized data.
 * Shall be performed only once when application is started.
 */
std::vector<std::unique_ptr<iPatient>> InitializePatients(const Serializer& serializer)
{
    // this free functions should be in single file
    // and only be accessible within start of the program section.
    std::vector<std::unique_ptr<iPatient>> patients;
    // Expected that Patient data will be deserialized and
    // emplaced in patient vector, something like following way:
    // for(const auto& patient : serializer.DeserializePatients())
    // {
    //     patients.emplace_back(std::make_unique<iPatient>(patient));
    // }
    // other deserialized objects should follow the same approach
    patients.emplace_back(std::make_unique<iPatient>());

    return patients;
}

} // namespace patient
