#include "room.hpp"

<<<<<<< HEAD Room::Room(const uint roomNumber, const std::vector<Treatment>& treatments,
             std::shared_ptr<Warehouse>& ptrToWarehouse)
    : roomNumber_{roomNumber}, treatments_{treatments}, ptrToWarehouse_{ptrToWarehouse}
{
}

uint Room::getRoomNumber() const
=======
    Room::Room(const uint roomNumber, const std::vector<Treatment> treatments, Warehouse& refToWarehouse)
    : roomNumber_{roomNumber}, treatments_{treatments}, refToWarehouse_{refToWarehouse}
{
}

uint Room::getRoomNumber()
>>>>>>> d349a39 (Update README.md (#66))
{
    return roomNumber_;
}

<<<<<<< HEAD
std::vector<Treatment> Room::getTreatments() const
{
    return treatments_;
}

std::shared_ptr<Warehouse> Room::getWarehouse() const
{
    return ptrToWarehouse_;
}

void Room::setRoomAvalaibility(bool avalaible)
{
    avalaible_ = avalaible;
}

void Room::setWarehouse(std::shared_ptr<Warehouse>& ptrToWarehouse)
{
    ptrToWarehouse_ = ptrToWarehouse;
}
=======
void Room::setRoomAvalaibility(bool avalaibility)
{
    avalaibility_ = avalaibility;
}

std::vector<Treatment> Room::getTreatments()
{
    return treatments_;
}
>>>>>>> d349a39 (Update README.md (#66))
