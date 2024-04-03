#include "room.hpp"

Room::Room(const uint roomNumber, const std::vector<Treatment> treatments, Warehouse& refToWarehouse)
    : roomNumber_{roomNumber}, treatments_{treatments}, refToWarehouse_{refToWarehouse}
{
}

uint Room::getRoomNumber() const
{
    return roomNumber_;
}

void Room::setRoomAvalaibility(bool avalaibility)
{
    avalaibility_ = avalaibility;
}

std::vector<Treatment> Room::getTreatments() const
{
    return treatments_;
}
