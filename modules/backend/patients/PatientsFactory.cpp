#include "PatientsFactory.hpp"

#include "patient/Patient.hpp"

namespace patient
{

// std::vector<std::unique_ptr<iPatient>> initializePatients([[maybe_unused]] const serializer::Serializer& serializer)
// {
//     std::vector<std::unique_ptr<iPatient>> patients;
//     // Expected that Patient data will be deserialized and
//     // emplaced in patient vector, something like following way:
//     // for(const auto& patient : serializer.DeserializePatients())
//     // {
//     //     patients.emplace_back(std::make_unique<iPatient>(patient));
//     // }
//     // other deserialized objects should follow the same approach
//     patients.emplace_back(std::make_unique<Patient>());

//     return patients;
// }

} // namespace patient
