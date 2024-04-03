#pragma once
#include "treatment.hpp"
#include "warehouse.hpp"
#include <utility>
#include <vector>

class Room
{
    uint roomNumber_;
    std::vector<Treatment> treatments_;
    bool avalaibility_{true};
    Warehouse& refToWarehouse_;

  public:
    Room() = delete;
    Room(const uint roomNumber, const std::vector<Treatment> treatments, Warehouse& refToWarehouse);

    uint getRoomNumber() const;
    // bool isRoomFree(timeInterval); TODO: write this function
    void setRoomAvalaibility(bool avalaibility);
    std::vector<Treatment> getTreatments() const;
};
