#pragma once
#include "treatment.hpp"
#include "warehouse.hpp"
#include <memory>
#include <vector>

class Room
{
    unsigned room_id_;
    std::vector<Treatment> treatments_;
    bool avalaible_{true};
    std::shared_ptr<Warehouse> warehouse_;

  public:
    Room() = delete;
    Room(const unsigned room_id, const std::vector<Treatment>& treatments, std::shared_ptr<Warehouse>& warehouse);

    unsigned getRoomNumber() const;
    std::vector<Treatment> getTreatments() const;
    std::shared_ptr<Warehouse> getWarehouse() const;
    void setRoomAvalaibility(bool avalaible);
    void setWarehouse(std::shared_ptr<Warehouse>& warehouse);
};
