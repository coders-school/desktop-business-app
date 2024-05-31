#pragma once

#include "modules/backend/clinic/staff/room/iRoom.hpp"
#include "modules/backend/warehouse/Warehouse.hpp"
#include <memory>

class Room : public iRoom
{
    std::uint8_t room_number_;
    std::shared_ptr<Warehouse> warehouse_;

  public:
    Room(const std::uint8_t room_number, std::shared_ptr<Warehouse> warehouse = nullptr)
        : room_number_{room_number}, warehouse_{warehouse}
    {
    }

    std::uint8_t getNumber() const override;
    void updateUsedProducts() override;
};