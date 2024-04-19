#include "room.hpp"

Room::Room(const unsigned room_id, const std::vector<Treatment>& treatments, std::shared_ptr<Warehouse>& warehouse)
    : room_id_{room_id}, treatments_{treatments}, warehouse_{warehouse}
{
}

unsigned Room::getRoomNumber() const

{
    return room_id_;
}

std::vector<Treatment> Room::getTreatments() const
{
    return treatments_;
}

std::shared_ptr<Warehouse> Room::getWarehouse() const
{
    return warehouse_;
}

void Room::setRoomAvalaibility(bool avalaible)
{
    avalaible_ = avalaible;
}

void Room::setWarehouse(std::shared_ptr<Warehouse>& warehouse)
{
    warehouse_ = warehouse;
}
