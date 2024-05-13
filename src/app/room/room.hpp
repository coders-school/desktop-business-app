#pragma once

#include <chrono>
#include <memory>
#include <vector>

enum class Treatment : uint32_t;
class Visit;
class Warehouse;
class Connector;

class Room : public std::enable_shared_from_this<Room>
{
    unsigned room_id_;
    std::vector<Treatment> treatments_;
    bool available_{true};
    std::shared_ptr<Warehouse> warehouse_;
    std::vector<std::shared_ptr<Visit>> visits_;
    std::vector<std::shared_ptr<Connector>> connectors_;

    Room(const unsigned room_id, const std::vector<Treatment>& treatments, const std::shared_ptr<Warehouse>& warehouse);
    bool isVisitAssigned(const std::shared_ptr<Visit>& visit);

  public:
    void addVisit(const std::shared_ptr<Visit>& visit);
    void addConnector(const std::shared_ptr<Connector>& connector);
    bool isRoomFree(const std::chrono::hh_mm_ss<std::chrono::seconds>& day_time) const;
    unsigned getRoomNumber() const;
    std::vector<Treatment> getTreatments() const;
    std::shared_ptr<Warehouse> getWarehouse() const;
    void setRoomAvailability(bool available);

    static void createRoom(const unsigned room_id, const std::vector<Treatment>& treatments,
                           const std::shared_ptr<Warehouse>& warehouse);
};
