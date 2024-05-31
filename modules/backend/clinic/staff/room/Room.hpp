#pragma once

#include <cstdint>
#include "modules/backend/clinic/staff/room/iRoom.hpp"

class Room : public iRoom
{
  uint8_t room_number_;

  public:
    Room(const uint8_t room_number) : room_number_{room_number}
    {
    }
};