#include "DoctorFactory.hpp"

namespace clinic
{
namespace staff
{
namespace doctor
{

DoctorPtr createDoctor(const common::PersonalData& personal_data, const common::Specialization specialization)
{
    return std::make_unique<Doctor>(personal_data, specialization);
}

} // namespace doctor
} // namespace staff
} // namespace clinic
