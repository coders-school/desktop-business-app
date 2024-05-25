#pragma once


class Room : public iRoom
{
    std::uint8_t room_number_;

  public:
    Room(const std::uint8_t room_number) : room_number_{room_number}
    {
    }
};