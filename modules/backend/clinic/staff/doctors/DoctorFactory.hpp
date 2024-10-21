#pragma once

#include "Doctor.hpp"

namespace clinic
{
namespace staff
{
namespace doctor
{

DoctorPtr createDoctor(const common::PersonalData& personal_data, const common::Specialization specialization);

}
} // namespace staff
} // namespace clinic
