#pragma once

#include <memory>
#include <vector>

enum class Treatment : uint32_t;
class Visit;
class Warehouse;

class Room : public std::enable_shared_from_this<Room>
{
    unsigned room_id_;
    std::vector<Treatment> treatments_;
    bool avalaible_{true};
    std::shared_ptr<Warehouse> warehouse_;
    std::vector<std::shared_ptr<Visit>> visits_;

    Room(const unsigned room_id, const std::vector<Treatment>& treatments, const std::shared_ptr<Warehouse>& warehouse);
    Room(const unsigned room_id, const std::shared_ptr<Warehouse>& warehouse);
    bool isVisitFound(const std::shared_ptr<Visit>& visit);

  public:
    void addVisit(const std::shared_ptr<Visit>& visit);
    void removeVisit(const std::shared_ptr<Visit>& visit);
    bool isRoomFree(const unsigned& timestamp);
    unsigned getRoomNumber() const;
    std::vector<Treatment> getTreatments() const;
    std::shared_ptr<Warehouse> getWarehouse() const;
    void setRoomAvalaibility(bool avalaible);
    std::vector<std::shared_ptr<Visit>> getVisits();

    static void createRoom(const unsigned room_id, const std::vector<Treatment>& treatments,
                           const std::shared_ptr<Warehouse>& warehouse);
    static void createRoom(const unsigned room_id, const std::shared_ptr<Warehouse>& warehouse);
};
