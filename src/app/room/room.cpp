#include "room.hpp"
#include "clinic_facade.hpp"

Room::Room(const unsigned& room_id, const std::vector<Treatment>& treatments, std::shared_ptr<Warehouse>& warehouse)
    : room_id_{room_id}, treatments_{treatments}, warehouse_{warehouse}, visits_{}
{
}

void Room::addVisit(const std::shared_ptr<Visit>& visit)
{
    visits_.emplace_back(visit);
}

bool Room::isRoomFree(const unsigned& timestamp)
{
    // TODO When Calendar will be available adjust accordingly
    std::ignore = timestamp;
    return false;
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

void Room::createRoom(const unsigned& room_id, const std::vector<Treatment>& treatments,
                      std::shared_ptr<Warehouse>& warehouse)
{
    Room room{room_id, treatments, warehouse};
    Clinic::appendRoom(std::make_shared<Room>(room));
}
