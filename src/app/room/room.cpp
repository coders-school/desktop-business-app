#include "room.hpp"
#include "clinic_facade.hpp"
#include "treatment.hpp"
#include "visit.hpp"
#include "warehouse.hpp"

Room::Room(const unsigned room_id, const std::vector<Treatment>& treatments,
           const std::shared_ptr<Warehouse>& warehouse)
    : room_id_{room_id}, treatments_{treatments}, warehouse_{warehouse}, visits_{}
{
}
Room::Room(const unsigned room_id, const std::shared_ptr<Warehouse>& warehouse)
    : room_id_{room_id}, warehouse_{warehouse}, visits_{}
{
}

bool Room::isVisitAssigned(const std::shared_ptr<Visit>& visit)
{
    return std::find(visits_.begin(), visits_.end(), visit) == visits_.end() ? false : true;
}

void Room::addVisit(const std::shared_ptr<Visit>& visit)
{
    if (!isVisitAssigned(visit))
    {
        visits_.emplace_back(visit);
        visit->setRoom(shared_from_this());
    }
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

void Room::createRoom(const unsigned room_id, const std::vector<Treatment>& treatments,
                      const std::shared_ptr<Warehouse>& warehouse)
{
    Room room{room_id, treatments, warehouse};
    Clinic::appendRoom(std::make_shared<Room>(room));
}

void Room::createRoom(const unsigned room_id, const std::shared_ptr<Warehouse>& warehouse)
{
    Clinic::appendRoom(std::make_shared<Room>(Room{room_id, warehouse}));
}

std::vector<std::shared_ptr<Visit>> Room::getVisits()
{
    return visits_;
}
