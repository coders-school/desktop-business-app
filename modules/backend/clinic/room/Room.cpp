#include "Room.hpp"

namespace clinic
{
namespace room
{

std::uint8_t Room::getNumber() const
{
    return room_number_;
}

void Room::updateUsedProducts()
{
    // TODO: This method should update the used products in the warehouse
    // based on the products used in the room during visit
    // 1. update argument list if necessary
    // 2. define how the process of updating should look like
}

} // namespace room
} // namespace clinic
