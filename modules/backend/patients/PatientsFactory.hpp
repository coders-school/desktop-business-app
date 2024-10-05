#pragma once

#include <memory>
#include <vector>


namespace patient
{

class iPatient;

/*
 * initializes Patients from serialized data.
 * Shall be performed only once when application is started.
 */
// std::vector<std::unique_ptr<iPatient>> initializePatients(const serializer::Serializer& serializer);
// this free functions should be in single file
// and only be accessible within start of the program section.

} // namespace patient
