#pragma once

#include "iRoom.hpp"

#include <memory>

namespace warehouse
{
class Warehouse;
}

namespace clinic
{
namespace room
{

class Room : public iRoom
{
  public:
    Room(const std::uint8_t room_number, std::shared_ptr<warehouse::Warehouse> warehouse = nullptr);

    std::uint8_t getNumber() const override;
    void updateUsedProducts() override;

  private:
    std::uint8_t room_number_;
    std::shared_ptr<warehouse::Warehouse> warehouse_;
};

} // namespace room
} // namespace clinic
