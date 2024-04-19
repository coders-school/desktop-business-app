#pragma once

#include "../visit/treatment.hpp"
#include "../visit/visit.hpp"
#include "../warehouse/warehouse.hpp"
#include <memory>
#include <vector>

class Room
{
    unsigned room_id_;
    std::vector<Treatment> treatments_;
    bool avalaible_{true};
    std::shared_ptr<Warehouse> warehouse_;
    std::vector<std::shared_ptr<Visit>> visits_;

    Room(const unsigned& room_id, const std::vector<Treatment>& treatments, std::shared_ptr<Warehouse>& warehouse);

  public:
    void addVisit(const std::shared_ptr<Visit>& visit);
    bool isRoomFree(const unsigned& timestamp);
    unsigned getRoomNumber() const;
    std::vector<Treatment> getTreatments() const;
    std::shared_ptr<Warehouse> getWarehouse() const;
    void setRoomAvalaibility(bool avalaible);
    void setWarehouse(std::shared_ptr<Warehouse>& warehouse);

    static void createRoom(const unsigned& room_id, const std::vector<Treatment>& treatments,
                           std::shared_ptr<Warehouse>& warehouse);
};
