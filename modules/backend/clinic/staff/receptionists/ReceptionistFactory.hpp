#pragma once

#include "Receptionist.hpp"

namespace clinic
{
namespace staff
{
namespace receptionist
{

ReceptionistPtr createReceptionist(const common::PersonalData& personal_data);

} // namespace receptionist
} // namespace staff
} // namespace clinic