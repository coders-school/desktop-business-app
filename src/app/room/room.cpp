#include "room.hpp"
#include "clinic_facade.hpp"
#include "connector.hpp"
#include "treatment.hpp"
#include "visit.hpp"
#include "warehouse.hpp"

Room::Room(const unsigned room_id, const std::vector<Treatment>& treatments,
           const std::shared_ptr<Warehouse>& warehouse)
    : room_id_{room_id}, treatments_{treatments}, warehouse_{warehouse}, visits_{}
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

void Room::addConnector(const std::shared_ptr<Connector>& connector)
{
    connectors_.emplace_back(connector);
}

bool Room::isRoomFree(const std::chrono::hh_mm_ss<std::chrono::seconds>& day_time) const
{
    std::ignore = day_time;
    // search connectors for room and compare if day_time is between start and end time
    return available_;
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

void Room::setRoomAvailability(bool available)
{
    available_ = available;
}

void Room::createRoom(const unsigned room_id, const std::vector<Treatment>& treatments,
                      const std::shared_ptr<Warehouse>& warehouse)
{
    Room room{room_id, treatments, warehouse};
    Clinic::appendRoom(std::make_shared<Room>(room));
}
