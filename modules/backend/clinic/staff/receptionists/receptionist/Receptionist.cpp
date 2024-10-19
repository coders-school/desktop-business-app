#include "Receptionist.hpp"

namespace clinic
{
namespace staff
{
namespace receptionist
{

Receptionist::Receptionist(const common::PersonalData& personal_data)
    : personal_data_{personal_data}
{
}

common::PersonalData Receptionist::GetPersonalData() const
{
    return personal_data_;
}

} // namespace receptionist
} // namespace staff
} // namespace clinic