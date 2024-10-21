#include "ReceptionistFactory.hpp"

namespace clinic
{
namespace staff
{
namespace receptionist
{

ReceptionistPtr createReceptionist(const common::PersonalData& personal_data)
{
    return std::make_unique<Receptionist>(personal_data);
}

} // namespace receptionist
} // namespace staff
} // namespace clinic