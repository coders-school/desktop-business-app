#include "room.hpp"

Room::Room(const uint roomNumber, const std::vector<Treatment> treatments, std::shared_ptr<Warehouse>& ptrToWarehouse)
    : roomNumber_{roomNumber}, treatments_{treatments}, ptrToWarehouse_{ptrToWarehouse}
{
}

uint Room::getRoomNumber() const
{
    return roomNumber_;
}

std::vector<Treatment> Room::getTreatments() const
{
    return treatments_;
}

std::shared_ptr<Warehouse> Room::getWarehouse() const
{
    return ptrToWarehouse_;
}

void Room::setRoomAvalaibility(bool avalaibility)
{
    avalaibility_ = avalaibility;
}

void Room::setWarehouse(std::shared_ptr<Warehouse> ptrToWarehouse)
{
    ptrToWarehouse_ = ptrToWarehouse;
}
