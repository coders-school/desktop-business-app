#include "room.hpp"

Room::Room(const uint roomNumber, const std::vector<Treatment> treatments, Warehouse& refToWarehouse)
    : roomNumber_{roomNumber}, treatments_{treatments}, refToWarehouse_{refToWarehouse}
{
}

uint Room::getRoomNumber()
{
    return roomNumber_;
}

void Room::setRoomAvalaibility(bool avalaibility)
{
    avalaibility_ = avalaibility;
}

std::vector<Treatment> Room::getTreatments()
{
    return treatments_;
}
