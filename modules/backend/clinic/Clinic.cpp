#include "Clinic.hpp"

#include "room/iRoom.hpp"
#include "staff/Staff.hpp"

namespace clinic
{

Clinic::Clinic(std::unique_ptr<staff::Staff> staff, std::vector<std::unique_ptr<room::iRoom>> rooms)
    : staff_{std::move(staff)}, rooms_{std::move(rooms)}
{
}

} // namespace clinic
