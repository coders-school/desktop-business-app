#pragma once
#include "treatment.hpp"
#include "warehouse.hpp"
#include <memory>
#include <vector>

class Room
{
    uint roomNumber_;
    std::vector<Treatment> treatments_;
    bool avalaible_{true};
    std::shared_ptr<Warehouse> ptrToWarehouse_;

  public:
    Room() = delete;
    Room(const uint roomNumber, const std::vector<Treatment>& treatments, std::shared_ptr<Warehouse>& ptrToWarehouse);

    // bool isRoomFree(timeInterval); TODO: write this function
    uint getRoomNumber() const;
    std::vector<Treatment> getTreatments() const;
    std::shared_ptr<Warehouse> getWarehouse() const;
    void setRoomAvalaibility(bool avalaible);
    void setWarehouse(std::shared_ptr<Warehouse>& ptrToWarehouse);
};
